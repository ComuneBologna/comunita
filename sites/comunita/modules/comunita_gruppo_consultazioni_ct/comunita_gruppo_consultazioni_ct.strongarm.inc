<?php
/**
 * @file
 * comunita_gruppo_consultazioni_ct.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function comunita_gruppo_consultazioni_ct_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_gruppo_di_consultazioni';
  $strongarm->value = 0;
  $export['comment_anonymous_gruppo_di_consultazioni'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_gruppo_di_consultazioni';
  $strongarm->value = 1;
  $export['comment_default_mode_gruppo_di_consultazioni'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_gruppo_di_consultazioni';
  $strongarm->value = '50';
  $export['comment_default_per_page_gruppo_di_consultazioni'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_gruppo_di_consultazioni';
  $strongarm->value = 1;
  $export['comment_form_location_gruppo_di_consultazioni'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_gruppo_di_consultazioni';
  $strongarm->value = '1';
  $export['comment_gruppo_di_consultazioni'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_gruppo_di_consultazioni';
  $strongarm->value = '1';
  $export['comment_preview_gruppo_di_consultazioni'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_gruppo_di_consultazioni';
  $strongarm->value = 1;
  $export['comment_subject_field_gruppo_di_consultazioni'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__gruppo_di_consultazioni';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'elenco_profili' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'workflow_tab' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '6',
        ),
        'path' => array(
          'weight' => '2',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__gruppo_di_consultazioni'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_gruppo_di_consultazioni';
  $strongarm->value = '0';
  $export['language_content_type_gruppo_di_consultazioni'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_gruppo_di_consultazioni';
  $strongarm->value = array();
  $export['menu_options_gruppo_di_consultazioni'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_gruppo_di_consultazioni';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_gruppo_di_consultazioni'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_gruppo_di_consultazioni';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_gruppo_di_consultazioni'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_gruppo_di_consultazioni';
  $strongarm->value = '0';
  $export['node_preview_gruppo_di_consultazioni'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_gruppo_di_consultazioni';
  $strongarm->value = 0;
  $export['node_submitted_gruppo_di_consultazioni'] = $strongarm;

  return $export;
}
