<?php
/**
 * @file
 * Admin functions.
 */
/**
 * Admin Settings form.
 */
function entity_rules_admin_form($form, &$form_state) {
  $entity_types = entity_get_info();
  foreach ($entity_types as $entity_type => $info) {
    if ($info['fieldable']) {
      $entity_options[$entity_type] = $info['label'];
    }
  }
  $form['entity_rules_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Enabled Types'),
    '#options' => $entity_options,
    '#default_value' => array_filter(variable_get('entity_rules_types', explode(',' , ENTITY_RULES_DEFAULT_TYPES))),
  );

  $form['entity_rules_permissions'] = array(
    '#type' => 'radios',
    '#title' => t('Permission Granularity'),
    '#options' => array(
      'none' => t('No defined permissions. Use bundle permissions.'),
      'single' => t('Single Permission.'),
      'entity_type' => t('Per Entity Type. Provide one permission per entity type.')
    ),
    '#default_value' => variable_get('entity_rules_permissions', ENTITY_RULES_DEFAULT_PERMISSIONS),

  );


  $form = system_settings_form($form);
  // Must clear settings after new settings have been saved
  $form['#submit'][] = 'entity_rules_clear_type_settings';
  return $form;
}

/**
 * Page callback to list Rules that can invoked by Entity Types
 */
function entity_rules_list($rule_type) {
  RulesPluginUI::$basePath = "admin/config/workflow/entity_rules/{$rule_type}";
  $options = array('show plugin' => FALSE);

  $content['enabled']['title']['#markup'] = '<h3>' . t("Enabled Entity $rule_type Rules") . '</h3>';

  $conditions = array(
    'plugin' => array('and', 'or', 'rule', 'rule set', 'action set'),
    'active' => TRUE,
    'tags' => array("entity_rules_$rule_type"),
  );
  $content['enabled']['rules'] = RulesPluginUI::overviewTable($conditions, $options);
  $content['enabled']['rules']['#empty'] = t("There are no active Entity $rule_type rules.");

  $content['disabled']['title']['#markup'] = '<h3>' . t("Disabled Entity $rule_type rules") . '</h3>';

  $conditions['active'] = FALSE;
  $content['disabled']['rules'] = RulesPluginUI::overviewTable($conditions, $options);
  $content['disabled']['rules']['#empty'] = t("There are no disabled Entity $rule_type rules.");

  return $content;
}

/**
 * Page call back to list Rules for a bundle.
 * @param $op
 *   Operation
 * @param $entity_type
 * @param $bundle
 * @return
 *   Drupal renderable array for page.
 */
function entity_rules_type_op_rules($op, $entity_type, $bundle) {
  $op_name = ucfirst($op);
  $bundle_name = _entity_rules_get_bundle_name($entity_type, $bundle);
  $output['add_new'] = drupal_get_form('entity_rules_new_bundle_rule_form', $entity_type, $bundle_name, $op);
  // @todo Bring up to standards
  $output['heading'] = array(
    '#type' => 'markup',
    '#markup' => "<h3>Current Rules</h3>",
  );
  $output['links'] = array(
    '#theme' => 'links',
    '#links' => array(
      array(
        'title' => "Add new $op_name Rule",
        'href' => "admin/config/workflow/entity_rules/$op/add",
      ),
      array(
        'title' => "Manage $op_name Rules",
        'href' => "admin/config/workflow/entity_rules/$op",
      ),
    ),
    '#attributes' => array('class' => 'action-links'),
  );

  $output['existing'] = drupal_get_form('entity_rules_bundle_rules_form', $entity_type, $bundle_name, $op);
  return $output;
}

/**
 * Form for setting Rule parmeters for a Bundle
 */
