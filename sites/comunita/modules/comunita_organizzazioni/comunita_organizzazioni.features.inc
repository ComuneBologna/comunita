<?php
/**
 * @file
 * comunita_organizzazioni.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function comunita_organizzazioni_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function comunita_organizzazioni_node_info() {
  $items = array(
    'organizzazione' => array(
      'name' => t('Organizzazione'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Nome Organizzazione'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
