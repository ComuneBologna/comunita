<?php


/**
 * Page callback for node/add/%node_type/mlid/%menu_editor_mlid
 */
function me_node_creation_create_node($type, $menu_item) {
  global $user;

  drupal_set_title(t('Create @name', array('@name' => $type->name)), PASS_THROUGH);

  $node = (object)array(
    'uid' => $user->uid,
    'name' => (isset($user->name) ? $user->name : ''),
    'type' => $type->type,
    'language' => LANGUAGE_NONE,
    'me_node_creation_menu_item' => $menu_item,
  );

  module_load_include('pages.inc', 'node');

  $form = drupal_get_form($type->type . '_node_form', $node);

  return $form;
}


function _me_node_creation_form_alter(&$form, $node) {
  $menu_item = $node->me_node_creation_menu_item;

  unset($form['menu']);

  $mlid_text = $menu_item['mlid'];
  $mlid_path = "admin/structure/menu/item/$mlid_text/edit";
  if ($mlid_router_item = menu_get_item($mlid_path)) {
    if ($mlid_router_item['access']) {
      $mlid_text = l($mlid_text, $mlid_path);
    }
  }

  $txt = t('The created node will be associated with the chosen menu item (!mlid),<br/>with link title "@title"', array(
    '!mlid' => $mlid_text, 
    '@title' => $menu_item['link_title'],
  ));
  $txt = "<p>$txt</p>";

  $form['me_node_creation'] = array(
    '#type' => 'markup',
    '#markup' => $txt,
    '#weight' => -20,
  );

  $form['title']['#default_value'] = $menu_item['link_title'];
  // $form['#me_node_creation_menu_item'] = $menu_item;
  // $form['#submit'][] = 'me_node_creation_node_form_submit';
}
