<?php


/**
 * Form for editing an entire menu tree at once.
 *
 * Shows for one menu the menu items accessible to the current user and
 * relevant operations.
 */
function menu_editor_overview_form($form, &$form_state, $menu) {
  global $menu_admin;
  $form['#attached']['css'] = array(drupal_get_path('module', 'menu') . '/menu.css');
  $sql = "
    SELECT m.load_functions, m.to_arg_functions, m.access_callback, m.access_arguments, m.page_callback, m.page_arguments, m.delivery_callback, m.title, m.title_callback, m.title_arguments, m.type, m.description, ml.*
    FROM {menu_links} ml LEFT JOIN {menu_router} m ON m.path = ml.router_path
    WHERE ml.menu_name = :menu
    ORDER BY p1 ASC, p2 ASC, p3 ASC, p4 ASC, p5 ASC, p6 ASC, p7 ASC, p8 ASC, p9 ASC";
  $result = db_query($sql, array(':menu' => $menu['menu_name']), array('fetch' => PDO::FETCH_ASSOC));
  $links = array();
  foreach ($result as $item) {
    $links[] = $item;
  }
  $tree = menu_tree_data($links);
  $node_links = array();
  menu_tree_collect_node_links($tree, $node_links);
  // We indicate that a menu administrator is running the menu access check.
  $menu_admin = TRUE;
  menu_tree_check_access($tree, $node_links);
  $menu_admin = FALSE;

  $form = array('#tree' => TRUE);
  $form['#multilingual_menu'] = FALSE;
  $form['#translatable_nodes'] = FALSE;

  $max_root_weight = _menu_editor_overview_tree_form($form, $form_state, $tree);

  // default values for all new menu items..
  $default_values = array(
    'link_title' => '',
    'link_path' => '<front>',
    'description' => '',
    'hidden' => true,
    'expanded' => false,
    'weight' => 0,
    // 'mlid' => NULL,  // this is different for every single one
    'plid' => 0,
    'language' => LANGUAGE_NONE,
  );

  foreach (menu_editor_get_placeholders() as $placeholder_code => $placeholder_path) {
    // take the first placeholder as default link path instead of <front>
    $default_values['link_path'] = $placeholder_code;
    break;
  }


  for ($i=0; $i<8; ++$i) {
    // new menu item
    $default_values['mlid'] = 'new' . $i;
    $item_key = 'mlid-new'.$i;
    $form[$item_key] = _menu_editor_overview_tree_form_item('new'.$i, $default_values, $form['#multilingual_menu']);
    $form[$item_key]['weight']['#default_value'] = $max_root_weight + $i + 1;
    $form[$item_key]['#item'] = array();
    $form[$item_key]['#attributes'] = array('class' => 'menu-new');
    $form[$item_key]['drag']['#markup'] = t('New menu item');
  }

  $form['#menu'] =  $menu;
  if (element_children($form)) {
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save configuration'),
    );
  }
  else {
    $form['empty_menu'] = array('#value' => t('There are no menu items yet.'));
  }

  return $form;
}


/**
 * Recursive helper function for menu_overview_form().
 */
