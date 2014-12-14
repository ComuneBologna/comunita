<?php
/**
 * @file
 * comunita_feedback.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function comunita_feedback_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contatti|entityform|feedback|form';
  $field_group->group_name = 'group_contatti';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'feedback';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contatti',
    'weight' => '0',
    'children' => array(
      0 => 'field_nome',
      1 => 'field_cognome',
      2 => 'field_email',
      3 => 'field_telefono',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Contatti',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
      ),
      'formatter' => '',
    ),
  );
  $export['group_contatti|entityform|feedback|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_partecipa|entityform|feedback|form';
  $field_group->group_name = 'group_partecipa';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'feedback';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Partecipa',
    'weight' => '2',
    'children' => array(
      0 => 'field_partecipa_workshop',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Partecipa',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-partecipa field-group-html-element',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
      ),
    ),
  );
  $export['group_partecipa|entityform|feedback|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_segnala|entityform|feedback|form';
  $field_group->group_name = 'group_segnala';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'feedback';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Segnala',
    'weight' => '1',
    'children' => array(
      0 => 'field_scegli_ambito_piace',
      1 => 'field_una_cosa_che_ti_piace',
      2 => 'field_scegli_ambito_migliorare',
      3 => 'field_una_cosa_migliorare',
      4 => 'field_scegli_ambito_manca',
      5 => 'field_una_cosa_che_manca',
      6 => 'field_scegli_ambito_malfunziona',
      7 => 'field_un_malfunzionamento',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Segnala',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
      ),
      'formatter' => '',
    ),
  );
  $export['group_segnala|entityform|feedback|form'] = $field_group;

  return $export;
}
