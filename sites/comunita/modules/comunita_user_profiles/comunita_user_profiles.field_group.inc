<?php
/**
 * @file
 * comunita_user_profiles.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function comunita_user_profiles_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_altro|user|user|form';
  $field_group->group_name = 'group_altro';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Altro',
    'weight' => '2',
    'children' => array(
      0 => 'field_competenze',
      1 => 'field_risorse',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Altro',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_altro|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bisogni|user|user|form';
  $field_group->group_name = 'group_bisogni';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bisogni',
    'weight' => '2',
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
  $export['group_bisogni|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_carta_com|user|user|form';
  $field_group->group_name = 'group_carta_com';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'La Carta di Comunità',
    'weight' => '5',
    'children' => array(
      0 => 'field_carta_com',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-carta-com field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_carta_com|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contacts|user|user|form';
  $field_group->group_name = 'group_contacts';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contatti',
    'weight' => '0',
    'children' => array(
      0 => 'field_nome',
      1 => 'field_cognome',
      2 => 'field_sito_personale',
      3 => 'field_telefono',
      4 => 'field_blog_personale',
      5 => 'field_avatar',
      6 => 'field_ebologna_nickname',
      7 => 'account',
      8 => 'picture',
      9 => 'group_social',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Contatti',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contacts|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_presentazione|user|user|form';
  $field_group->group_name = 'group_presentazione';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Presentazione',
    'weight' => '1',
    'children' => array(
      0 => 'field_presentazione',
      1 => 'field_statement',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Presentazione',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_presentazione|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_privacy|user|user|form';
  $field_group->group_name = 'group_privacy';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Privacy',
    'weight' => '4',
    'children' => array(
      0 => 'field_mostra_email',
      1 => 'field_mostra_telefono',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-privacy field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_privacy|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_risorse|user|user|form';
  $field_group->group_name = 'group_risorse';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Risorse',
    'weight' => '3',
    'children' => array(
      0 => 'field_risorse_capacita',
      1 => 'field_risorse_strumenti',
      2 => 'field_risorse_materiali',
      3 => 'field_risorse_spazi',
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
  $export['group_risorse|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social|user|user|form';
  $field_group->group_name = 'group_social';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_contacts';
  $field_group->data = array(
    'label' => 'Social Network',
    'weight' => '10',
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
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_social|user|user|form'] = $field_group;

  return $export;
}
