<?php
/**
 * @file
 * comunita_flags.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function comunita_flags_flag_default_flags() {
  $flags = array();
  // Exported flag: "Segui".
  $flags['segui'] = array(
    'entity_type' => 'node',
    'title' => 'Segui',
    'global' => 0,
    'types' => array(
      0 => 'organizzazione',
      1 => 'progetto',
    ),
    'flag_short' => 'Segui',
    'flag_long' => 'Segui [node:title]',
    'flag_message' => 'Ora segui [node:title]',
    'unflag_short' => 'Non seguire',
    'unflag_long' => 'Non seguire più [node:title]',
    'unflag_message' => 'Hai smesso di seguire [node:title]',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => 'others',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'comunita_flags',
    'locked' => array(
      0 => 'name',
    ),
  );
  // Exported flag: "Segui Utente".
  $flags['segui_utente'] = array(
    'entity_type' => 'user',
    'title' => 'Segui Utente',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Segui',
    'flag_long' => 'Segui [user:field_nome] [user:field_cognome]',
    'flag_message' => 'Ora segui  [user:field_nome] [user:field_cognome]',
    'unflag_short' => 'Non seguire',
    'unflag_long' => 'Non seguire più [user:field_nome] [user:field_cognome]',
    'unflag_message' => 'Hai smesso di seguire [user:field_nome] [user:field_cognome]',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'heartbeat_user' => 'heartbeat_user',
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_profile' => 1,
    'access_uid' => 'others',
    'api_version' => 3,
    'module' => 'comunita_flags',
    'locked' => array(
      0 => 'name',
    ),
  );
  // Exported flag: "Voto".
  $flags['voto'] = array(
    'entity_type' => 'node',
    'title' => 'Voto',
    'global' => 0,
    'types' => array(
      0 => 'proposta',
    ),
    'flag_short' => '<span class="glyphicon glyphicon-heart"></span> Vota (+1)',
    'flag_long' => 'Vota questa proposta',
    'flag_message' => 'Hai votato!',
    'unflag_short' => 'Cancella il voto (-1)',
    'unflag_long' => 'Cancella il tuo voto alla proposta',
    'unflag_message' => 'Hai cancellato il tuo voto',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'elenco_profili' => 0,
      'token' => 0,
      'workflow_tab' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => 'others',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'comunita_flags',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}
