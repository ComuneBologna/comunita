<?php
/**
 * @file
 * comunita_article_ct.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function comunita_article_ct_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function comunita_article_ct_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Contenuto'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titolo'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