function entity_rules_bundle_rules_form($form, &$form_state, $entity_type, $bundle, $op) {
  $rule_settings = entity_rules_load_settings_for_op($entity_type, $bundle, $op, TRUE);
  $show_tokens = FALSE;
  $component_types = _entity_rules_get_component_types_for_op($op);
  if (empty($rule_settings)) {
    $form['empty'] = array(
      '#type' => 'markup',
      '#markup' => t('There are currently no active rules'),
    );
    return $form;
  }
  $form['entity_type'] = array(
    '#type' => 'value',
    '#value' => $entity_type,
  );
  $form['bundle'] = array(
    '#type' => 'value',
    '#value' => $bundle,
  );
  $form['op'] = array(
    '#type' => 'value',
    '#value' => $op,
  );
  $current_path = current_path();
  $length = strlen('entity-rules');
  $ends_with_rules = (substr($current_path, -$length) === 'entity-rules');
  if ($ends_with_rules) {
    $current_path .= '/create';
  }
  $form['settings']['#tree'] = TRUE;
  $rules = rules_config_load_multiple(array_keys($rule_settings));
  $weight = 0;
  foreach ($rule_settings as $id => $rule_setting) {
    $rule = $rule_setting->loaded_rules_config;
    if (isset($rule)) {
      $form_row = array();
      $form_row['name'] = array(
        '#type' => 'markup',
        '#markup' => $rule->label
          . ' ' . l(t('edit'), "admin/config/workflow/entity_rules/$op/manage/{$rule->id}"),
      );
      $form_row['id'] = array(
        '#type' => 'value',
        '#value' => $rule_setting->id,
      );
      $vars = _entity_rules_get_extra_vars($rule, $op);
      if (!empty($vars)) {
        foreach ($vars as $param_name => $param_info) {
          switch ($param_info['type']) {
            case 'text':
              $form_row['args'][$param_name] = array(
                '#type' => 'textarea',
                '#cols' => 15,
                '#rows' => 3,
                '#title' => $param_info['label'],
                '#default_value' => isset($rule_setting->args[$param_name]) ? $rule_setting->args[$param_name] : NULL,
              );
              break;
            default:
              $form_row['args'][$param_name] = array(
                '#type' => $param_info['type'] == 'boolean' ? 'checkbox' : 'textfield',
                '#title' => $param_info['label'],
                '#default_value' => isset($rule_setting->args[$param_name]) ? $rule_setting->args[$param_name] : NULL,
              );
          }
        }
      }
      if (is_subclass_of($rule, 'RulesConditionContainer')) {
        $form_row['false_msg'] = array(
          '#type' => 'text_format',
          '#cols' => 15,
          '#rows' => 3,
          '#title' => t('Rule returns false message'),
          '#default_value' => isset($rule_setting['false_msg']['value']) ? $rule_setting['false_msg']['value'] : NULL,
          '#format' => isset($rule_setting->false_msg['format']) ? $rule_setting->false_msg['format'] : NULL,
          '#description' => t('This message will be displayed if this Rule evalutes to FALSE.'),
        );
        $show_tokens = TRUE;
      }
      $remove_path = str_replace('/entity-rules', '/entity-rules-remove', $current_path) . "/$id";
      $form_row['remove_link'] = array(
        '#markup' => l(t('Remove'), $remove_path),
      );
      $form_row['weight'] = array(
        '#type' => 'weight',
        '#title' => t('Weight'),
        '#default_value' => $weight++,
        '#delta' => 10,
        '#title-display' => 'invisible',
      );
      $form['settings'][$id] = $form_row;
    }
  }
  if ($show_tokens && module_exists('token')) {
    $form['tokens'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array($entity_type),
      // The token types that have specific context. Can be multiple token types like 'term' and/or 'user'
      '#global_types' => TRUE,
      // A boolean TRUE or FALSE whether to include 'global' context tokens like [current-user:*] or [site:*]. Defaults to TRUE.
      '#click_insert' => TRUE,
      // A boolean whether to include the 'Click this token to insert in into the the focused textfield' JavaScript functionality. Defaults to TRUE.
      '#dialog' => TRUE,
    );
  }
  $form['#theme'] = 'entity_rules_bundle_rules_form';
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Changes'),
  );
  return $form;
}

