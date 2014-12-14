<?php
/**
 * @file
 * comunita_forms.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function comunita_forms_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_entityform_type().
 */
function comunita_forms_default_entityform_type() {
  $items = array();
  $items['cura_beni_comuni'] = entity_import('entityform_type', '{
    "type" : "cura_beni_comuni",
    "label" : "Proposte per la cura e la rigenerazione dei beni comuni",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "filtered_html" },
      "submit_button_text" : "",
      "submit_confirm_msg" : "Grazie per aver compilato il modulo",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "Hai gi\\u00e0 inviato il modulo.",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "Invio confermato",
      "submission_text" : {
        "value" : "\\u003Cp\\u003ELa tua segnalazione sar\\u00e0 presa in carico dal nostro staff.\\u0026nbsp;\\u003Cbr \\/\\u003EPotremmo ricontattarti per chiederti ulteriori dettagli.\\u003C\\/p\\u003E",
        "format" : "filtered_html"
      },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "1" : "1", "2" : "2", "3" : "3", "4" : "4", "5" : "5" },
      "resubmit_action" : "new",
      "redirect_path" : "\\u003Cfront\\u003E",
      "instruction_pre" : {
        "value" : "\\u003Cp\\u003ECoerentemente con il regolamento, \\u00e8 stato pubblicato un Avviso pubblico per la formulazione, da parte di cittadini, di proposte di collaborazione con l\\u2019Amministrazione per la cura e la rigenerazione dei beni comuni urbani.\\u003Cbr \\/\\u003EPrima di inviare una proposta consulta il \\u003Ca href=\\u0022http:\\/\\/www.comune.bo.it\\/media\\/files\\/allegato_a_al_pg_n._1978852014.pdf\\u0022\\u003Etesto del bando\\u003C\\/a\\u003E\\u003C\\/p\\u003E",
        "format" : "filtered_html"
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/cura-beni-comuni",
        "alias" : "cura-beni-comuni",
        "language" : "und"
      }
    }
  }');
  $items['vandalismo_grafico'] = entity_import('entityform_type', '{
    "type" : "vandalismo_grafico",
    "label" : "Vandalismo Grafico",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "filtered_html" },
      "submit_button_text" : "",
      "submit_confirm_msg" : "Grazie per aver compilato il modulo",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "Hai gi\\u00e0 inviato il modulo.",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "",
      "submission_text" : {
        "value" : "Grazie per aver compilato il modulo.",
        "format" : "filtered_html"
      },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "2" : "2", "3" : "3", "4" : "4", "1" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "\\u003Cfront\\u003E",
      "instruction_pre" : {
        "value" : "\\u003Ch3\\u003EInterventi di rimozione del vandalismo grafico\\u003C\\/h3\\u003E\\r\\n\\u003Cp\\u003E\\r\\n\\u003Cstrong\\u003EAttenzione procedura effettuabile solo per interventi che non modifichino la circolazione stradale (es. divieto di sosta). In casi diversi rivolgersi direttamente all\\u0027URP di Quartiere.\\r\\nPer interventi da effettuarsi in pi\\u00f9 giornate inserire le singole date.\\r\\n\\u003C\\/p\\u003E",
        "format" : "filtered_html"
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/vandalismo-grafico",
        "alias" : "vandalismo-grafico",
        "language" : "und"
      }
    }
  }');
  return $items;
}
