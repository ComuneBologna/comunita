<?php
/**
 * @file
 * comunita_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function comunita_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'beni_comuni';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Beni Comuni';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'altro';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Voci per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tutto -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Scostamento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« prima';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ precedente';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'seguente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'ultima »';
  $handler->display->display_options['style_plugin'] = 'masonry_views';
  $handler->display->display_options['style_options']['masonry_resizable'] = TRUE;
  $handler->display->display_options['style_options']['masonry_animated'] = TRUE;
  $handler->display->display_options['style_options']['masonry_fit_width'] = FALSE;
  $handler->display->display_options['style_options']['masonry_rtl'] = FALSE;
  $handler->display->display_options['style_options']['masonry_images_first'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Intestazione: Globale: Area di testo */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h1>Schede dei Beni Comuni</h1>
<p>I beni comuni attualmente oggetto di interventi di cura.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Campo: Contenuto: Fotografia */
  $handler->display->display_options['fields']['field_fotografia']['id'] = 'field_fotografia';
  $handler->display->display_options['fields']['field_fotografia']['table'] = 'field_data_field_fotografia';
  $handler->display->display_options['fields']['field_fotografia']['field'] = 'field_fotografia';
  $handler->display->display_options['fields']['field_fotografia']['label'] = '';
  $handler->display->display_options['fields']['field_fotografia']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fotografia']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_fotografia']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Campo: Contenuto: Descrizione breve */
  $handler->display->display_options['fields']['field_descrizione_breve_progetto']['id'] = 'field_descrizione_breve_progetto';
  $handler->display->display_options['fields']['field_descrizione_breve_progetto']['table'] = 'field_data_field_descrizione_breve_progetto';
  $handler->display->display_options['fields']['field_descrizione_breve_progetto']['field'] = 'field_descrizione_breve_progetto';
  $handler->display->display_options['fields']['field_descrizione_breve_progetto']['label'] = '';
  $handler->display->display_options['fields']['field_descrizione_breve_progetto']['element_label_colon'] = FALSE;
  /* Campo: Contenuto: Tipologia */
  $handler->display->display_options['fields']['field_tipologia']['id'] = 'field_tipologia';
  $handler->display->display_options['fields']['field_tipologia']['table'] = 'field_data_field_tipologia';
  $handler->display->display_options['fields']['field_tipologia']['field'] = 'field_tipologia';
  $handler->display->display_options['fields']['field_tipologia']['label'] = '';
  $handler->display->display_options['fields']['field_tipologia']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tipologia']['type'] = 'taxonomy_term_reference_plain';
  /* Criterio di ordinamento: Contenuto: Data di inserimento */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'progetto' => 'progetto',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bene_comune' => 'bene_comune',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Criterio del filtro: Contenuto: Titolo */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Cerca progetto';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Criterio del filtro: Workflow current: Current state */
  $handler->display->display_options['filters']['sid']['id'] = 'sid';
  $handler->display->display_options['filters']['sid']['table'] = 'workflow_node_current';
  $handler->display->display_options['filters']['sid']['field'] = 'sid';
  $handler->display->display_options['filters']['sid']['group'] = 1;
  $handler->display->display_options['filters']['sid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sid']['expose']['operator_id'] = 'sid_op';
  $handler->display->display_options['filters']['sid']['expose']['label'] = 'Stato';
  $handler->display->display_options['filters']['sid']['expose']['operator'] = 'sid_op';
  $handler->display->display_options['filters']['sid']['expose']['identifier'] = 'sid';
  $handler->display->display_options['filters']['sid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['sid']['expose']['workflow_reduce_wid'] = '2';
  /* Criterio del filtro: Contenuto: Tag/Categorie (field_tag_categorie) */
  $handler->display->display_options['filters']['field_tag_categorie_tid']['id'] = 'field_tag_categorie_tid';
  $handler->display->display_options['filters']['field_tag_categorie_tid']['table'] = 'field_data_field_tag_categorie';
  $handler->display->display_options['filters']['field_tag_categorie_tid']['field'] = 'field_tag_categorie_tid';
  $handler->display->display_options['filters']['field_tag_categorie_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tag_categorie_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tag_categorie_tid']['expose']['operator_id'] = 'field_tag_categorie_tid_op';
  $handler->display->display_options['filters']['field_tag_categorie_tid']['expose']['label'] = 'Ricerca per tag';
  $handler->display->display_options['filters']['field_tag_categorie_tid']['expose']['operator'] = 'field_tag_categorie_tid_op';
  $handler->display->display_options['filters']['field_tag_categorie_tid']['expose']['identifier'] = 'field_tag_categorie_tid';
  $handler->display->display_options['filters']['field_tag_categorie_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_tag_categorie_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tag_categorie_tid']['vocabulary'] = 'tags';
  $handler->display->display_options['path'] = 'beni-comuni/elenco';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'progetti.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Intestazione: Globale: Area di testo */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Beni Comuni</h2>
<p>Vuoi prenderti cura di un bene comune? Scopri come e le attività realizzate, le risorse e gli strumenti.</p>
<a href="beni-comuni" class="scopri">Vai a beni comuni</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Contenuto: Fotografia */
  $handler->display->display_options['fields']['field_fotografia']['id'] = 'field_fotografia';
  $handler->display->display_options['fields']['field_fotografia']['table'] = 'field_data_field_fotografia';
  $handler->display->display_options['fields']['field_fotografia']['field'] = 'field_fotografia';
  $handler->display->display_options['fields']['field_fotografia']['label'] = '';
  $handler->display->display_options['fields']['field_fotografia']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fotografia']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_fotografia']['settings'] = array(
    'image_style' => 'large',
    'image_link' => 'content',
  );
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Campo: Contenuto: Tipologia */
  $handler->display->display_options['fields']['field_tipologia']['id'] = 'field_tipologia';
  $handler->display->display_options['fields']['field_tipologia']['table'] = 'field_data_field_tipologia';
  $handler->display->display_options['fields']['field_tipologia']['field'] = 'field_tipologia';
  $handler->display->display_options['fields']['field_tipologia']['label'] = '';
  $handler->display->display_options['fields']['field_tipologia']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tipologia']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_tipologia']['element_class'] = 'tipologia';
  $handler->display->display_options['fields']['field_tipologia']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tipologia']['type'] = 'taxonomy_term_reference_plain';
  /* Campo: Globale: Testo personalizzato */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title]