/**
 * Form Submit callback for entity_rules_bundle_rules_form
 *
 * Sort Rules settings according to weight
 */
function entity_rules_bundle_rules_form_submit($form, &$form_state) {

  $values = $form_state['values'];
  foreach ($values['settings'] as $id => $entity_rule_setting) {

    entity_save('entity_rule_setting', (object) $entity_rule_setting);
  }
  drupal_set_message(t('Changes have been saved.'));
}

/**
 * Form callback that should current rules for a bundle and operation.
 *
 * @param $form
 * @param $form_state
 * @param $entity_type
 * @param $bundle
 * @param $op
 * @return
 *   Form array.
 */
function entity_rules_new_bundle_rule_form($form, &$form_state, $entity_type, $bundle, $op) {
  $rules = entity_rules_get_rule_options("entity_rules_$op", $entity_type);
  //$rules = array_diff_key($rules, $used_rules);
  if (empty($rules)) {
    return array();
  }
  $form['bundle'] = array(
    '#type' => 'value',
    '#value' => $bundle,
  );
  $form['entity_op'] = array(
    '#type' => 'value',
    '#value' => $op,
  );
  $form['entity_type'] = array(
    '#type' => 'value',
    '#value' => $entity_type,
  );

  $form['rule'] = array(
    '#type' => 'select',
    '#title' => t('Add Rule'),
    '#options' => $rules,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add'),
  );
  return $form;
}

/**
 * Form submit callback.
 *
 * Allows adding new rules to a bundle.
 * @param $form
 * @param $form_state
 */
function entity_rules_new_bundle_rule_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $new_entity_values = array(
    'entity_type' => $values['entity_type'],
    'bundle' => $values['bundle'],
    'op' => $values['entity_op'],
    'rules_config' => $values['rule'],
  );
  $entity_rule_setting = entity_create('entity_rule_setting', $new_entity_values);
  // @todo Should you be able to add the same Rule twice??
  entity_save('entity_rule_setting', $entity_rule_setting);
}

/**
 * Gets Rules options for a select form element.
 * @param $tag
 *   Rule tag to filter on.
 * @param $entity_type
 * @return
 *   Array of key value pairs.
 */
function entity_rules_get_rule_options($tag, $entity_type) {
  $conditions = array(
    //'plugin' => $plugin_types,
    'active' => TRUE,
  );
  $entities = entity_load('rules_config', FALSE, $conditions);
  ksort($entities);
  $rules = array();
  foreach ($entities as $entity) {
    if (in_array($tag, $entity->tags)) {
      $vars = $entity->componentVariables();
      if (isset($vars['entity'])) {
        if ($vars['entity']['type'] == 'entity' || $vars['entity']['type'] == $entity_type) {
          $rules[$entity->name] = $entity->label;
        }
      }

    }
  }
  return $rules;
}

/**
 * Removes rule from a bundle and operation.
 *
 * @param $op
 * @param $entity_type
 * @param $bundle
 * @param $rule_name
 */
function entity_rules_type_op_rules_remove($op, $entity_type, $bundle, $id) {
  entity_delete('entity_rule_setting', $id);
  drupal_set_message(t('This rule has been removed.'));
  $redirect = current_path();
  $redirect = str_replace('entity-rules-remove', 'entity-rules', $redirect);
  $redirect = str_replace("/$id", '', $redirect);
  drupal_goto($redirect);
}

/**
 * Theme callback for the entity_rules_bundle_rules_form form.
 *
 * The theme callback will format the $form data structure into a table and
 * add our tabledrag functionality.  (Note that drupal_add_tabledrag should be
 * called from the theme layer, and not from a form declaration.  This helps
 * keep template files clean and readable, and prevents tabledrag.js from
 * being added twice accidently.
 *
 * @return
 *   The rendered tabledrag form
 */