function _menu_editor_overview_tree_form(&$form, &$form_state, $tree) {
  $max_root_weight = 0;
  foreach ($tree as $data) {
    $title = '';
    $item = $data['link'];
    // Don't show callbacks; these have $item['hidden'] < 0.
    if ($item && $item['hidden'] >= 0) {
      $item_key = 'mlid-'. $item['mlid'];
      $weight = isset($form_state[$item_key]['weight']) ? $form_state[$item_key]['weight'] : $item['weight'];
      $plid = isset($form_state[$item_key]['plid']) ? $form_state[$item_key]['plid'] : $item['plid'];

      if (!$plid && $weight > $max_root_weight) {
        // this is a root level item
        $max_root_weight = $weight;
      }
      $path = $item['link_path'];
      if (!empty($item['options']['query'])) {
        if (is_array($item['options']['query'])) {
          $path .= '?'. drupal_http_build_query($item['options']['query']);
        }
        else {
          // Query could be a string, due to a malfunction in previous versions of this module.
          $path .= '?'. $item['options']['query'];
        }
      }
      if (isset($item['options']['fragment'])) {
        $path .= '#'. $item['options']['fragment'];
      }
      $default_values = array(
        'link_title' => $item['link_title'],
        'link_path' => $path,
        'description' => isset($item['options']['attributes']['title']) ? $item['options']['attributes']['title'] : '',
        'hidden'   => !$item['hidden'],
        'expanded' => $item['expanded'],
        'weight'   => $weight,
        'plid'     => $plid,
        'depth' => 1,
      );

      $form[$item_key] = _menu_editor_overview_tree_form_item($item['mlid'], $default_values, $form['#multilingual_menu']);

      $form[$item_key]['#item'] = $item;
      $form[$item_key]['#attributes'] = $item['hidden'] ? array('class' => 'menu-disabled') : array('class' => 'menu-enabled');
      $form[$item_key]['drag']['#markup'] = l($item['title'], $item['href'], $item['localized_options']) . ($item['hidden'] ? ' ('. t('disabled') .')' : '');

      // Include i18n support.
      if (module_exists('i18n_menu')) {
        $item['language'] = i18n_menu_item_get_language($item);
        $node_item = ($node = i18n_menu_item_get_node($item)) && i18n_menu_node_supported_type($node->type);
        if (!$node_item && i18n_menu_mode($item['menu_name'], I18N_MODE_TRANSLATE)) {
          $form[$item_key]['language'] = array('#title' => NULL) + i18n_element_language_select($item);
          $form['#multilingual_menu'] = TRUE;
          // If the term to be added will be a translation of a source term,
          // set the default value of the option list to the target language and
          // create a form element for storing the translation set of the source term.
          if (isset($_GET['translation']) && isset($_GET['target']) && ($source_item = menu_link_load($_GET['translation']))) {
            if (!empty($source_item['i18n_tsid'])) {
              $translation_set = i18n_translation_set_load($source_item['i18n_tsid']);
            }
            else {
              // Create object and stick the source information in the translation set.
              $translation_set = i18n_translation_set_build('menu_link')
                ->add_item($source_item);
            }
            $form[$item_key]['link_path']['#default_value'] = $source_item['link_path'];

            // Maybe we should disable the 'link_path' and 'parent' form elements?
            // $form['link_path']['#disabled'] = TRUE;
            // $form['parent']['#disabled'] = TRUE;

            $form[$item_key]['language']['#default_value'] = $_GET['target'];
            $form[$item_key]['language']['#disabled'] = TRUE;
          }
        }
        else {
          $form[$item_key]['language'] = array(
            '#type' => 'value',
            '#value' => $item['language'],
          );
        }
        // Aside from the usual conditions from i18n_menu_form_menu_edit_item_alter(), also
        // check if the return of the language name isn't "Undefined". This is caused when
        // choosing "Translate mode" to be "No multilingual options for menu items. Only the
        // menu will be translatable." but one of the menu items is a node which
        // is translatable.
        if ($node_item && i18n_langcode($item['language'])) {
          $form[$item_key]['lang_message'] = array(
            '#type' => 'markup',
            '#title' => t('Language'),
            '#markup' => i18n_language_name($item['language']),
          );

          $form['#translatable_nodes'] = TRUE;
        }
      }

      // Only items created by the menu module can be deleted.
      if ($item['module'] == 'menu' || $item['updated'] == 1) { 
        $form[$item_key]['delete'] = array(
          '#type' => 'checkbox',
          '#title' => t('delete'),
          '#default_value' => false,
        );
      }
    }

    // process child elements
    if ($data['below']) {
      _menu_editor_overview_tree_form($form, $form_data, $data['below']);
    }
  }
  return $max_root_weight;
}


function _menu_editor_overview_tree_form_item($item_mlid, $default_values, $multilingual_menu = FALSE) {

  foreach (menu_editor_get_placeholders() as $code => $path) {
    if (str_replace('@mlid', $item_mlid, $path) == $default_values['link_path']) {
      $default_values['link_path'] = $code;
    }
  }

  $element = array();
  $element['link_title'] = array(
    '#type' => 'textfield',
    '#size' => 25,
  );
  $element['link_path'] = array(
    '#type' => 'textfield',
    '#size' => 25,
  );
  $element['description'] = array(
    '#type' => 'textarea',
    '#cols' => 8,
    '#rows' => 1,
    '#resizable' => FALSE,
  );
  $element['hidden'] = array(
    '#type' => 'checkbox',
  );
  $element['expanded'] = array(
    '#type' => 'checkbox',
  );
  $element['weight'] = array(
    // The original form uses a select box for the weight.
    // We use a textfield instead, to save memory on server side
    // and to reduce page size.
    '#type' => 'textfield',
    '#size' => 4,
    '#element_validate' => array('_menu_editor_valid_weight'),
  );
  $element['mlid'] = array(
    '#type' => 'hidden',
    '#value' => $item_mlid,
  );
  $element['plid'] = array(
    '#type' => 'textfield',
    '#size' => 6,
  );
  // If this is a new menu item, simply provide i18n_menu select options.
  if (strpos($item_mlid, 'new') === 0 && $multilingual_menu) {
    $element['language'] = array('#title' => NULL) + i18n_element_language_select();
  }
  foreach ($default_values as $key => $value) {
    if (isset($element[$key])) {
      $element[$key]['#default_value'] = $value;
    }
  }
  return $element;
}


