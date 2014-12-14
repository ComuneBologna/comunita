<?php
/**
 * @file
 * comunita_progetto_ct.features.inc
 */

/**
 * Implements hook_default_Workflow().
 */
function comunita_progetto_ct_default_Workflow() {
  $workflows = array();

  // Exported workflow: 'progetti'
  $workflows['progetti'] = entity_import('Workflow', '{
    "name" : "progetti",
    "tab_roles" : [],
    "options" : [],
    "states" : {
      "1" : {"sid":"1","wid":"1","weight":"-50","sysid":"1","state":"(creation)","status":"1","name":"(creation)"},
      "9" : {"sid":"9","wid":"1","weight":"-19","sysid":"0","state":"Bozza","status":"1","name":"bozza"},
      "2" : {"sid":"2","wid":"1","weight":"-18","sysid":"0","state":"Presentato","status":"1","name":"presentato"},
      "3" : {"sid":"3","wid":"1","weight":"-17","sysid":"0","state":"In corso di valutazione","status":"1","name":"in_corso_di_valutazione"},
      "4" : {"sid":"4","wid":"1","weight":"-16","sysid":"0","state":"Approvato","status":"1","name":"approvato"},
      "5" : {"sid":"5","wid":"1","weight":"-15","sysid":"0","state":"Programmato","status":"1","name":"programmato"},
      "6" : {"sid":"6","wid":"1","weight":"-14","sysid":"0","state":"In fase di sviluppo","status":"1","name":"in_fase_di_sviluppo"},
      "7" : {"sid":"7","wid":"1","weight":"-13","sysid":"0","state":"In corso di svolgimento","status":"1","name":"in_corso_di_svolgimento"},
      "8" : {"sid":"8","wid":"1","weight":"-12","sysid":"0","state":"Concluso","status":"1","name":"concluso"}
    },
    "transitions" : {
      "15" : {"tid":"15","sid":"1","target_sid":"9","roles":{"-1":-1},"wid":"1","name":"1_9","label":"","rdf_mapping":[]},
      "1" : {"tid":"1","sid":"1","target_sid":"2","roles":{"-1":-1,"3":3},"wid":"1","name":"1_2","label":"","rdf_mapping":[]},
      "16" : {"tid":"16","sid":"9","target_sid":"9","roles":{"-1":-1,"1":1,"3":3,"4":4},"wid":"1","name":"9_9","label":"","rdf_mapping":[]},
      "17" : {"tid":"17","sid":"9","target_sid":"2","roles":{"-1":-1},"wid":"1","name":"9_2","label":"","rdf_mapping":[]},
      "2" : {"tid":"2","sid":"2","target_sid":"2","roles":{"-1":-1,"1":1,"3":3,"4":4},"wid":"1","name":"2_2","label":"","rdf_mapping":[]},
      "3" : {"tid":"3","sid":"2","target_sid":"3","roles":{"3":3,"4":4},"wid":"1","name":"2_3","label":"","rdf_mapping":[]},
      "18" : {"tid":"18","sid":"3","target_sid":"9","roles":{"3":3},"wid":"1","name":"3_9","label":"","rdf_mapping":[]},
      "9" : {"tid":"9","sid":"3","target_sid":"3","roles":{"-1":-1,"1":1,"3":3,"4":4},"wid":"1","name":"3_3","label":"","rdf_mapping":[]},
      "19" : {"tid":"19","sid":"3","target_sid":"4","roles":{"3":3,"4":4},"wid":"1","name":"3_4","label":"","rdf_mapping":[]},
      "20" : {"tid":"20","sid":"4","target_sid":"3","roles":{"3":3},"wid":"1","name":"4_3","label":"","rdf_mapping":[]},
      "10" : {"tid":"10","sid":"4","target_sid":"4","roles":{"-1":-1,"1":1,"3":3,"4":4},"wid":"1","name":"4_4","label":"","rdf_mapping":[]},
      "21" : {"tid":"21","sid":"4","target_sid":"5","roles":{"-1":-1},"wid":"1","name":"4_5","label":"","rdf_mapping":[]},
      "22" : {"tid":"22","sid":"5","target_sid":"3","roles":{"3":3,"4":4},"wid":"1","name":"5_3","label":"","rdf_mapping":[]},
      "11" : {"tid":"11","sid":"5","target_sid":"5","roles":{"-1":-1,"1":1,"3":3,"4":4},"wid":"1","name":"5_5","label":"","rdf_mapping":[]},
      "23" : {"tid":"23","sid":"5","target_sid":"6","roles":{"-1":-1},"wid":"1","name":"5_6","label":"","rdf_mapping":[]},
      "46" : {"tid":"46","sid":"6","target_sid":"3","roles":{"3":3,"4":4},"wid":"1","name":"6_3","label":"","rdf_mapping":[]},
      "12" : {"tid":"12","sid":"6","target_sid":"6","roles":{"-1":-1,"1":1,"3":3,"4":4},"wid":"1","name":"6_6","label":"","rdf_mapping":[]},
      "24" : {"tid":"24","sid":"6","target_sid":"7","roles":{"-1":-1},"wid":"1","name":"6_7","label":"","rdf_mapping":[]},
      "47" : {"tid":"47","sid":"7","target_sid":"3","roles":{"3":3,"4":4},"wid":"1","name":"7_3","label":"","rdf_mapping":[]},
      "13" : {"tid":"13","sid":"7","target_sid":"7","roles":{"-1":-1,"1":1,"3":3,"4":4},"wid":"1","name":"7_7","label":"","rdf_mapping":[]},
      "25" : {"tid":"25","sid":"7","target_sid":"8","roles":{"-1":-1},"wid":"1","name":"7_8","label":"","rdf_mapping":[]},
      "48" : {"tid":"48","sid":"8","target_sid":"3","roles":{"3":3,"4":4},"wid":"1","name":"8_3","label":"","rdf_mapping":[]},
      "14" : {"tid":"14","sid":"8","target_sid":"8","roles":{"-1":-1,"1":1,"3":3,"4":4},"wid":"1","name":"8_8","label":"","rdf_mapping":[]}
    },
    "label" : "Progetti",
    "typeMap" : [],
    "rdf_mapping" : [],
    "wid_original" : "1",
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
function comunita_progetto_ct_ctools_plugin_api($module = NULL, $api = NULL) {
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
function comunita_progetto_ct_node_info() {
  $items = array(
    'progetto' => array(
      'name' => t('Progetto'),
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
