<?php

function comunita_theme_page_alter(&$page) {
  foreach (system_region_list($GLOBALS['theme'], REGIONS_ALL) as $region => $name) {
    if (in_array($region, array('iperbole_header'))) {
      $page['iperbole_header'] = array(
                '#region' => 'iperbole_header',
                '#weight' => '-10',
                '#theme_wrappers' => array('region'),
      );
    }
  }
}

function comunita_theme_preprocess_page(&$vars) {
  global $user;
  $vars['notitle'] = FALSE;
  
  if(isset($vars['node'])) {
    if(in_array($vars['node']->type, array('page', 'organizzazione', 'progetto', 'article', 'bene_comune', 'consultazione', 'proposta', 'patto_di_collaborazione', 'gruppo_di_consultazioni')) || $vars['node']->nid == 11 || $vars['node']->nid == 21 || $vars['node']->nid == 32 || $vars['node']->nid == 75) {
      $vars['notitle'] = TRUE;
    }
  }
  elseif((arg(0) == 'user') || (arg(0) == 'progetti') || (arg(0) == 'consultazioni') || (arg(0) == 'profili') || (arg(0) == 'beni-comuni') || (arg(0) == 'organizzazioni')) {
    $vars['notitle'] = TRUE;
  }
  
  if(isset($vars['tabs'])) {
    // No tabs for users except admin and redazione
    if(!in_array('redazione', $user->roles) && !in_array('administrator', $user->roles)) {
      //unset($vars['tabs']);
    }
  }
}

function comunita_theme_form_comment_form_alter(&$form, &$form_state) {
  $form['comment_body']['#after_build'][] = 'comunita_theme_customize_comment_form';
}

function comunita_theme_customize_comment_form(&$form) {
  $form[LANGUAGE_NONE][0]['format']['#access'] = FALSE;
  return $form;
}

function comunita_theme_preprocess_html(&$vars) {
  //jQtip
  global $base_url;
  drupal_add_css('//cdn.jsdelivr.net/qtip2/2.2.1/jquery.qtip.min.css', array('type' => 'external'));
  drupal_add_js('//cdn.jsdelivr.net/qtip2/2.2.1/jquery.qtip.js', array('type' => 'external', 'weight' => 99, 'group' => JS_THEME));
  drupal_add_js($base_url . '/' . path_to_theme() . '/js/header.js', array('weight' => 100, 'group' => JS_THEME));
}