/**
 * Weight textfield validation function
 * Stolen from http://drupal.org/project/tiny_menu_editor
 * Big thanks to Dmitriy.trt
 */
function _menu_editor_valid_weight($element, &$form_state) {
  if ((isset($element['#value']) && $element['#value'] !== '') || !empty($element['#required'])) {
    if (!preg_match('/^\-?\d+$/', $element['#value'])) {
       form_error($element, t('Weight has to be an integer value.'));
    }
  }
}


function menu_editor_overview_form_validate($form, &$form_state) {
  $form_values = &$form_state['values'];

  // Check existing items.
  foreach (element_children($form) as $item_key) {
    // Check if these are menu items.
    if (strpos($item_key, 'mlid-') !== FALSE) {
      $element = &$form[$item_key];
      if (isset($element['link_path'])) {
        menu_editor_validate_item($element, $element['link_path']['#value'], $item_key . '][');
      }
    }
  }

  // allow new items to be dynamically added via javascript,
  // that have not been in the form originally.
  foreach ($form_state['input'] as $item_key => $item) {
    if (preg_match('/^mlid-new\d+$/', $item_key)) {
      if (menu_editor_overview_form_validate_new_item($item)) {
        $form_values[$item_key] = $item;
      }
    }
  }
}


/**
 * Validate form values for a menu link being added or edited.
 */
function menu_editor_validate_item(&$element, $link_path, $error_key_prefix) {
  $placeholders = menu_editor_get_placeholders();
  if (isset($placeholders[$link_path])) {
    // it would be hard to check access,
    // because we don't necessarily know the mlid.
    // Thus, we simply grant access for all placeholders.
    return;
  }

  if ($element['link_path']['#default_value'] == $link_path) {
    // link_path is the only field that we check,
    // and we don't complain about existing link paths.
    return;
  }
  $item = $element['#item'];
  $normal_path = drupal_get_normal_path($link_path);
  $item['link_path'] = $normal_path;

  if (!url_is_external($normal_path)) {

    $parsed_link = parse_url($normal_path);

    if (isset($parsed_link['query'])) {
      $item['options']['query'] = drupal_get_query_array($parsed_link['query']);
    }
    if (isset($parsed_link['fragment'])) {
      $item['options']['fragment'] = $parsed_link['fragment'];
    }
    $item['link_path'] = $parsed_link['path'];
  }
  if (!trim($item['link_path']) || !drupal_valid_path($item['link_path'])) {
    form_set_error($error_key_prefix . 'link_path', t("The path '@link_path' is either invalid or you do not have access to it.", array('@link_path' => $item['link_path'])));
  }
}


/**
 * validate a menu item that was dynamically added through javascript
 * 
 * @param unknown_type $item
 */
function menu_editor_overview_form_validate_new_item($item) {
  // TODO: add some sanity checks
  return true;
}


/**
 * Submit handler for the menu overview form.
 *
 * This function takes great care in saving parent items first, then items
 * underneath them. Saving items in the incorrect order can break the menu tree.
 *
 * @see menu_overview_form()
 */
