<?php
/**
 * @file
 * comunita_progetto_ct.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function comunita_progetto_ct_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_descrizione|node|progetto|form';
  $field_group->group_name = 'group_descrizione';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'progetto';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Descrizione generale',
    'weight' => '1',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'field_tipologia_progetto',
      2 => 'field_tag_categorie',
      3 => 'field_descrizione_breve_progetto',
      4 => 'field_link_pagina_esterna',
      5 => 'field_area_tematica',
      6 => 'field_immagine_progetto',
      7 => 'field_dove_progetto',
      8 => 'field_geo',
      9 => 'field_stato',
      10 => 'field_stato_documento',
      11 => 'title',
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
  $export['group_descrizione|node|progetto|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rendiconto|node|progetto|form';
  $field_group->group_name = 'group_rendiconto';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'progetto';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Rendiconto',
    'weight' => '6',
    'children' => array(
      0 => 'field_obiettivi_indirizzi',
      1 => 'field_azioni_e_servizi_resi',
      2 => 'field_risultati_raggiunti',
      3 => 'field_risorse_disponibili',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-rendiconto field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_rendiconto|node|progetto|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_richiedi_supporto|node|progetto|form';
  $field_group->group_name = 'group_richiedi_supporto';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'progetto';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Richiedi supporto',
    'weight' => '3',
    'children' => array(
      0 => 'field_supporto_capacita',
      1 => 'field_supporto_strumenti',
      2 => 'field_supporto_materiali',
      3 => 'field_supporto_spazi',
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
  $export['group_richiedi_supporto|node|progetto|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_soggetti|node|progetto|form';
  $field_group->group_name = 'group_soggetti';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'progetto';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Soggetti',
    'weight' => '0',
    'children' => array(
      0 => 'og_group_ref',
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
  $export['group_soggetti|node|progetto|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_specifica|node|progetto|form';
  $field_group->group_name = 'group_specifica';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'progetto';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Descrizione specifica',
    'weight' => '2',
    'children' => array(
      0 => 'field_bene_intervento',
      1 => 'field_obiettivo_piano',
      2 => 'field_interesse_collettivo',
      3 => 'field_strumento_finanziamento',
      4 => 'field_allegati_obiettivo',
      5 => 'field_allegati_bene_oggetto',
      6 => 'field_allegati_risorse_impiegate',
      7 => 'field_patrocinio',
      8 => 'field_bene_comune_collegato',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-specifica field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_specifica|node|progetto|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tempi|node|progetto|form';
  $field_group->group_name = 'group_tempi';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'progetto';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tempistiche',
    'weight' => '5',
    'children' => array(
      0 => 'field_data_avvio',
      1 => 'field_momento_rendicontazione',
      2 => 'field_data_chiusura',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tempi field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tempi|node|progetto|form'] = $field_group;

  return $export;
}