function theme_entity_rules_bundle_rules_form($variables) {
  $form = $variables['form'];
  $have_false_msg = $have_args = FALSE;


  // Initialize the variable which will store our table rows.
  $rows = array();
  $output = '';
  // Iterate over each element in our $form[$setting_var_name] array.
  foreach (element_children($form['settings']) as $id) {
    if (isset($form['settings'][$id]['false_msg'])) {
      $have_false_msg = TRUE;
    }
    if (isset($form['settings'][$id]['args'])) {
      $have_args = TRUE;
    }
  }
  foreach (element_children($form['settings']) as $id) {

    // Before we add our 'weight' column to the row, we need to give the
    // element a custom class so that it can be identified in the
    // drupal_add_tabledrag call.
    //
    // This could also have been done during the form declaration by adding
    // '#attributes' => array('class' => 'example-item-weight'),
    // directy to the 'weight' element in tabledrag_example_simple_form().
    $form['settings'][$id]['weight']['#attributes']['class'] = array('rule-item-weight');

    // We are now ready to add each element of our $form data to the $rows
    // array, so that they end up as individual table cells when rendered
    // in the final table.  We run each element through the drupal_render()
    // function to generate the final html markup for that element.
    $row = array(
      'data' => array(
        // Add our 'name' column.
        drupal_render($form['settings'][$id]['name']),
      ),
      'class' => array('draggable'),
    );
    if ($have_args) {
      $have_args = TRUE;
      // Add our 'description' column.
      $row['data'][] = drupal_render($form['settings'][$id]['args']);
    }
    if ($have_false_msg) {
      // Add our 'return message' column.
      $row['data'][] = drupal_render($form['settings'][$id]['false_msg']);
    }
    // Add our 'remove' column
    $row['data'][] = drupal_render($form['settings'][$id]['remove_link']);
    // Add our 'weight' column.
    $row['data'][] = drupal_render($form['settings'][$id]['weight']);

    $rows[] = $row;
  }

  // We now define the table header values.  Ensure that the 'header' count
  // matches the final column count for your table.
  $header = array(t('Name'));
  if ($have_args) {
    $header[] = t('Arguments');
  }
  if ($have_false_msg) {
    $header[] = t('Return Message');
  }

  $header[] = t('Remove');
  $header[] = t('Weight');

  // We also need to pass the drupal_add_tabledrag() function an id which will
  // be used to identify the <table> element containing our tabledrag form.
  // Because an element's 'id' should be unique on a page, make sure the value
  // you select is NOT the same as the form ID used in your form declaration.
  $table_id = 'items-table';

  // We can render our tabledrag table for output.
  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => $table_id),
  ));

  // And then render any remaining form elements (such as our submit button).
  $output .= drupal_render_children($form);

  if (!empty($table_id)) {
    drupal_add_tabledrag($table_id, 'order', 'sibling', 'rule-item-weight');
  }

  return $output;
}

/**
 * Page callback for list of Bundles to administer entity rules
 */
function entity_rules_entity_type_list() {
  $permissions = variable_get('entity_rules_permissions', ENTITY_RULES_DEFAULT_PERMISSIONS);
  $enabled_types = variable_get('entity_rules_types', explode(',', ENTITY_RULES_DEFAULT_TYPES));
  $entity_infos = entity_get_info();
  $entity_infos = array_intersect_key($entity_infos, array_flip($enabled_types));
  $output = '';
  foreach ($entity_infos as $entity_type => $info) {
    // Don't show entity type if user can't setting Rules
    if ($permissions == 'entity_type' && !user_access("administer $entity_type entity_rules settings")) {
      continue;
    }
    if ($info['fieldable']) {
      $rows = array();
      foreach ($info['bundles'] as $bundle_name => $bundle_info) {

        $rows[] = array(
          $bundle_info['label'],
          l(t('Administer Rules'), "admin/config/workflow/entity-rules-triggers/$entity_type/$bundle_name/create"),
        );
      }
      $output .= "<h2>{$info['label']}</h2>";
      $output .= theme('table',
        array(
          'header' => array(t('Bundle'), t('Manage')),
          'rows' => $rows,
        )
      );
    }
  }
  return $output;
}