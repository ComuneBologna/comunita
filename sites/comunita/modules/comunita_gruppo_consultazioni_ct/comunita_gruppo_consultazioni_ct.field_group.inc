<?php
/**
 * @file
 * comunita_gruppo_consultazioni_ct.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function comunita_gruppo_consultazioni_ct_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contenuti|node|gruppo_di_consultazioni|form';
  $field_group->group_name = 'group_contenuti';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'gruppo_di_consultazioni';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contenuti gruppo',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_consultazioni_incluse',
      2 => 'title',
      3 => 'og_group_ref',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contenuti field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_contenuti|node|gruppo_di_consultazioni|form'] = $field_group;

  return $export;
}
