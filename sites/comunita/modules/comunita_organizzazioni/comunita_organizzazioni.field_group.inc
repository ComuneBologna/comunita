<?php
/**
 * @file
 * comunita_organizzazioni.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function comunita_organizzazioni_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bisogni|node|organizzazione|form';
  $field_group->group_name = 'group_bisogni';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organizzazione';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bisogni',
    'weight' => '2',
    'children' => array(
      0 => 'field_supporto_capacita',
      1 => 'field_supporto_materiali',
      2 => 'field_supporto_spazi',
      3 => 'field_supporto_strumenti',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-bisogni field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_bisogni|node|organizzazione|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contatti|node|organizzazione|form';
  $field_group->group_name = 'group_contatti';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organizzazione';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contatti',
    'weight' => '0',
    'children' => array(
      0 => 'field_org_picture',
      1 => 'field_sito_personale',
      2 => 'field_ragione_sociale',
      3 => 'field_sede_legale',
      4 => 'field_sede_operativa',
      5 => 'field_partita_iva_cf',
      6 => 'title',
      7 => 'group_social',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contatti field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_contatti|node|organizzazione|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_presentazione|node|organizzazione|form';
  $field_group->group_name = 'group_presentazione';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organizzazione';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Presentazione',
    'weight' => '1',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-presentazione field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_presentazione|node|organizzazione|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_risorse|node|organizzazione|form';
  $field_group->group_name = 'group_risorse';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organizzazione';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Risorse',
    'weight' => '3',
    'children' => array(
      0 => 'field_risorse_capacita',
      1 => 'field_risorse_materiali',
      2 => 'field_risorse_spazi',
      3 => 'field_risorse_strumenti',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-risorse field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_risorse|node|organizzazione|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social|node|organizzazione|form';
  $field_group->group_name = 'group_social';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organizzazione';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_contatti';
  $field_group->data = array(
    'label' => 'Social Network',
    'weight' => '8',
    'children' => array(
      0 => 'field_facebook',
      1 => 'field_google_',
      2 => 'field_linkedin',
      3 => 'field_twitter',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Social Network',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-social field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_social|node|organizzazione|form'] = $field_group;

  return $export;
}
