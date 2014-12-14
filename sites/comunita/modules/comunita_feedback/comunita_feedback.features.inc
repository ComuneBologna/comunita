<?php
/**
 * @file
 * comunita_feedback.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function comunita_feedback_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_entityform_type().
 */
function comunita_feedback_default_entityform_type() {
  $items = array();
  $items['feedback'] = entity_import('entityform_type', '{
    "type" : "feedback",
    "label" : "Modulo di raccolta Feedback e Proposte",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "filtered_html" },
      "submit_button_text" : "",
      "submit_confirm_msg" : "Grazie per la tua segnalazione",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "Invio confermato",
      "submission_text" : {
        "value" : "\\u003Cp\\u003ELa tua segnalazione sar\\u00e0 presa in carico dal nostro staff.\\u0026nbsp;\\u003Cbr \\/\\u003EPotremmo ricontattarti per chiederti ulteriori dettagli.\\u003C\\/p\\u003E",
        "format" : "full_html"
      },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "1" : "1", "2" : "2", "3" : "3", "4" : "4", "5" : "5" },
      "resubmit_action" : "new",
      "redirect_path" : "\\u003Cfront\\u003E",
      "instruction_pre" : {
        "value" : "\\u003Cp\\u003EAiutaci a migliorare la nuova Rete Civica Iperbole con i tuoi feedback e con le tue proposte. C\\u0027\\u00e8 tempo fino al 30 gennaio 2015.\\u003C\\/p\\u003E",
        "format" : "full_html"
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/feedback",
        "alias" : "feedback",
        "language" : "und"
      }
    }
  }');
  return $items;
}
