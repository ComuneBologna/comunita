<?php
/**
 * @file
 * comunita_consultazione.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function comunita_consultazione_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_allegati|node|consultazione|form';
  $field_group->group_name = 'group_allegati';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultazione';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documenti allegati',
    'weight' => '1',
    'children' => array(
      0 => 'field_documenti_allegati',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_allegati|node|consultazione|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_discussione|node|consultazione|form';
  $field_group->group_name = 'group_discussione';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'consultazione';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Discussione',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'og_group_ref',
      2 => 'field_tags',
      3 => 'field_apertura_consultazione',
      4 => 'field_chiusura_consultazione',
      5 => 'field_area_tematica',
      6 => 'field_contenuto_interno_collegat',
      7 => 'field_geo',
      8 => 'field_image',
      9 => 'field_info_geo',
      10 => 'field_informazioni_di_contesto',
      11 => 'field_interesse_collettivo',
      12 => 'field_link_pagina_esterna',
      13 => 'field_modalit_di_impiego',
      14 => 'field_risultati_raggiunti',
      15 => 'field_tipologia_discussione',
      16 => 'title',
      17 => 'field_stato_consultazione',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-discussione field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_discussione|node|consultazione|form'] = $field_group;

  return $export;
}
