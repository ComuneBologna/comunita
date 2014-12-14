<?php
/**
 * @file
 * comunita_proposta.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function comunita_proposta_ctools_plugin_api($module = NULL, $api = NULL) {
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
function comunita_proposta_node_info() {
  $items = array(
    'proposta' => array(
      'name' => t('Proposta'),
      'base' => 'node_content',
      'description' => t('Le proposte in risposta alle consultazioni'),
      'has_title' => '1',
      'title_label' => t('Titolo'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