function menu_editor_overview_form_submit($form, &$form_state) {

  // When dealing with saving menu items, the order in which these items are
  // saved is critical. If a changed child item is saved before its parent,
  // the child item could be saved with an invalid path past its immediate
  // parent. To prevent this, save items in the form in the same order they
  // are sent by $_POST, ensuring parents are saved first, then their children.
  // See http://drupal.org/node/181126#comment-632270
  $item_keys = array_flip(array_keys($form_state['input'])); // Get the $_POST order.
  $form_values = array_merge($item_keys, $form_state['values']); // Update our original form with the new order.

  $menu_name = $form['#menu']['menu_name'];

  $updated_items = array();
  $fields = array('expanded', 'weight', 'plid', 'link_title', 'link_path', 'description');

  foreach ($form_values as $item_key => $v) {
    if (isset($form[$item_key]['#item'])) {
      $element = $form[$item_key];
      if (!is_numeric($v['mlid'])) {
        // add new item
        unset($v['mlid']);
        if (!is_string($v['link_title']) || empty($v['link_title'])) {
          continue;
        }
        if (!is_string($v['link_path']) || empty($v['link_path'])) {
          continue;
        }
        $element['#item']['menu_name'] = $menu_name;
        // Set all fields in this menu item.
        foreach ($fields as $field) {
          // Check if field is set since some fields could not be NULL when 
          // doing menu_link_save().
          if (isset($v[$field])) {
            $element['#item'][$field] = $v[$field];
          }
        }
        $updated_items[$item_key] = $element['#item'];
      } else if (!empty($v['delete'])) {
        // delete existing item
        if (is_numeric($v['mlid'])) {
          menu_link_delete($v['mlid']);
        }
        continue;
      } else {
        // update existing item
        // Update any fields that have changed in this menu item.
        foreach ($fields as $field) {
          if ($v[$field] != $element[$field]['#default_value']) {
            $element['#item'][$field] = $v[$field];
            $updated_items[$item_key] = $element['#item'];
          }
        }
      }
      // Hidden is a special case, the value needs to be inverted.
      // Besides, while we operate with boolean, the database wants numeric 0/1.
      if ($v['hidden'] xor $element['hidden']['#default_value']) {
        $element['#item']['hidden'] = empty($v['hidden']) ? 1 : 0;
        $updated_items[$item_key] = $element['#item'];
      }
      // langcode is a special case as well
      if (!empty($form['#multilingual_menu'])) {
        $langcode = isset($element['language']['#default_value']) ? $element['language']['#default_value'] : $element['language']['#value'];
        if ($v['language'] != $langcode) {
          $element['#item']['language'] = $v['language'];
          $updated_items[$item_key] = $element['#item'];
        }
      }
      // description is a special case
      if (isset($updated_items[$item_key]['description'])) {
        $updated_items[$item_key]['options']['attributes']['title'] = $updated_items[$item_key]['description'];
      }
    }
  }

  // placeholders to change the link path
  $placeholders = menu_editor_get_placeholders();

  // Save all our changed items to the database.
  $errors = array();
  $mlids = array();

  foreach ($updated_items as $item_key => $item) {
    $item['customized'] = 1;

    // check the link path
    $link_path = &$item['link_path'];

    $link_path_placeholder = NULL;

    // placeholders
    if (isset($placeholders[$link_path])) {
      if (isset($item['mlid']) && is_numeric($item['mlid'])) {
        $link_path = str_replace('@mlid', $item['mlid'], $placeholders[$link_path]);
      }
      else {
        $link_path_placeholder = $placeholders[$link_path];
        // use a dummy link path,
        // until we know the correct mlid.
        $link_path = '<front>';
      }
    }

    // clean the link path
    if (isset($link_path)) {
      $link_path = drupal_get_normal_path($link_path);
      if (!url_is_external($link_path)) {
        $parsed_link = parse_url($link_path);

        if (isset($parsed_link['query'])) {
          $item['options']['query'] = drupal_get_query_array($parsed_link['query']);
        }
        else {
          unset($item['options']['query']);
        }

        if (isset($parsed_link['fragment'])) {
          $item['options']['fragment'] = $parsed_link['fragment'];
        }
        else {
          unset($item['options']['fragment']);
        }

        if ($link_path != $parsed_link['path']) {
          $link_path = $parsed_link['path'];
        }
      }
      if (!trim($link_path) || !drupal_valid_path($link_path)) {
        // invalid link path, discard this item
        continue;
      }
    }

    // drupal_set_message('<pre>' . print_r($item, true) . '</pre>');
    if (!empty($item['plid']) && !is_numeric($item['plid'])) {
      if (isset($mlids["mlid-$item[plid]"])) {
        $item['plid'] = $mlids["mlid-$item[plid]"];
      }
      else {
        unset($item['plid']);
      }
    }

    $mlid = menu_link_save($item);

    if (is_numeric($mlid)) {
      // remember as a plid for child items
      $mlids[$item_key] = $mlid;
      if (isset($link_path_placeholder)) {
        // overwrite the dummy link path
        $link_path = str_replace('@mlid', $item['mlid'], $link_path_placeholder);

        menu_link_save($item);
      }
    }
    else {
      $errors[] = $item_key;
    }
  }

  if (!empty($errors)) {
    drupal_set_message(t('There were errors saving the following menu links:<br/>' . implode('<br/>', $errors)), 'error');
  }
}





