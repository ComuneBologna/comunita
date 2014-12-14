<?php
/**
 * @file
 * comunita_segnalazioni.features.inc
 */

/**
 * Implements hook_default_entityform_type().
 */
function comunita_segnalazioni_default_entityform_type() {
  $items = array();
  $items['segnala_organizzazione'] = entity_import('entityform_type', '{
    "type" : "segnala_organizzazione",
    "label" : "Segnala Organizzazione",
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
      "submission_page_title" : "",
      "submission_text" : { "value" : "", "format" : "filtered_html" },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "1" : "1", "2" : "2", "3" : "3", "4" : "4" },
      "resubmit_action" : "new",
      "redirect_path" : "\\u003Cfront\\u003E",
      "instruction_pre" : { "value" : "Segnala questa organizzazione", "format" : "filtered_html" }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/segnala-organizzazione",
        "alias" : "segnala-organizzazione",
        "language" : "und"
      }
    }
  }');
  $items['segnala_progetto'] = entity_import('entityform_type', '{
    "type" : "segnala_progetto",
    "label" : "Segnala Progetto",
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
      "submission_page_title" : "",
      "submission_text" : { "value" : "", "format" : "filtered_html" },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "1" : "1", "2" : "2", "3" : "3", "4" : "4" },
      "resubmit_action" : "new",
      "redirect_path" : "\\u003Cfront\\u003E",
      "instruction_pre" : { "value" : "Segnala questo progetto", "format" : "filtered_html" }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/segnala-progetto",
        "alias" : "segnala-progetto",
        "language" : "und"
      }
    }
  }');
  $items['segnala_utente'] = entity_import('entityform_type', '{
    "type" : "segnala_utente",
    "label" : "Segnala Utente",
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
      "submission_page_title" : "",
      "submission_text" : { "value" : "", "format" : "filtered_html" },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "1" : "1", "2" : "2", "3" : "3", "4" : "4" },
      "resubmit_action" : "new",
      "redirect_path" : "\\u003Cfront\\u003E",
      "instruction_pre" : { "value" : "Segnala questo utente", "format" : "filtered_html" }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/segnala-utente",
        "alias" : "segnala-utente",
        "language" : "und"
      }
    }
  }');
  return $items;
}
