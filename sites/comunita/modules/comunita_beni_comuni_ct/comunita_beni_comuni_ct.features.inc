<?php
/**
 * @file
 * comunita_beni_comuni_ct.features.inc
 */

/**
 * Implements hook_default_Workflow().
 */
function comunita_beni_comuni_ct_default_Workflow() {
  $workflows = array();

  // Exported workflow: 'beni_comuni'
  $workflows['beni_comuni'] = entity_import('Workflow', '{
    "name" : "beni_comuni",
    "tab_roles" : [],
    "options" : [],
    "states" : {
      "10" : {"sid":"10","wid":"2","weight":"-50","sysid":"1","state":"(creation)","status":"1","name":"(creation)"},
      "11" : {"sid":"11","wid":"2","weight":"-20","sysid":"0","state":"Disponibile","status":"1","name":"disponibile"},
      "12" : {"sid":"12","wid":"2","weight":"-19","sysid":"0","state":"In corso di valutazione","status":"1","name":"in_corso_di_valutazione"},
      "13" : {"sid":"13","wid":"2","weight":"-18","sysid":"0","state":"Preso in carico","status":"1","name":"preso_in_carico"},
      "14" : {"sid":"14","wid":"2","weight":"-17","sysid":"0","state":"Curato","status":"1","name":"curato"}
    },
    "transitions" : {
      "26" : {"tid":"26","sid":"10","target_sid":"11","roles":{"-1":-1,"3":3},"wid":"2","name":"10_11","label":"","rdf_mapping":[]},
      "27" : {"tid":"27","sid":"10","target_sid":"12","roles":{"-1":-1,"3":3},"wid":"2","name":"10_12","label":"","rdf_mapping":[]},
      "28" : {"tid":"28","sid":"10","target_sid":"13","roles":{"-1":-1,"3":3},"wid":"2","name":"10_13","label":"","rdf_mapping":[]},
      "29" : {"tid":"29","sid":"10","target_sid":"14","roles":{"-1":-1,"3":3},"wid":"2","name":"10_14","label":"","rdf_mapping":[]},
      "30" : {"tid":"30","sid":"11","target_sid":"11","roles":{"-1":-1,"3":3},"wid":"2","name":"11_11","label":"","rdf_mapping":[]},
      "31" : {"tid":"31","sid":"11","target_sid":"12","roles":{"-1":-1,"3":3},"wid":"2","name":"11_12","label":"","rdf_mapping":[]},
      "32" : {"tid":"32","sid":"11","target_sid":"13","roles":{"-1":-1,"3":3},"wid":"2","name":"11_13","label":"","rdf_mapping":[]},
      "33" : {"tid":"33","sid":"11","target_sid":"14","roles":{"-1":-1,"3":3},"wid":"2","name":"11_14","label":"","rdf_mapping":[]},
      "34" : {"tid":"34","sid":"12","target_sid":"11","roles":{"-1":-1,"3":3},"wid":"2","name":"12_11","label":"","rdf_mapping":[]},
      "35" : {"tid":"35","sid":"12","target_sid":"12","roles":{"-1":-1,"3":3},"wid":"2","name":"12_12","label":"","rdf_mapping":[]},
      "36" : {"tid":"36","sid":"12","target_sid":"13","roles":{"-1":-1,"3":3},"wid":"2","name":"12_13","label":"","rdf_mapping":[]},
      "37" : {"tid":"37","sid":"12","target_sid":"14","roles":{"-1":-1,"3":3},"wid":"2","name":"12_14","label":"","rdf_mapping":[]},
      "38" : {"tid":"38","sid":"13","target_sid":"11","roles":{"-1":-1,"3":3},"wid":"2","name":"13_11","label":"","rdf_mapping":[]},
      "39" : {"tid":"39","sid":"13","target_sid":"12","roles":{"-1":-1,"3":3},"wid":"2","name":"13_12","label":"","rdf_mapping":[]},
      "40" : {"tid":"40","sid":"13","target_sid":"13","roles":{"-1":-1,"3":3},"wid":"2","name":"13_13","label":"","rdf_mapping":[]},
      "41" : {"tid":"41","sid":"13","target_sid":"14","roles":{"-1":-1,"3":3},"wid":"2","name":"13_14","label":"","rdf_mapping":[]},
      "42" : {"tid":"42","sid":"14","target_sid":"11","roles":{"-1":-1,"3":3},"wid":"2","name":"14_11","label":"","rdf_mapping":[]},
      "43" : {"tid":"43","sid":"14","target_sid":"12","roles":{"-1":-1,"3":3},"wid":"2","name":"14_12","label":"","rdf_mapping":[]},
      "44" : {"tid":"44","sid":"14","target_sid":"13","roles":{"3":3},"wid":"2","name":"14_13","label":"","rdf_mapping":[]},
      "45" : {"tid":"45","sid":"14","target_sid":"14","roles":{"-1":-1,"3":3},"wid":"2","name":"14_14","label":"","rdf_mapping":[]}
    },
    "label" : "Beni Comuni",
    "typeMap" : [],
    "rdf_mapping" : [],
    "wid_original" : "2",
    "system_roles" : {
      "-1" : "(autore)",
      "1" : "utente anonimo",
      "2" : "utente autenticato",
      "3" : "administrator",
      "4" : "redazione",
      "5" : "community manager"
    }
  }');

  return $workflows;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function comunita_beni_comuni_ct_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function comunita_beni_comuni_ct_node_info() {
  $items = array(
    'bene_comune' => array(
      'name' => t('Bene Comune'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titolo'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