/**
 * Theme the menu overview form into a table.
 *
 * @ingroup themeable
 */
function theme_menu_editor_overview_form($variables) {
  $form = $variables['form'];
  drupal_add_css(drupal_get_path('module', 'menu_editor') .'/menu_editor.css');
  drupal_add_js(drupal_get_path('module', 'menu_editor') . '/menu_editor.js');
  global $language;
  $i18n_menu = $form['#multilingual_menu'] || $form['#translatable_nodes'];
  drupal_add_tabledrag('menu-overview', 'match', 'parent', 'menu-plid', 'menu-plid', 'menu-mlid', TRUE, MENU_MAX_DEPTH - 1);
  drupal_add_tabledrag('menu-overview', 'order', 'sibling', 'menu-weight');

  $header = array();
  $header[] = t('Menu item');
  $header[] = t('Title');
  $header[] = t('Path');
  $header[] = array('data' => t('Descr.', array(), array('context' => 'Abbr: "Description"')), 'class' => 'description');
  $header[] = array('data' => t('En.', array(), array('context' => 'Abbr: "Enabled"')), 'class' => 'checkbox');
  $header[] = array('data' => t('Exp.', array(), array('context' => 'Abbr: "Expanded"')), 'class' => 'checkbox');
  $header[] = t('Weight');
  if ($i18n_menu) {
    $header[] = t('Language');
  }
  $header[] = array('data'  => t('Delete'), 'class' => 'delete-checkbox');

  $rows = array();
  $items = array();

  foreach (element_children($form) as $item_key) {
    if (isset($form[$item_key]['hidden'])) {
      $element = &$form[$item_key];

      // Add special classes to be used for tabledrag.js.
      $element['plid']['#attributes']['class'] = array('menu-plid');
      $element['mlid']['#attributes']['class'] = array('menu-mlid');
      $element['weight']['#attributes']['class'] = array('menu-weight');

      // Change the parent field to a hidden. This allows any value but hides the field.
      $element['plid']['#type'] = 'hidden';

      // Adjust tab index to allow vertical tabbing
      foreach (array('link_title', 'link_path', 'description', 'hidden', 'expanded') as $i => $key) {
        $element[$key]['#attributes']['tabindex'] = $i+2;
      }
      $element['link_path']['#attributes']['tabindex'] = 2;

      $cells = array();

      $size = isset($element['#item']['depth']) ? $element['#item']['depth'] : 1;
      $cells['drag'] = array(
        'data' => theme('indentation', array('size' => $size - 1)) . drupal_render($element['drag']),
        'class' => 'drag',
      );
      $cells['link_title'] = array('data' => drupal_render($element['link_title']), 'class' => 'title-edit');
      $cells['link_path'] = array('data' => drupal_render($element['link_path']), 'class' => 'path-edit');
      $cells['description'] = array('data' => drupal_render($element['description']), 'class' => 'description');
      $cells['hidden'] = array('data' => drupal_render($element['hidden']), 'class' => 'checkbox');
      $cells['expanded'] = array('data' => drupal_render($element['expanded']), 'class' => 'checkbox');
      $cells['mlid'] = drupal_render($element['weight']) . drupal_render($element['plid']) . drupal_render($element['mlid']);
      if ($i18n_menu) {
        if (isset($element['lang_message'])) {
          $cells['language'] = array('data' => drupal_render($element['lang_message']));
        }
        else {
          $cells['language'] = array('data' => drupal_render($element['language']), 'class' => 'select');
        }
      }
      $cells['delete'] = array('data' => drupal_render($element['delete']), 'class' => 'delete-checkbox');

      $row = array_merge(array('data' => $cells), $element['#attributes']);
      $row['class'] = array('draggable');
      if ($i18n_menu) {
        $langcode = isset($element['language']['#default_value']) ? $element['language']['#default_value'] : $element['language']['#value'];
        $row['class'][] = ($langcode != LANGUAGE_NONE) ? 'langcode-'.$langcode : 'all-languages';
        $row['class'][]= ($langcode == $language->language) ? 'active-language' : '';
      }
      $rows[$item_key] = $row;
    }
  }
  $output = '';
  // allow other modules to change the table data.
  drupal_alter('menu_editor_overview_table', $header, $rows);
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'menu-overview')));
  $output .= drupal_render_children($form);
  return $output;
}