<div>[field_tipologia]</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bene_comune' => 'bene_comune',
  );

  /* Display: Blocco Elenco */
  $handler = $view->new_display('block', 'Blocco Elenco', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Intestazione: Globale: Area di testo */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p>I beni comuni attualmente oggetto di interventi di cura.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bene_comune' => 'bene_comune',
  );
  $translatables['beni_comuni'] = array(
    t('Master'),
    t('altro'),
    t('Applica'),
    t('Ripristina'),
    t('Ordina per'),
    t('Asc'),
    t('Disc'),
    t('Voci per pagina'),
    t('- Tutto -'),
    t('Scostamento'),
    t('« prima'),
    t('‹ precedente'),
    t('seguente ›'),
    t('ultima »'),
    t('<h1>Schede dei Beni Comuni</h1>
<p>I beni comuni attualmente oggetto di interventi di cura.</p>'),
    t('Page'),
    t('Cerca progetto'),
    t('Stato'),
    t('Ricerca per tag'),
    t('Feed'),
    t('Block'),
    t('<h2>Beni Comuni</h2>
<p>Vuoi prenderti cura di un bene comune? Scopri come e le attività realizzate, le risorse e gli strumenti.</p>
<a href="beni-comuni" class="scopri">Vai a beni comuni</a>'),
    t('[title]
<div>[field_tipologia]</div>'),
    t('Blocco Elenco'),
    t('<p>I beni comuni attualmente oggetto di interventi di cura.</p>'),
  );
  $export['beni_comuni'] = $view;

  $view = new view();
  $view->name = 'blog';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Blog';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Blog';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'altro';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relazione: OG membership: OG membership from Nodo */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Criterio di ordinamento: Contenuto: Sempre in cima */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Criterio di ordinamento: Contenuto: Data di inserimento */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtro contestuale: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['gid']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['gid']['validate_options']['types'] = array(
    'organizzazione' => 'organizzazione',
  );
  $handler->display->display_options['arguments']['gid']['validate']['fail'] = 'empty';
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );

  /* Display: Post in evidenza */
  $handler = $view->new_display('block', 'Post in evidenza', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Contenuto: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  /* Campo: Globale: Testo personalizzato */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h2>Il blog della Rete Civica</h2>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'title';
  /* Campo: Contenuto: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'Leggi';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Campo: Globale: Testo personalizzato */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[nothing]
<div class="title">[title]</div>
[nid]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'blog';

  /* Display: Elenco */
  $handler = $view->new_display('block', 'Elenco', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'list-group-item';
  $handler->display->display_options['style_options']['class'] = 'list-group';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relazione: OG membership: OG membership from Nodo */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtro contestuale: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['gid']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['gid']['validate_options']['types'] = array(
    'organizzazione' => 'organizzazione',
  );
  $handler->display->display_options['arguments']['gid']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Cosa succede su Comunità */
  $handler = $view->new_display('block', 'Cosa succede su Comunità', 'block_succede');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'list-group-item';
  $handler->display->display_options['style_options']['class'] = 'list-group';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relazione: Contenuto: Autore */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relazione: Flag: segui_utente */
  $handler->display->display_options['relationships']['flag_content_rel_1']['id'] = 'flag_content_rel_1';
  $handler->display->display_options['relationships']['flag_content_rel_1']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel_1']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_1']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['flag_content_rel_1']['label'] = 'segue utente';
  $handler->display->display_options['relationships']['flag_content_rel_1']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_1']['flag'] = 'segui_utente';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Campo: Utente: Nome */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Criterio del filtro: Flag: Flagged */
  $handler->display->display_options['filters']['flagged_1']['id'] = 'flagged_1';
  $handler->display->display_options['filters']['flagged_1']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged_1']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged_1']['relationship'] = 'flag_content_rel_1';
  $handler->display->display_options['filters']['flagged_1']['value'] = '1';
  $handler->display->display_options['filters']['flagged_1']['group'] = 2;
  /* Criterio del filtro: Contenuto: Identificativo uid dell'autore */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'node';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = array(
    0 => '74',
  );
  $handler->display->display_options['filters']['uid']['group'] = 2;

  /* Display: Blog pagine interne */
  $handler = $view->new_display('block', 'Blog pagine interne', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Il blog della Rete Civica';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'list-group-item';
  $handler->display->display_options['style_options']['class'] = 'list-group';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relazione: OG membership: OG membership from Nodo */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Criterio del filtro: OG membership: Group ID */
  $handler->display->display_options['filters']['gid']['id'] = 'gid';
  $handler->display->display_options['filters']['gid']['table'] = 'og_membership';
  $handler->display->display_options['filters']['gid']['field'] = 'gid';
  $handler->display->display_options['filters']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['gid']['value']['value'] = '123';
  $translatables['blog'] = array(
    t('Master'),
    t('Blog'),
    t('altro'),
    t('Applica'),
    t('Ripristina'),
    t('Ordina per'),
    t('Asc'),
    t('Disc'),
    t('OG membership from node'),
    t('Tutti'),
    t('Post in evidenza'),
    t('<h2>Il blog della Rete Civica</h2>'),
    t('Leggi'),
    t('[nothing]
<div class="title">[title]</div>
[nid]'),
    t('blog'),
    t('Elenco'),
    t('Cosa succede su Comunità'),
    t('autore'),
    t('segue utente'),
    t('Blog pagine interne'),
    t('Il blog della Rete Civica'),
  );
  $export['blog'] = $view;

  $view = new view();
  $view->name = 'consultazioni';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Consultazioni';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Consultazioni';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'altro';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Voci per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tutto -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Scostamento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« prima';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ precedente';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'seguente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'ultima »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Intestazione: Globale: Area di testo */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h1>Consultazioni</h1>
<p>Visualizza tutte le consultazioni aperte e già concluse promosse all\'interno del network Comunità.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Campo: Contenuto: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = '';
  $handler->display->display_options['fields']['field_tags']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tags']['alter']['text'] = '#[field_tags] ';
  $handler->display->display_options['fields']['field_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tags']['separator'] = ' ';
  /* Campo: Contenuto: Testo */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '250',
  );
  /* Criterio di ordinamento: Contenuto: Data di inserimento */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'consultazione' => 'consultazione',
    'gruppo_di_consultazioni' => 'gruppo_di_consultazioni',
  );
  /* Criterio del filtro: Contenuto: Titolo */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Titolo';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Criterio del filtro: Workflow current: Current state */
  $handler->display->display_options['filters']['sid']['id'] = 'sid';
  $handler->display->display_options['filters']['sid']['table'] = 'workflow_node_current';
  $handler->display->display_options['filters']['sid']['field'] = 'sid';
  $handler->display->display_options['filters']['sid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sid']['expose']['operator_id'] = 'sid_op';
  $handler->display->display_options['filters']['sid']['expose']['label'] = 'Stato';
  $handler->display->display_options['filters']['sid']['expose']['operator'] = 'sid_op';
  $handler->display->display_options['filters']['sid']['expose']['identifier'] = 'sid';
  $handler->display->display_options['filters']['sid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['sid']['expose']['workflow_reduce_wid'] = '3';
  /* Criterio del filtro: Contenuto: Tags (field_tags) */
  $handler->display->display_options['filters']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['value'] = '';
  $handler->display->display_options['filters']['field_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator_id'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['label'] = 'Ricerca per tag';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['identifier'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tags_tid']['vocabulary'] = 'tags';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'consultazioni';
  $translatables['consultazioni'] = array(
    t('Master'),
    t('Consultazioni'),
    t('altro'),
    t('Applica'),
    t('Ripristina'),
    t('Ordina per'),
    t('Asc'),
    t('Disc'),
    t('Voci per pagina'),
    t('- Tutto -'),
    t('Scostamento'),
    t('« prima'),
    t('‹ precedente'),
    t('seguente ›'),
    t('ultima »'),
    t('<h1>Consultazioni</h1>
<p>Visualizza tutte le consultazioni aperte e già concluse promosse all\'interno del network Comunità.</p>'),
    t('#[field_tags] '),
    t('Titolo'),
    t('Stato'),
    t('Ricerca per tag'),
    t('Page'),
  );
  $export['consultazioni'] = $view;

  $view = new view();
  $view->name = 'followers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Followers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Followers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'altro';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'user';
  $handler->display->display_options['row_options']['view_mode'] = 'elenco_profili';
  /* Relazione: Flag: User's flaggings */
  $handler->display->display_options['relationships']['flag_user_content_rel']['id'] = 'flag_user_content_rel';
  $handler->display->display_options['relationships']['flag_user_content_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_user_content_rel']['field'] = 'flag_user_content_rel';
  $handler->display->display_options['relationships']['flag_user_content_rel']['flag'] = 'segui';
  /* Campo: Utente: Nome */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Criterio di ordinamento: Utente: Data creazione */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtro contestuale: Flag: ID contenuto */
  $handler->display->display_options['arguments']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['table'] = 'flagging';
  $handler->display->display_options['arguments']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['relationship'] = 'flag_user_content_rel';
  $handler->display->display_options['arguments']['entity_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['entity_id']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments']['entity_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['entity_id']['default_argument_options']['argument'] = '1';
  $handler->display->display_options['arguments']['entity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['entity_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['entity_id']['validate']['type'] = 'flag_flaggable_node';
  $handler->display->display_options['arguments']['entity_id']['validate_options']['flag_name'] = 'segui';
  /* Criterio del filtro: Utente: Attivo */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['followers'] = array(
    t('Master'),
    t('Followers'),
    t('altro'),
    t('Applica'),
    t('Ripristina'),
    t('Ordina per'),
    t('Asc'),
    t('Disc'),
    t('user flagged content'),
    t('Tutti'),
    t('Block'),
  );
  $export['followers'] = $view;

  $view = new view();
  $view->name = 'mappa_homepage';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Mappa Homepage';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Mappa Homepage';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'altro';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_geojson';
  $handler->display->display_options['style_options']['data_source']['value'] = 'geofield';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'field_geo';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'title';
  $handler->display->display_options['style_options']['data_source']['name_field'] = '';
  $handler->display->display_options['style_options']['data_source']['description_field'] = '';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Campo: Contenuto: Georeferenziazione */
  $handler->display->display_options['fields']['field_geo']['id'] = 'field_geo';
  $handler->display->display_options['fields']['field_geo']['table'] = 'field_data_field_geo';
  $handler->display->display_options['fields']['field_geo']['field'] = 'field_geo';
  $handler->display->display_options['fields']['field_geo']['label'] = '';
  $handler->display->display_options['fields']['field_geo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geo']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_geo']['settings'] = array(
    'data' => 'full',
  );
  /* Campo: Contenuto: Tipo */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Criterio di ordinamento: Contenuto: Data di inserimento */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtro contestuale: Contenuto: Tipo */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['default_argument_options']['argument'] = 'progetto';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['type']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['type']['validate']['fail'] = 'empty';
  $handler->display->display_options['arguments']['type']['limit'] = '0';
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bene_comune' => 'bene_comune',
    'organizzazione' => 'organizzazione',
    'progetto' => 'progetto',
  );
  /* Criterio del filtro: Contenuto: Stato Documento (field_stato_documento) */
  $handler->display->display_options['filters']['field_stato_documento_value']['id'] = 'field_stato_documento_value';
  $handler->display->display_options['filters']['field_stato_documento_value']['table'] = 'field_data_field_stato_documento';
  $handler->display->display_options['filters']['field_stato_documento_value']['field'] = 'field_stato_documento_value';
  $handler->display->display_options['filters']['field_stato_documento_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_stato_documento_value']['value'] = array(
    0 => '0',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'geo.json';
  $translatables['mappa_homepage'] = array(
    t('Master'),
    t('Mappa Homepage'),
    t('altro'),
    t('Applica'),
    t('Ripristina'),
    t('Ordina per'),
    t('Asc'),
    t('Disc'),
    t('Tutti'),
    t('Page'),
  );
  $export['mappa_homepage'] = $view;

  $view = new view();
  $view->name = 'organizzazioni';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Organizzazioni';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'I tuoi profili organizzazione';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'altro';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'elenco_profili';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Criterio di ordinamento: Contenuto: Data di inserimento */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtro contestuale: Contenuto: Identificativo uid dell'autore */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'empty';
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organizzazione' => 'organizzazione',
  );

  /* Display: Blocco Utente */
  $handler = $view->new_display('block', 'Blocco Utente', 'block_1');
  $translatables['organizzazioni'] = array(
    t('Master'),
    t('I tuoi profili organizzazione'),
    t('altro'),
    t('Applica'),
    t('Ripristina'),
    t('Ordina per'),
    t('Asc'),
    t('Disc'),
    t('Tutti'),
    t('Blocco Utente'),
  );
  $export['organizzazioni'] = $view;

  $view = new view();
  $view->name = 'patti_di_collaborazione';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Patti di collaborazione';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Patto di collaborazione';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'altro';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Criterio di ordinamento: Contenuto: Data di inserimento */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtro contestuale: Contenuto: Contenuto collegato (field_contenuto_collegato) */
  $handler->display->display_options['arguments']['field_contenuto_collegato_target_id']['id'] = 'field_contenuto_collegato_target_id';
  $handler->display->display_options['arguments']['field_contenuto_collegato_target_id']['table'] = 'field_data_field_contenuto_collegato';
  $handler->display->display_options['arguments']['field_contenuto_collegato_target_id']['field'] = 'field_contenuto_collegato_target_id';
  $handler->display->display_options['arguments']['field_contenuto_collegato_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_contenuto_collegato_target_id']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments']['field_contenuto_collegato_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_contenuto_collegato_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_contenuto_collegato_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_contenuto_collegato_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_contenuto_collegato_target_id']['specify_validation'] = TRUE;
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'patto_di_collaborazione' => 'patto_di_collaborazione',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['patti_di_collaborazione'] = array(
    t('Master'),
    t('Patto di collaborazione'),
    t('altro'),
    t('Applica'),
    t('Ripristina'),
    t('Ordina per'),
    t('Asc'),
    t('Disc'),
    t('Tutti'),
    t('Block'),
  );
  $export['patti_di_collaborazione'] = $view;

  $view = new view();
  $view->name = 'post_recenti_su_organizzazione';
  $view->description = 'Show all content (nodes) of a group.';
  $view->tag = 'og';
  $view->base_table = 'node';
  $view->human_name = 'Post recenti su Organizzazione';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Post Recenti';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'altro';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Voci per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tutto -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Scostamento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« prima';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ precedente';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'seguente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'ultima »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Comportamento se non ci sono risultati: Globale: Area di testo */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'There is no content in this group.';
  /* Relazione: OG membership: OG membership from Nodo */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Criterio di ordinamento: Contenuto: Data di inserimento */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtro contestuale: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['gid']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );

  /* Display: Post del gruppo */
  $handler = $view->new_display('block', 'Post del gruppo', 'block_1');
  $handler->display->display_options['block_description'] = 'Post recenti Organizzazione';

  /* Display: Post dell'utente */
  $handler = $view->new_display('block', 'Post dell\'utente', 'block_2');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtro contestuale: Contenuto: Identificativo uid dell'autore */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'empty';

  /* Display: Post del gruppo Mini */
  $handler = $view->new_display('block', 'Post del gruppo Mini', 'block_3');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'Post recenti Organizzazione';

  /* Display: Post dell'utente Mini */
  $handler = $view->new_display('block', 'Post dell\'utente Mini', 'block_4');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtro contestuale: Contenuto: Identificativo uid dell'autore */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'empty';
  $handler->display->display_options['block_description'] = 'Post recenti Organizzazione';

  /* Display: Post del gruppo */
  $handler = $view->new_display('block', 'Post del gruppo', 'block_5');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtro contestuale: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['default_argument_options']['argument'] = '1';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  $handler->display->display_options['block_description'] = 'Post recenti Organizzazione';
  $translatables['post_recenti_su_organizzazione'] = array(
    t('Defaults'),
    t('Post Recenti'),
    t('altro'),
    t('Applica'),
    t('Ripristina'),
    t('Ordina per'),
    t('Asc'),
    t('Disc'),
    t('Voci per pagina'),
    t('- Tutto -'),
    t('Scostamento'),
    t('« prima'),
    t('‹ precedente'),
    t('seguente ›'),
    t('ultima »'),
    t('There is no content in this group.'),
    t('OG membership from node'),
    t('Tutti'),
    t('Post del gruppo'),
    t('Post recenti Organizzazione'),
    t('Post dell\'utente'),
    t('Post del gruppo Mini'),
    t('Post dell\'utente Mini'),
  );
  $export['post_recenti_su_organizzazione'] = $view;

  $view = new view();
  $view->name = 'profili';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Profili';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'altro';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '48';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Voci per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tutto -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Scostamento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« prima';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ precedente';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'seguente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'ultima »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Intestazione: Globale: Area di testo */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h1>Profili di Comunità</h1>
<p>Persone, gruppi, associazioni e imprese della città: chi sono e cosa fanno?  Tutto è organizzato per parole chiave così da facilitare la scoperta di contenuti che ti possono interessare.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Campo: Contenuto: Logo Organizzazione */
  $handler->display->display_options['fields']['field_org_picture']['id'] = 'field_org_picture';
  $handler->display->display_options['fields']['field_org_picture']['table'] = 'field_data_field_org_picture';
  $handler->display->display_options['fields']['field_org_picture']['field'] = 'field_org_picture';
  $handler->display->display_options['fields']['field_org_picture']['label'] = '';
  $handler->display->display_options['fields']['field_org_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_org_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_org_picture']['settings'] = array(
    'image_style' => 'profili',
    'image_link' => 'content',
  );
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Campo: Contenuto: Testo */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '50',
  );
  /* Criterio di ordinamento: Contenuto: Data di inserimento */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'progetto' => 'progetto',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Organizzazioni';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'masonry_views';
  $handler->display->display_options['style_options']['masonry_resizable'] = TRUE;
  $handler->display->display_options['style_options']['masonry_animated'] = TRUE;
  $handler->display->display_options['style_options']['masonry_fit_width'] = TRUE;
  $handler->display->display_options['style_options']['masonry_rtl'] = FALSE;
  $handler->display->display_options['style_options']['masonry_images_first'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organizzazione' => 'organizzazione',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Criterio del filtro: Contenuto: Titolo */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Cerca profilo';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['path'] = 'organizzazioni';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'progetti.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Intestazione: Globale: Area di testo */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Profili</h2>
<p>Persone, gruppi, associazioni e imprese della città: chi sono e cosa fanno?</p>
<a href="profili" class="scopri">Elenco profili</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Contenuto: Logo Organizzazione */
  $handler->display->display_options['fields']['field_org_picture']['id'] = 'field_org_picture';
  $handler->display->display_options['fields']['field_org_picture']['table'] = 'field_data_field_org_picture';
  $handler->display->display_options['fields']['field_org_picture']['field'] = 'field_org_picture';
  $handler->display->display_options['fields']['field_org_picture']['label'] = '';
  $handler->display->display_options['fields']['field_org_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_org_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_org_picture']['settings'] = array(
    'image_style' => 'large',
    'image_link' => 'content',
  );
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Campo: Globale: Testo personalizzato */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organizzazione' => 'organizzazione',
  );
  $translatables['profili'] = array(
    t('Master'),
    t('altro'),
    t('Applica'),
    t('Ripristina'),
    t('Ordina per'),
    t('Asc'),
    t('Disc'),
    t('Voci per pagina'),
    t('- Tutto -'),
    t('Scostamento'),
    t('« prima'),
    t('‹ precedente'),
    t('seguente ›'),
    t('ultima »'),
    t('<h1>Profili di Comunità</h1>
<p>Persone, gruppi, associazioni e imprese della città: chi sono e cosa fanno?  Tutto è organizzato per parole chiave così da facilitare la scoperta di contenuti che ti possono interessare.</p>'),
    t('Page'),
    t('Organizzazioni'),
    t('Cerca profilo'),
    t('Feed'),
    t('Block'),
    t('<h2>Profili</h2>
<p>Persone, gruppi, associazioni e imprese della città: chi sono e cosa fanno?</p>
<a href="profili" class="scopri">Elenco profili</a>'),
    t('[title]'),
  );
  $export['profili'] = $view;

  $view = new view();
  $view->name = 'progetti';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Progetti';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Progetti';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'altro';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Voci per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tutto -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Scostamento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« prima';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ precedente';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'seguente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'ultima »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Intestazione: Globale: Area di testo */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h1>I progetti di Comunità</h1>
<p>Visualizza tutti i progetti raccontati in Comunità e utilizza lo strumento di ricerca per trovare quello che cerchi.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Campo: Contenuto: Immagine */
  $handler->display->display_options['fields']['field_immagine_progetto']['id'] = 'field_immagine_progetto';
  $handler->display->display_options['fields']['field_immagine_progetto']['table'] = 'field_data_field_immagine_progetto';
  $handler->display->display_options['fields']['field_immagine_progetto']['field'] = 'field_immagine_progetto';
  $handler->display->display_options['fields']['field_immagine_progetto']['label'] = '';
  $handler->display->display_options['fields']['field_immagine_progetto']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_immagine_progetto']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_immagine_progetto']['settings'] = array(
    'image_style' => 'large',
    'image_link' => 'content',
  );
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Campo: Contenuto: Tag/Categorie */
  $handler->display->display_options['fields']['field_tag_categorie']['id'] = 'field_tag_categorie';
  $handler->display->display_options['fields']['field_tag_categorie']['table'] = 'field_data_field_tag_categorie';
  $handler->display->display_options['fields']['field_tag_categorie']['field'] = 'field_tag_categorie';
  $handler->display->display_options['fields']['field_tag_categorie']['label'] = '';
  $handler->display->display_options['fields']['field_tag_categorie']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tag_categorie']['alter']['text'] = '#[field_tag_categorie]';
  $handler->display->display_options['fields']['field_tag_categorie']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tag_categorie']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tag_categorie']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tag_categorie']['separator'] = ' ';
  /* Campo: Contenuto: Descrizione breve */
  $handler->display->display_options['fields']['field_descrizione_breve_progetto']['id'] = 'field_descrizione_breve_progetto';
  $handler->display->display_options['fields']['field_descrizione_breve_progetto']['table'] = 'field_data_field_descrizione_breve_progetto';
  $handler->display->display_options['fields']['field_descrizione_breve_progetto']['field'] = 'field_descrizione_breve_progetto';
  $handler->display->display_options['fields']['field_descrizione_breve_progetto']['label'] = '';
  $handler->display->display_options['fields']['field_descrizione_breve_progetto']['element_label_colon'] = FALSE;
  /* Criterio di ordinamento: Contenuto: Data di inserimento */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'progetto' => 'progetto',
  );
  /* Criterio del filtro: Contenuto: Stato Documento (field_stato_documento) */
  $handler->display->display_options['filters']['field_stato_documento_value']['id'] = 'field_stato_documento_value';
  $handler->display->display_options['filters']['field_stato_documento_value']['table'] = 'field_data_field_stato_documento';
  $handler->display->display_options['filters']['field_stato_documento_value']['field'] = 'field_stato_documento_value';
  $handler->display->display_options['filters']['field_stato_documento_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_stato_documento_value']['value'] = array(
    0 => '0',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Comportamento se non ci sono risultati: Globale: Area di testo */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Nessun risultato trovato.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relazione: Campo: Capacità (field_supporto_capacita) */
  $handler->display->display_options['relationships']['field_supporto_capacita_tid']['id'] = 'field_supporto_capacita_tid';
  $handler->display->display_options['relationships']['field_supporto_capacita_tid']['table'] = 'field_data_field_supporto_capacita';
  $handler->display->display_options['relationships']['field_supporto_capacita_tid']['field'] = 'field_supporto_capacita_tid';
  /* Relazione: Campo: Materiali (field_supporto_materiali) */
  $handler->display->display_options['relationships']['field_supporto_materiali_tid']['id'] = 'field_supporto_materiali_tid';
  $handler->display->display_options['relationships']['field_supporto_materiali_tid']['table'] = 'field_data_field_supporto_materiali';
  $handler->display->display_options['relationships']['field_supporto_materiali_tid']['field'] = 'field_supporto_materiali_tid';
  /* Relazione: Campo: Spazi (field_supporto_spazi) */
  $handler->display->display_options['relationships']['field_supporto_spazi_tid']['id'] = 'field_supporto_spazi_tid';
  $handler->display->display_options['relationships']['field_supporto_spazi_tid']['table'] = 'field_data_field_supporto_spazi';
  $handler->display->display_options['relationships']['field_supporto_spazi_tid']['field'] = 'field_supporto_spazi_tid';
  /* Relazione: Campo: Strumenti (field_supporto_strumenti) */
  $handler->display->display_options['relationships']['field_supporto_strumenti_tid']['id'] = 'field_supporto_strumenti_tid';
  $handler->display->display_options['relationships']['field_supporto_strumenti_tid']['table'] = 'field_data_field_supporto_strumenti';
  $handler->display->display_options['relationships']['field_supporto_strumenti_tid']['field'] = 'field_supporto_strumenti_tid';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'progetto' => 'progetto',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Criterio del filtro: Contenuto: Titolo */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Cerca progetto';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Criterio del filtro: Workflow current: Current state */
  $handler->display->display_options['filters']['sid']['id'] = 'sid';
  $handler->display->display_options['filters']['sid']['table'] = 'workflow_node_current';
  $handler->display->display_options['filters']['sid']['field'] = 'sid';
  $handler->display->display_options['filters']['sid']['group'] = 1;
  $handler->display->display_options['filters']['sid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sid']['expose']['operator_id'] = 'sid_op';
  $handler->display->display_options['filters']['sid']['expose']['label'] = 'Stato';
  $handler->display->display_options['filters']['sid']['expose']['operator'] = 'sid_op';
  $handler->display->display_options['filters']['sid']['expose']['identifier'] = 'sid';
  $handler->display->display_options['filters']['sid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['sid']['expose']['workflow_reduce_wid'] = '1';
  /* Criterio del filtro: Contenuto: Tag/Categorie (field_tag_categorie) */
  $handler->display->display_options['filters']['field_tag_categorie_tid']['id'] = 'field_tag_categorie_tid';
  $handler->display->display_options['filters']['field_tag_categorie_tid']['table'] = 'field_data_field_tag_categorie';
  $handler->display->display_options['filters']['field_tag_categorie_tid']['field'] = 'field_tag_categorie_tid';
  $handler->display->display_options['filters']['field_tag_categorie_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tag_categorie_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tag_categorie_tid']['expose']['operator_id'] = 'field_tag_categorie_tid_op';
  $handler->display->display_options['filters']['field_tag_categorie_tid']['expose']['label'] = 'Ricerca per tag';
  $handler->display->display_options['filters']['field_tag_categorie_tid']['expose']['operator'] = 'field_tag_categorie_tid_op';
  $handler->display->display_options['filters']['field_tag_categorie_tid']['expose']['identifier'] = 'field_tag_categorie_tid';
  $handler->display->display_options['filters']['field_tag_categorie_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_tag_categorie_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tag_categorie_tid']['vocabulary'] = 'tags';
  /* Criterio del filtro: Contenuto: Stato Documento (field_stato_documento) */
  $handler->display->display_options['filters']['field_stato_documento_value']['id'] = 'field_stato_documento_value';
  $handler->display->display_options['filters']['field_stato_documento_value']['table'] = 'field_data_field_stato_documento';
  $handler->display->display_options['filters']['field_stato_documento_value']['field'] = 'field_stato_documento_value';
  $handler->display->display_options['filters']['field_stato_documento_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_stato_documento_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['path'] = 'progetti';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'progetti.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Intestazione: Globale: Area di testo */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Progetti</h2>
<p>Quali sono e cosa fanno i progetti collaborativi?</p>
<a href="progetti" class="scopri">Elenco progetti</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Contenuto: Immagine */
  $handler->display->display_options['fields']['field_immagine_progetto']['id'] = 'field_immagine_progetto';
  $handler->display->display_options['fields']['field_immagine_progetto']['table'] = 'field_data_field_immagine_progetto';
  $handler->display->display_options['fields']['field_immagine_progetto']['field'] = 'field_immagine_progetto';
  $handler->display->display_options['fields']['field_immagine_progetto']['label'] = '';
  $handler->display->display_options['fields']['field_immagine_progetto']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_immagine_progetto']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_immagine_progetto']['settings'] = array(
    'image_style' => 'large',
    'image_link' => 'content',
  );
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Campo: Contenuto: Tag/Categorie */
  $handler->display->display_options['fields']['field_tag_categorie']['id'] = 'field_tag_categorie';
  $handler->display->display_options['fields']['field_tag_categorie']['table'] = 'field_data_field_tag_categorie';
  $handler->display->display_options['fields']['field_tag_categorie']['field'] = 'field_tag_categorie';
  $handler->display->display_options['fields']['field_tag_categorie']['label'] = '';
  $handler->display->display_options['fields']['field_tag_categorie']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tag_categorie']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tag_categorie']['alter']['text'] = '#[field_tag_categorie] ';
  $handler->display->display_options['fields']['field_tag_categorie']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tag_categorie']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tag_categorie']['separator'] = '';
  /* Campo: Globale: Testo personalizzato */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title]
[field_tag_categorie]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $translatables['progetti'] = array(
    t('Master'),
    t('Progetti'),
    t('altro'),
    t('Applica'),
    t('Ripristina'),
    t('Ordina per'),
    t('Asc'),
    t('Disc'),
    t('Voci per pagina'),
    t('- Tutto -'),
    t('Scostamento'),
    t('« prima'),
    t('‹ precedente'),
    t('seguente ›'),
    t('ultima »'),
    t('<h1>I progetti di Comunità</h1>
<p>Visualizza tutti i progetti raccontati in Comunità e utilizza lo strumento di ricerca per trovare quello che cerchi.</p>'),
    t('#[field_tag_categorie]'),
    t('Page'),
    t('Nessun risultato trovato.'),
    t('termine da field_supporto_capacita'),
    t('termine da field_supporto_materiali'),
    t('termine da field_supporto_spazi'),
    t('termine da field_supporto_strumenti'),
    t('Cerca progetto'),
    t('Stato'),
    t('Ricerca per tag'),
    t('Feed'),
    t('Block'),
    t('<h2>Progetti</h2>
<p>Quali sono e cosa fanno i progetti collaborativi?</p>
<a href="progetti" class="scopri">Elenco progetti</a>'),
    t('#[field_tag_categorie] '),
    t('[title]
[field_tag_categorie]'),
  );
  $export['progetti'] = $view;

  $view = new view();
  $view->name = 'progetti_proposti_organizzazione';
  $view->description = 'Show all content (nodes) of a group.';
  $view->tag = 'og';
  $view->base_table = 'node';
  $view->human_name = 'Progetti proposti Organizzazione';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Progetti Proposti';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'altro';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Voci per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tutto -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Scostamento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« prima';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ precedente';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'seguente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'ultima »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'elenco_profili';
  /* Comportamento se non ci sono risultati: Globale: Area di testo */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Nessun contenuto recente.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Criterio di ordinamento: Contenuto: Data di inserimento */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'progetto' => 'progetto',
  );

  /* Display: Blocco */
  $handler = $view->new_display('block', 'Blocco', 'block_1');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relazione: OG membership: OG membership from Nodo */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtro contestuale: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['gid']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  $handler->display->display_options['arguments']['gid']['validate']['fail'] = 'empty';
  $handler->display->display_options['block_description'] = 'Post recenti Organizzazione';

  /* Display: Blocco Utente */
  $handler = $view->new_display('block', 'Blocco Utente', 'block_2');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtro contestuale: Contenuto: Identificativo uid dell'autore */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'empty';

  /* Display: Blocco Pagina Partecipa */
  $handler = $view->new_display('block', 'Blocco Pagina Partecipa', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Progetti che cercano supporto';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Intestazione: Globale: Area di testo */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Puoi offrire il tuo aiuto ai progetti che cercano supporto (capacità, materiali, spazi e strumenti). Di seguito li trovi elencati in ordine di pubblicazione.

';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relazione: Campo: Capacità (field_supporto_capacita) */
  $handler->display->display_options['relationships']['field_supporto_capacita_tid']['id'] = 'field_supporto_capacita_tid';
  $handler->display->display_options['relationships']['field_supporto_capacita_tid']['table'] = 'field_data_field_supporto_capacita';
  $handler->display->display_options['relationships']['field_supporto_capacita_tid']['field'] = 'field_supporto_capacita_tid';
  /* Relazione: Campo: Materiali (field_supporto_materiali) */
  $handler->display->display_options['relationships']['field_supporto_materiali_tid']['id'] = 'field_supporto_materiali_tid';
  $handler->display->display_options['relationships']['field_supporto_materiali_tid']['table'] = 'field_data_field_supporto_materiali';
  $handler->display->display_options['relationships']['field_supporto_materiali_tid']['field'] = 'field_supporto_materiali_tid';
  /* Relazione: Campo: Spazi (field_supporto_spazi) */
  $handler->display->display_options['relationships']['field_supporto_spazi_tid']['id'] = 'field_supporto_spazi_tid';
  $handler->display->display_options['relationships']['field_supporto_spazi_tid']['table'] = 'field_data_field_supporto_spazi';
  $handler->display->display_options['relationships']['field_supporto_spazi_tid']['field'] = 'field_supporto_spazi_tid';
  /* Relazione: Campo: Strumenti (field_supporto_strumenti) */
  $handler->display->display_options['relationships']['field_supporto_strumenti_tid']['id'] = 'field_supporto_strumenti_tid';
  $handler->display->display_options['relationships']['field_supporto_strumenti_tid']['table'] = 'field_data_field_supporto_strumenti';
  $handler->display->display_options['relationships']['field_supporto_strumenti_tid']['field'] = 'field_supporto_strumenti_tid';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'progetto' => 'progetto',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Criterio del filtro: Campo: Spazi (field_supporto_spazi) */
  $handler->display->display_options['filters']['field_supporto_spazi_tid']['id'] = 'field_supporto_spazi_tid';
  $handler->display->display_options['filters']['field_supporto_spazi_tid']['table'] = 'field_data_field_supporto_spazi';
  $handler->display->display_options['filters']['field_supporto_spazi_tid']['field'] = 'field_supporto_spazi_tid';
  $handler->display->display_options['filters']['field_supporto_spazi_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_supporto_spazi_tid']['value'] = '';
  $handler->display->display_options['filters']['field_supporto_spazi_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_supporto_spazi_tid']['vocabulary'] = 'spazi';
  /* Criterio del filtro: Campo: Strumenti (field_supporto_strumenti) */
  $handler->display->display_options['filters']['field_supporto_strumenti_tid']['id'] = 'field_supporto_strumenti_tid';
  $handler->display->display_options['filters']['field_supporto_strumenti_tid']['table'] = 'field_data_field_supporto_strumenti';
  $handler->display->display_options['filters']['field_supporto_strumenti_tid']['field'] = 'field_supporto_strumenti_tid';
  $handler->display->display_options['filters']['field_supporto_strumenti_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_supporto_strumenti_tid']['value'] = '';
  $handler->display->display_options['filters']['field_supporto_strumenti_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_supporto_strumenti_tid']['vocabulary'] = 'strumenti_def';
  /* Criterio del filtro: Campo: Materiali (field_supporto_materiali) */
  $handler->display->display_options['filters']['field_supporto_materiali_tid']['id'] = 'field_supporto_materiali_tid';
  $handler->display->display_options['filters']['field_supporto_materiali_tid']['table'] = 'field_data_field_supporto_materiali';
  $handler->display->display_options['filters']['field_supporto_materiali_tid']['field'] = 'field_supporto_materiali_tid';
  $handler->display->display_options['filters']['field_supporto_materiali_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_supporto_materiali_tid']['value'] = '';
  $handler->display->display_options['filters']['field_supporto_materiali_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_supporto_materiali_tid']['vocabulary'] = 'materiali';
  /* Criterio del filtro: Campo: Capacità (field_supporto_capacita) */
  $handler->display->display_options['filters']['field_supporto_capacita_tid']['id'] = 'field_supporto_capacita_tid';
  $handler->display->display_options['filters']['field_supporto_capacita_tid']['table'] = 'field_data_field_supporto_capacita';
  $handler->display->display_options['filters']['field_supporto_capacita_tid']['field'] = 'field_supporto_capacita_tid';
  $handler->display->display_options['filters']['field_supporto_capacita_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_supporto_capacita_tid']['value'] = '';
  $handler->display->display_options['filters']['field_supporto_capacita_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_supporto_capacita_tid']['vocabulary'] = 'capacita';

  /* Display: Blocco Utente */
  $handler = $view->new_display('block', 'Blocco Utente', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Progetti non pubblicati';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtro contestuale: Contenuto: Identificativo uid dell'autore */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'progetto' => 'progetto',
  );
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';

  /* Display: Blocco Utente */
  $handler = $view->new_display('block', 'Blocco Utente', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Progetti da revisionare';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relazione: Contenuto: Autore */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Campo: Campo: Cognome */
  $handler->display->display_options['fields']['field_cognome']['id'] = 'field_cognome';
  $handler->display->display_options['fields']['field_cognome']['table'] = 'field_data_field_cognome';
  $handler->display->display_options['fields']['field_cognome']['field'] = 'field_cognome';
  $handler->display->display_options['fields']['field_cognome']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_cognome']['label'] = '';
  $handler->display->display_options['fields']['field_cognome']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cognome']['element_label_colon'] = FALSE;
  /* Campo: Campo: Nome */
  $handler->display->display_options['fields']['field_nome']['id'] = 'field_nome';
  $handler->display->display_options['fields']['field_nome']['table'] = 'field_data_field_nome';
  $handler->display->display_options['fields']['field_nome']['field'] = 'field_nome';
  $handler->display->display_options['fields']['field_nome']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_nome']['label'] = '';
  $handler->display->display_options['fields']['field_nome']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_nome']['element_label_colon'] = FALSE;
  /* Campo: Contenuto: Identificativo uid dell'autore */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Autore';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[field_nome] [field_cognome] ';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtro contestuale: Contenuto: Identificativo uid dell'autore */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'progetto' => 'progetto',
  );
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $translatables['progetti_proposti_organizzazione'] = array(
    t('Defaults'),
    t('Progetti Proposti'),
    t('altro'),
    t('Applica'),
    t('Ripristina'),
    t('Ordina per'),
    t('Asc'),
    t('Disc'),
    t('Voci per pagina'),
    t('- Tutto -'),
    t('Scostamento'),
    t('« prima'),
    t('‹ precedente'),
    t('seguente ›'),
    t('ultima »'),
    t('Nessun contenuto recente.'),
    t('Blocco'),
    t('OG membership from node'),
    t('Tutti'),
    t('Post recenti Organizzazione'),
    t('Blocco Utente'),
    t('Blocco Pagina Partecipa'),
    t('Progetti che cercano supporto'),
    t('Puoi offrire il tuo aiuto ai progetti che cercano supporto (capacità, materiali, spazi e strumenti). Di seguito li trovi elencati in ordine di pubblicazione.

'),
    t('termine da field_supporto_capacita'),
    t('termine da field_supporto_materiali'),
    t('termine da field_supporto_spazi'),
    t('termine da field_supporto_strumenti'),
    t('Progetti non pubblicati'),
    t('Progetti da revisionare'),
    t('autore'),
    t('Titolo'),
    t('Autore'),
    t('[field_nome] [field_cognome] '),
  );
  $export['progetti_proposti_organizzazione'] = $view;

  $view = new view();
  $view->name = 'proposte';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Proposte';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Visualizza le proposte';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'altro';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Voci per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tutto -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Scostamento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« prima';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ precedente';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'seguente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'ultima »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Campo: Contenuto: Titolo */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Criterio di ordinamento: Contenuto: Data di inserimento */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtro contestuale: Contenuto: Consultazione collegata (field_consultazione) */
  $handler->display->display_options['arguments']['field_consultazione_target_id']['id'] = 'field_consultazione_target_id';
  $handler->display->display_options['arguments']['field_consultazione_target_id']['table'] = 'field_data_field_consultazione';
  $handler->display->display_options['arguments']['field_consultazione_target_id']['field'] = 'field_consultazione_target_id';
  $handler->display->display_options['arguments']['field_consultazione_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_consultazione_target_id']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments']['field_consultazione_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_consultazione_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_consultazione_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_consultazione_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_consultazione_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_consultazione_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_consultazione_target_id']['validate_options']['types'] = array(
    'consultazione' => 'consultazione',
  );
  $handler->display->display_options['arguments']['field_consultazione_target_id']['validate']['fail'] = 'empty';
  /* Criterio del filtro: Contenuto: Pubblicato */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Contenuto: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'proposta' => 'proposta',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['proposte'] = array(
    t('Master'),
    t('Visualizza le proposte'),
    t('altro'),
    t('Applica'),
    t('Ripristina'),
    t('Ordina per'),
    t('Asc'),
    t('Disc'),
    t('Voci per pagina'),
    t('- Tutto -'),
    t('Scostamento'),
    t('« prima'),
    t('‹ precedente'),
    t('seguente ›'),
    t('ultima »'),
    t('Tutti'),
    t('Block'),
  );
  $export['proposte'] = $view;

  $view = new view();
  $view->name = 'segnalazioni';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'entityform';
  $view->human_name = 'Segnalazioni';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Segnalazioni';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'altro';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'list-group-item';
  $handler->display->display_options['style_options']['class'] = 'list-group';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relazione: Entityform Submission: Utente uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'entityform';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Campo: Entityform Submission: Segnalazione */
  $handler->display->display_options['fields']['field_segnalazione']['id'] = 'field_segnalazione';
  $handler->display->display_options['fields']['field_segnalazione']['table'] = 'field_data_field_segnalazione';
  $handler->display->display_options['fields']['field_segnalazione']['field'] = 'field_segnalazione';
  $handler->display->display_options['fields']['field_segnalazione']['label'] = '';
  $handler->display->display_options['fields']['field_segnalazione']['element_label_colon'] = FALSE;
  /* Campo: Utente: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'user';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  /* Campo: Campo: Cognome */
  $handler->display->display_options['fields']['field_cognome']['id'] = 'field_cognome';
  $handler->display->display_options['fields']['field_cognome']['table'] = 'field_data_field_cognome';
  $handler->display->display_options['fields']['field_cognome']['field'] = 'field_cognome';
  $handler->display->display_options['fields']['field_cognome']['relationship'] = 'user';
  $handler->display->display_options['fields']['field_cognome']['label'] = '';
  $handler->display->display_options['fields']['field_cognome']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cognome']['element_label_colon'] = FALSE;
  /* Campo: Campo: Nome */
  $handler->display->display_options['fields']['field_nome']['id'] = 'field_nome';
  $handler->display->display_options['fields']['field_nome']['table'] = 'field_data_field_nome';
  $handler->display->display_options['fields']['field_nome']['field'] = 'field_nome';
  $handler->display->display_options['fields']['field_nome']['relationship'] = 'user';
  $handler->display->display_options['fields']['field_nome']['label'] = '';
  $handler->display->display_options['fields']['field_nome']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_nome']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_nome']['alter']['text'] = '[field_nome] [field_cognome]';
  $handler->display->display_options['fields']['field_nome']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_nome']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_nome']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_nome']['empty'] = 'Anonimo';
  /* Campo: Campo: Groups audience */
  $handler->display->display_options['fields']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['label'] = '';
  $handler->display->display_options['fields']['og_group_ref']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['og_group_ref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['og_group_ref']['empty'] = '[field_nome]';
  $handler->display->display_options['fields']['og_group_ref']['settings'] = array(
    'link' => 1,
  );
  /* Filtro contestuale: Entityform Submission: Utente (field_utente_segnala) */
  $handler->display->display_options['arguments']['field_utente_segnala_target_id']['id'] = 'field_utente_segnala_target_id';
  $handler->display->display_options['arguments']['field_utente_segnala_target_id']['table'] = 'field_data_field_utente_segnala';
  $handler->display->display_options['arguments']['field_utente_segnala_target_id']['field'] = 'field_utente_segnala_target_id';
  $handler->display->display_options['arguments']['field_utente_segnala_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_utente_segnala_target_id']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments']['field_utente_segnala_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_utente_segnala_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_utente_segnala_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_utente_segnala_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_utente_segnala_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_utente_segnala_target_id']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['field_utente_segnala_target_id']['validate']['fail'] = 'empty';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Blocco Utente */
  $handler = $view->new_display('block', 'Blocco Utente', 'block_1');

  /* Display: Blocco Organizzazione */
  $handler = $view->new_display('block', 'Blocco Organizzazione', 'block_2');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtro contestuale: Entityform Submission: Organizzazione (field_org_segnala) */
  $handler->display->display_options['arguments']['field_org_segnala_target_id']['id'] = 'field_org_segnala_target_id';
  $handler->display->display_options['arguments']['field_org_segnala_target_id']['table'] = 'field_data_field_org_segnala';
  $handler->display->display_options['arguments']['field_org_segnala_target_id']['field'] = 'field_org_segnala_target_id';
  $handler->display->display_options['arguments']['field_org_segnala_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_org_segnala_target_id']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments']['field_org_segnala_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_org_segnala_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_org_segnala_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_org_segnala_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_org_segnala_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_org_segnala_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_org_segnala_target_id']['validate_options']['types'] = array(
    'organizzazione' => 'organizzazione',
  );
  $handler->display->display_options['arguments']['field_org_segnala_target_id']['validate']['fail'] = 'empty';

  /* Display: Blocco Progetto */
  $handler = $view->new_display('block', 'Blocco Progetto', 'block_3');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtro contestuale: Entityform Submission: Progetto (field_progetto_segnala) */
  $handler->display->display_options['arguments']['field_progetto_segnala_target_id']['id'] = 'field_progetto_segnala_target_id';
  $handler->display->display_options['arguments']['field_progetto_segnala_target_id']['table'] = 'field_data_field_progetto_segnala';
  $handler->display->display_options['arguments']['field_progetto_segnala_target_id']['field'] = 'field_progetto_segnala_target_id';
  $handler->display->display_options['arguments']['field_progetto_segnala_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_progetto_segnala_target_id']['exception']['title'] = 'Tutti';
  $handler->display->display_options['arguments']['field_progetto_segnala_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_progetto_segnala_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_progetto_segnala_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_progetto_segnala_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_progetto_segnala_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_progetto_segnala_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_progetto_segnala_target_id']['validate_options']['types'] = array(
    'progetto' => 'progetto',
  );
  $handler->display->display_options['arguments']['field_progetto_segnala_target_id']['validate']['fail'] = 'empty';
  $translatables['segnalazioni'] = array(
    t('Master'),
    t('Segnalazioni'),
    t('altro'),
    t('Applica'),
    t('Ripristina'),
    t('Ordina per'),
    t('Asc'),
    t('Disc'),
    t('Utente'),
    t('[field_nome] [field_cognome]'),
    t('Anonimo'),
    t('[field_nome]'),
    t('Tutti'),
    t('Block'),
    t('Blocco Utente'),
    t('Blocco Organizzazione'),
    t('Blocco Progetto'),
  );
  $export['segnalazioni'] = $view;

  $view = new view();
  $view->name = 'users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Profili';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Profili';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'altro';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Applica';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Ripristina';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordina per';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Disc';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '48';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Voci per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tutto -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Scostamento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« prima';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ precedente';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'seguente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'ultima »';
  $handler->display->display_options['style_plugin'] = 'masonry_views';
  $handler->display->display_options['style_options']['masonry_gutter_width'] = '';
  $handler->display->display_options['style_options']['masonry_resizable'] = TRUE;
  $handler->display->display_options['style_options']['masonry_animated'] = TRUE;
  $handler->display->display_options['style_options']['masonry_fit_width'] = TRUE;
  $handler->display->display_options['style_options']['masonry_rtl'] = FALSE;
  $handler->display->display_options['style_options']['masonry_images_first'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Intestazione: Globale: Area di testo */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h1>Profili di Comunità</h1>
<p>Persone, gruppi, associazioni e imprese della città: chi sono e cosa fanno?  Tutto è organizzato per parole chiave così da facilitare la scoperta di contenuti che ti possono interessare.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Campo: Utente: Avatar */
  $handler->display->display_options['fields']['field_avatar']['id'] = 'field_avatar';
  $handler->display->display_options['fields']['field_avatar']['table'] = 'field_data_field_avatar';
  $handler->display->display_options['fields']['field_avatar']['field'] = 'field_avatar';
  $handler->display->display_options['fields']['field_avatar']['label'] = '';
  $handler->display->display_options['fields']['field_avatar']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_avatar']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_avatar']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_avatar']['settings'] = array(
    'image_style' => 'profili',
    'image_link' => 'content',
  );
  /* Campo: Utente: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Campo: Campo: Nome */
  $handler->display->display_options['fields']['field_nome']['id'] = 'field_nome';
  $handler->display->display_options['fields']['field_nome']['table'] = 'field_data_field_nome';
  $handler->display->display_options['fields']['field_nome']['field'] = 'field_nome';
  $handler->display->display_options['fields']['field_nome']['label'] = '';
  $handler->display->display_options['fields']['field_nome']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_nome']['element_label_colon'] = FALSE;
  /* Campo: Campo: Cognome */
  $handler->display->display_options['fields']['field_cognome']['id'] = 'field_cognome';
  $handler->display->display_options['fields']['field_cognome']['table'] = 'field_data_field_cognome';
  $handler->display->display_options['fields']['field_cognome']['field'] = 'field_cognome';
  $handler->display->display_options['fields']['field_cognome']['label'] = '';
  $handler->display->display_options['fields']['field_cognome']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cognome']['element_label_colon'] = FALSE;
  /* Campo: Utente: Ritratto */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '[field_avatar]';
  $handler->display->display_options['fields']['picture']['image_style'] = 'profili';
  /* Campo: Utente: Nome */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[field_nome] [field_cognome]';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Campo: Utente: Una frase per raccontarti */
  $handler->display->display_options['fields']['field_statement']['id'] = 'field_statement';
  $handler->display->display_options['fields']['field_statement']['table'] = 'field_data_field_statement';
  $handler->display->display_options['fields']['field_statement']['field'] = 'field_statement';
  $handler->display->display_options['fields']['field_statement']['label'] = '';
  $handler->display->display_options['fields']['field_statement']['element_label_colon'] = FALSE;
  /* Criterio di ordinamento: Utente: Data creazione */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Criterio del filtro: Utente: Attivo */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Criterio del filtro: Utente: Ruoli */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['operator'] = 'not';
  $handler->display->display_options['filters']['rid']['value'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['filters']['rid']['group'] = 1;
  /* Criterio del filtro: Campo: Nome (field_nome) */
  $handler->display->display_options['filters']['field_nome_value_1']['id'] = 'field_nome_value_1';
  $handler->display->display_options['filters']['field_nome_value_1']['table'] = 'field_data_field_nome';
  $handler->display->display_options['filters']['field_nome_value_1']['field'] = 'field_nome_value';
  $handler->display->display_options['filters']['field_nome_value_1']['operator'] = 'not empty';
  /* Criterio del filtro: Globale: Combina filtri dei campi */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Cerca profilo';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_nome' => 'field_nome',
    'field_cognome' => 'field_cognome',
  );
  /* Criterio del filtro: Utente: L'ID dell'utente */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '!=';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '386';
  /* Criterio del filtro: Utente: Accetto e sottoscrivo la Carta di Comunità (field_carta_com) */
  $handler->display->display_options['filters']['field_carta_com_value']['id'] = 'field_carta_com_value';
  $handler->display->display_options['filters']['field_carta_com_value']['table'] = 'field_data_field_carta_com';
  $handler->display->display_options['filters']['field_carta_com_value']['field'] = 'field_carta_com_value';
  $handler->display->display_options['filters']['field_carta_com_value']['value'] = array(
    1 => '1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'profili';
  $translatables['users'] = array(
    t('Master'),
    t('Profili'),
    t('altro'),
    t('Applica'),
    t('Ripristina'),
    t('Ordina per'),
    t('Asc'),
    t('Disc'),
    t('Voci per pagina'),
    t('- Tutto -'),
    t('Scostamento'),
    t('« prima'),
    t('‹ precedente'),
    t('seguente ›'),
    t('ultima »'),
    t('<h1>Profili di Comunità</h1>
<p>Persone, gruppi, associazioni e imprese della città: chi sono e cosa fanno?  Tutto è organizzato per parole chiave così da facilitare la scoperta di contenuti che ti possono interessare.</p>'),
    t('[field_avatar]'),
    t('[field_nome] [field_cognome]'),
    t('Cerca profilo'),
    t('Page'),
  );
  $export['users'] = $view;

  return $export;
}
