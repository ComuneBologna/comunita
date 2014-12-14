<?php
/**
 * @file
 * comunita_gruppo_consultazioni_ct.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function comunita_gruppo_consultazioni_ct_ctools_plugin_api($module = NULL, $api = NULL) {
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
function comunita_gruppo_consultazioni_ct_node_info() {
  $items = array(
    'gruppo_di_consultazioni' => array(
      'name' => t('Gruppo di consultazioni'),
      'base' => 'node_content',
      'description' => t('Questo tipo può essere utilizzato per creare discussioni divise in più punti, ciascuno con proposte associate. I "punti" del gruppo sono singole consultazioni, che vengono qui raggruppate.'),
      'has_title' => '1',
      'title_label' => t('Titolo'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
