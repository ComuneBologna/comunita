<?php
/**
 * @file
 * comunita_forms.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function comunita_forms_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'entityform-cura_beni_comuni-field_allegati_obiettivo'
  $field_instances['entityform-cura_beni_comuni-field_allegati_obiettivo'] = array(
    'bundle' => 'cura_beni_comuni',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_allegati_obiettivo',
    'label' => 'Allegati obiettivo e piano delle attività',
    'required' => 1,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'txt pdf doc docx odt xls xml csv',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'multiupload_filefield_widget',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_mfw',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'entityform-cura_beni_comuni-field_area_tematica'
  $field_instances['entityform-cura_beni_comuni-field_area_tematica'] = array(
    'bundle' => 'cura_beni_comuni',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_area_tematica',
    'label' => 'Area tematica',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'entityform-cura_beni_comuni-field_data_avvio'
  $field_instances['entityform-cura_beni_comuni-field_data_avvio'] = array(
    'bundle' => 'cura_beni_comuni',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_data_avvio',
    'label' => 'Data di avvio',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'entityform-cura_beni_comuni-field_data_chiusura'
  $field_instances['entityform-cura_beni_comuni-field_data_chiusura'] = array(
    'bundle' => 'cura_beni_comuni',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_data_chiusura',
    'label' => 'Data di conclusione prevista',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'entityform-cura_beni_comuni-field_descrizione_breve'
  $field_instances['entityform-cura_beni_comuni-field_descrizione_breve'] = array(
    'bundle' => 'cura_beni_comuni',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_descrizione_breve',
    'label' => 'Descrizione breve del progetto',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 200,
        'maxlength_js_enforce' => 1,
        'maxlength_js_label' => 'Contenuto limitato a @limit caratteri, rimanenti: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 1,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'entityform-cura_beni_comuni-field_image'
  $field_instances['entityform-cura_beni_comuni-field_image'] = array(
    'bundle' => 'cura_beni_comuni',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_image',
    'label' => 'Immagine',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '6 MB',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'entityform-cura_beni_comuni-field_info_geo'
  $field_instances['entityform-cura_beni_comuni-field_info_geo'] = array(
    'bundle' => 'cura_beni_comuni',
    'default_value' => array(
      0 => array(
        'element_key' => 'entityform|cura_beni_comuni|field_info_geo|und|0',
        'thoroughfare' => '',
        'premise' => '',
        'postal_code' => '',
        'locality' => '',
        'administrative_area' => '',
        'country' => 'IT',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_info_geo',
    'label' => 'Info per Georeferenziazione',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(
          'IT' => 'IT',
        ),
        'format_handlers' => array(
          'address' => 'address',
          'address-hide-country' => 'address-hide-country',
          'organisation' => 0,
          'name-oneline' => 0,
          'name-full' => 0,
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'entityform-cura_beni_comuni-field_link_pagina_esterna'
  $field_instances['entityform-cura_beni_comuni-field_link_pagina_esterna'] = array(
    'bundle' => 'cura_beni_comuni',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_link_pagina_esterna',
    'label' => 'Link pagina esterna',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'entityform-cura_beni_comuni-field_momento_rendicontazione'
  $field_instances['entityform-cura_beni_comuni-field_momento_rendicontazione'] = array(
    'bundle' => 'cura_beni_comuni',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_momento_rendicontazione',
    'label' => 'Eventuale verifica avanzamento / rendicontazione intermedia',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'entityform-cura_beni_comuni-field_motivazione_bene'
  $field_instances['entityform-cura_beni_comuni-field_motivazione_bene'] = array(
    'bundle' => 'cura_beni_comuni',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => ' Descrizione della ragione dell\'intervento per la collettività',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_motivazione_bene',
    'label' => 'Motivazione dell\'individuazione come Bene Comune',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 400,
        'maxlength_js_enforce' => 1,
        'maxlength_js_label' => 'Contenuto limitato a @limit caratteri, rimanenti: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 1,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'entityform-cura_beni_comuni-field_obiettivo_piano'
  $field_instances['entityform-cura_beni_comuni-field_obiettivo_piano'] = array(
    'bundle' => 'cura_beni_comuni',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Presentazione dell\'obiettivo progettuale e del piano delle attività distinte tra di loro',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_obiettivo_piano',
    'label' => 'Descrizione Obiettivo e Piano Attività',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 400,
        'maxlength_js_enforce' => 1,
        'maxlength_js_label' => 'Contenuto limitato a @limit caratteri, rimanenti: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'entityform-cura_beni_comuni-field_patrocinio'
  $field_instances['entityform-cura_beni_comuni-field_patrocinio'] = array(
    'bundle' => 'cura_beni_comuni',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_patrocinio',
    'label' => 'Patrocinio',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 1,
        'maxlength_js_label' => 'Contenuto limitato a @limit caratteri, rimanenti: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'entityform-cura_beni_comuni-field_strumento_finanziamento'
  $field_instances['entityform-cura_beni_comuni-field_strumento_finanziamento'] = array(
    'bundle' => 'cura_beni_comuni',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Nome del bando / avviso da cui si ricevono eventuali altre forme di sostegno o per cui si è fatta richiesta',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_strumento_finanziamento',
    'label' => 'Strumento di finanziamento',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 1,
        'maxlength_js_label' => 'Contenuto limitato a @limit caratteri, rimanenti: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'entityform-cura_beni_comuni-field_supporto_richiesto_bene'
  $field_instances['entityform-cura_beni_comuni-field_supporto_richiesto_bene'] = array(
    'bundle' => 'cura_beni_comuni',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'E\' possibile richiedere tutte le forme di supporto indicate nel foglio.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_supporto_richiesto_bene',
    'label' => 'Supporto richiesto',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'entityform-cura_beni_comuni-field_tipologia_bene_oggetto'
  $field_instances['entityform-cura_beni_comuni-field_tipologia_bene_oggetto'] = array(
    'bundle' => 'cura_beni_comuni',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tipologia_bene_oggetto',
    'label' => 'Tipologia del bene oggetto di intervento',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'entityform-cura_beni_comuni-field_tipologia_intervento'
  $field_instances['entityform-cura_beni_comuni-field_tipologia_intervento'] = array(
    'bundle' => 'cura_beni_comuni',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tipologia_intervento',
    'label' => 'Tipologia intervento',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'entityform-cura_beni_comuni-og_group_ref'
  $field_instances['entityform-cura_beni_comuni-og_group_ref'] = array(
    'bundle' => 'cura_beni_comuni',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'Se non hai ancora creato un\'organizzazione <a href="/comunita/node/add/organizzazione">creala ora</a>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'og_group_ref',
    'label' => 'Soggetto capofila',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'access_override' => 0,
          'admin' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'default' => array(
            'widget_type' => 'options_select',
          ),
          'status' => TRUE,
        ),
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'og',
      'settings' => array(),
      'type' => 'og_complex',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-field_codice_fiscale'
  $field_instances['entityform-vandalismo_grafico-field_codice_fiscale'] = array(
    'bundle' => 'vandalismo_grafico',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_codice_fiscale',
    'label' => 'Codice Fiscale',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-field_cognome'
  $field_instances['entityform-vandalismo_grafico-field_cognome'] = array(
    'bundle' => 'vandalismo_grafico',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_cognome',
    'label' => 'Cognome',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-field_data_intervento'
  $field_instances['entityform-vandalismo_grafico-field_data_intervento'] = array(
    'bundle' => 'vandalismo_grafico',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_data_intervento',
    'label' => 'Data dell\'intervento',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-field_data_intervento_multiple'
  $field_instances['entityform-vandalismo_grafico-field_data_intervento_multiple'] = array(
    'bundle' => 'vandalismo_grafico',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_data_intervento_multiple',
    'label' => 'Date per interventi da effettuarsi in più giornate',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-field_dichiaro_1'
  $field_instances['entityform-vandalismo_grafico-field_dichiaro_1'] = array(
    'bundle' => 'vandalismo_grafico',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_dichiaro_1',
    'label' => 'Dichiaro che occuperò la porzione di suolo pubblico nella data dell\'intervento indicata e compresa tra i civici indicati',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-field_dichiaro_2'
  $field_instances['entityform-vandalismo_grafico-field_dichiaro_2'] = array(
    'bundle' => 'vandalismo_grafico',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'vedi PG 202684/2014',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_dichiaro_2',
    'label' => 'Dichiaro che l\'intervento verrà effettuato nel rispetto delle linee guida di cui ho preso visione',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-field_email'
  $field_instances['entityform-vandalismo_grafico-field_email'] = array(
    'bundle' => 'vandalismo_grafico',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_email',
    'label' => 'Email',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-field_foto_del_luogo'
  $field_instances['entityform-vandalismo_grafico-field_foto_del_luogo'] = array(
    'bundle' => 'vandalismo_grafico',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 17,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_foto_del_luogo',
    'label' => 'Foto del luogo',
    'required' => 1,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'vandalismo',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '6 MB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-field_indirizzo_intervento'
  $field_instances['entityform-vandalismo_grafico-field_indirizzo_intervento'] = array(
    'bundle' => 'vandalismo_grafico',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Indicare via e civici e/o ulteriori elementi utili all\'individuazione dell\'area)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_indirizzo_intervento',
    'label' => 'Indirizzo dell\'intervento',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-field_larghezza'
  $field_instances['entityform-vandalismo_grafico-field_larghezza'] = array(
    'bundle' => 'vandalismo_grafico',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_larghezza',
    'label' => 'Larghezza',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-field_lunghezza'
  $field_instances['entityform-vandalismo_grafico-field_lunghezza'] = array(
    'bundle' => 'vandalismo_grafico',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_lunghezza',
    'label' => 'Lunghezza',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-field_nome'
  $field_instances['entityform-vandalismo_grafico-field_nome'] = array(
    'bundle' => 'vandalismo_grafico',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_nome',
    'label' => 'Nome',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-field_protezione'
  $field_instances['entityform-vandalismo_grafico-field_protezione'] = array(
    'bundle' => 'vandalismo_grafico',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Inserire il nome del prodotto.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_protezione',
    'label' => 'Protezione',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-field_pulitura'
  $field_instances['entityform-vandalismo_grafico-field_pulitura'] = array(
    'bundle' => 'vandalismo_grafico',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Inserire il nome del prodotto.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_pulitura',
    'label' => 'Pulitura',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-field_quartiere_intervento'
  $field_instances['entityform-vandalismo_grafico-field_quartiere_intervento'] = array(
    'bundle' => 'vandalismo_grafico',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_quartiere_intervento',
    'label' => 'Quartiere di intervento',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-field_telefono'
  $field_instances['entityform-vandalismo_grafico-field_telefono'] = array(
    'bundle' => 'vandalismo_grafico',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_telefono',
    'label' => 'Telefono',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-field_tipologia_superfice'
  $field_instances['entityform-vandalismo_grafico-field_tipologia_superfice'] = array(
    'bundle' => 'vandalismo_grafico',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'In caso di interventi di diversa tipologia fare due distinte comunicazioni',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tipologia_superfice',
    'label' => 'Tipologia della superfice',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-field_ulteriori_indicazioni'
  $field_instances['entityform-vandalismo_grafico-field_ulteriori_indicazioni'] = array(
    'bundle' => 'vandalismo_grafico',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_ulteriori_indicazioni',
    'label' => 'Ulteriori indicazioni',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'entityform-vandalismo_grafico-og_group_ref'
  $field_instances['entityform-vandalismo_grafico-og_group_ref'] = array(
    'bundle' => 'vandalismo_grafico',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'Invia il modulo con una delle tue organizzazioni.
Se non hai ancora creato un\'organizzazione <a href="node/add/organizzazione">creala ora</a>.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'og_group_ref',
    'label' => 'Soggetto capofila',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'access_override' => 0,
          'admin' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'default' => array(
            'widget_type' => 'options_select',
          ),
          'status' => TRUE,
        ),
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'og',
      'settings' => array(),
      'type' => 'og_complex',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t(' Descrizione della ragione dell\'intervento per la collettività');
  t('Allegati obiettivo e piano delle attività');
  t('Area tematica');
  t('Codice Fiscale');
  t('Cognome');
  t('Data dell\'intervento');
  t('Data di avvio');
  t('Data di conclusione prevista');
  t('Date per interventi da effettuarsi in più giornate');
  t('Descrizione Obiettivo e Piano Attività');
  t('Descrizione breve del progetto');
  t('Dichiaro che l\'intervento verrà effettuato nel rispetto delle linee guida di cui ho preso visione');
  t('Dichiaro che occuperò la porzione di suolo pubblico nella data dell\'intervento indicata e compresa tra i civici indicati');
  t('E\' possibile richiedere tutte le forme di supporto indicate nel foglio.');
  t('Email');
  t('Eventuale verifica avanzamento / rendicontazione intermedia');
  t('Foto del luogo');
  t('Immagine');
  t('In caso di interventi di diversa tipologia fare due distinte comunicazioni');
  t('Indicare via e civici e/o ulteriori elementi utili all\'individuazione dell\'area)');
  t('Indirizzo dell\'intervento');
  t('Info per Georeferenziazione');
  t('Inserire il nome del prodotto.');
  t('Invia il modulo con una delle tue organizzazioni.
Se non hai ancora creato un\'organizzazione <a href="node/add/organizzazione">creala ora</a>.');
  t('Larghezza');
  t('Link pagina esterna');
  t('Lunghezza');
  t('Motivazione dell\'individuazione come Bene Comune');
  t('Nome');
  t('Nome del bando / avviso da cui si ricevono eventuali altre forme di sostegno o per cui si è fatta richiesta');
  t('Patrocinio');
  t('Presentazione dell\'obiettivo progettuale e del piano delle attività distinte tra di loro');
  t('Protezione');
  t('Pulitura');
  t('Quartiere di intervento');
  t('Se non hai ancora creato un\'organizzazione <a href="/comunita/node/add/organizzazione">creala ora</a>');
  t('Soggetto capofila');
  t('Strumento di finanziamento');
  t('Supporto richiesto');
  t('Telefono');
  t('Tipologia del bene oggetto di intervento');
  t('Tipologia della superfice');
  t('Tipologia intervento');
  t('Ulteriori indicazioni');
  t('vedi PG 202684/2014');

  return $field_instances;
}
