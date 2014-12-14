<?php
/**
 * @file
 * comunita_beni_comuni_ct.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function comunita_beni_comuni_ct_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_descrizione|node|bene_comune|form';
  $field_group->group_name = 'group_descrizione';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bene_comune';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Descrizione',
    'weight' => '0',
    'children' => array(
      0 => 'field_tipologia',
      1 => 'field_fotografia',
      2 => 'field_info_geo',
      3 => 'field_geo',
      4 => 'body',
      5 => 'field_motivazione_bene',
      6 => 'field_link_a_risorse_online_di_i',
      7 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-descrizione field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_descrizione|node|bene_comune|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stato|node|bene_comune|form';
  $field_group->group_name = 'group_stato';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bene_comune';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Stato',
    'weight' => '1',
    'children' => array(
      0 => 'field_stato_bene',
      1 => 'field_progetto_collegato',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-stato field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_stato|node|bene_comune|form'] = $field_group;

  return $export;
}
