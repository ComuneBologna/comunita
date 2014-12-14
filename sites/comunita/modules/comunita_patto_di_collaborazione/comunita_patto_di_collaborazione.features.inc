<?php
/**
 * @file
 * comunita_patto_di_collaborazione.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function comunita_patto_di_collaborazione_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function comunita_patto_di_collaborazione_node_info() {
  $items = array(
    'patto_di_collaborazione' => array(
      'name' => t('Patto di collaborazione'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
