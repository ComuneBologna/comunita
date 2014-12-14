<?php global $user; ?>
<article<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
  <header>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  
  <div<?php print $content_attributes; ?>>
   <div class="row">
    <div class="col-sm-6">
      <?php if($node->uid == $user->uid): ?>
        <?php if($node->field_stato_documento[LANGUAGE_NONE][0]['value'] == 0): ?>
        <div class="alert alert-warning alert-dismissible">
          <button type="button" class="close" data-dismiss="alert"><span aria-hidden="true">&times;</span><span class="sr-only">Chiudi</span></button>
          Lo stato attuale del tuo progetto è: <strong>BOZZA</strong>
        </div>
        <?php elseif($node->field_stato_documento[LANGUAGE_NONE][0]['value'] == 1): ?>
        <div class="alert alert-info alert-dismissible">
          <button type="button" class="close" data-dismiss="alert"><span aria-hidden="true">&times;</span><span class="sr-only">Chiudi</span></button>
          Lo stato attuale del tuo progetto è: <strong>INVIATO</strong>
        </div>
        <?php elseif($node->field_stato_documento[LANGUAGE_NONE][0]['value'] == 2): ?>
        <div class="alert alert-success alert-dismissible">
          <button type="button" class="close" data-dismiss="alert"><span aria-hidden="true">&times;</span><span class="sr-only">Chiudi</span></button>
          Lo stato attuale del tuo progetto è: <strong>PUBBLICATO</strong>
        </div>
      <?php endif; ?>
      <?php endif; ?>
      <div class="panel panel-notitle">
        <div class="panel-body">
          <?php //print render($content['field_stato']); ?>
          <?php if(!empty($field_bene_intervento)): ?>
          <div class="bene_comune">Bene Comune</div>
          <?php endif; ?>
          <div class="row">
            <div class="col-sm-4">
              <?php print render($content['field_immagine_progetto']) ?>
            </div>
            <div class="col-sm-8">
              <div class="profile-title">
                <h1><?php print $title ; ?></h1>
              </div>
              <div class="row">
                <div class="col-sm-12">
                  <?php
                    print render($content['field_link_pagina_esterna']);
                    print render($content['og_group_ref']);
                  ?>
                </div>
              </div>
            </div>
          </div>
          <div class="row">
            <div class="col-sm-12">
              <?php foreach($field_tag_categorie as $tag): ?>
               <?php print comunita_progetti_taxonomy_term_uri(taxonomy_term_load($tag['tid'])); ?>
              <?php endforeach; ?>
            </div>
            <div class="col-sm-12 progetto-action">
              <p>Segui o partecipa al progetto.</p>
              <?php if(isset($content['links']['flag'])): ?>
                <?php print render($content['links']['flag']); ?>
              <?php elseif($user->uid == 0): ?>
                <a href="/comunita/cas" class="flag-register">Accedi per seguire</a>
              <?php endif;?>
              <div class="segnala"><?php print l('<span class="glyphicon glyphicon-exclamation-sign"></span> Segnala questo progetto', 'segnala-progetto', array('html' => true, 'query' => array('field_progetto_segnala' => $node->nid))); ?></div>
            </div>
            <?php if(in_array('redazione', $user->roles) || in_array('administrator', $user->roles)): ?>
            <div class="col-sm-12 progetto-action action-links">
              <p>Area redazionale</p>
              <?php print l('Crea patto di collaborazione', 'node/add/patto-di-collaborazione', array('query' => array('field_contenuto_collegato' => $node->nid))); ?>
            </div>
            <?php endif; ?>
          </div>
        </div>
      </div>
      
      <?php if(isset($content['field_tipologia_progetto']) || isset($content['field_area_tematica'])): ?>
      <div class="panel panel-title-small">
        <div class="row">
          <div class="col-sm-6">
            <div class="panel-heading">
              <h2 class="panel-title"><?php print t('Tipologia'); ?></h2>
            </div>
            <div class="panel-body">
              <?php print render($content['field_tipologia_progetto']); ?>
            </div>
          </div>
          <div class="col-sm-6">
            <div class="panel-heading">
              <h2 class="panel-title"><?php print t('Area tematica'); ?></h2>
            </div>
            <div class="panel-body">
              <?php print render($content['field_area_tematica']); ?>
            </div>
          </div>
        </div>
      </div>
      <?php endif; ?>
      
      <?php if(isset($content['field_descrizione_breve_progetto'])): ?>
      <div class="panel">
        <div class="panel-heading">
          <h2 class="panel-title"><?php print t('Descrizione breve'); ?></h2>
        </div>
        <div class="panel-body">
          <?php print render($content['field_descrizione_breve_progetto']); ?>
        </div>
      </div>
      <?php endif; ?>
      
      <?php if(isset($content['field_obiettivo_piano'])): ?>
      <div class="panel">
        <div class="panel-heading">
          <h2 class="panel-title"><?php print t('Obiettivo e Piano Attività'); ?></h2>
        </div>
        <div class="panel-body">
          <?php print render($content['field_obiettivo_piano']); ?>
        </div>
        <?php if(isset($content['field_allegati_obiettivo'])): ?>
        <div class="panel-footer">
          <?php print render($content['field_allegati_obiettivo']); ?>
        </div>
        <?php endif; ?>
      </div>
      <?php endif; ?>

      <?php if(isset($content['field_interesse_collettivo'])): ?>
      <div class="panel">
        <div class="panel-heading">
          <h2 class="panel-title"><?php print t('Perché è di interesse collettivo'); ?></h2>
        </div>
        <div class="panel-body">
          <?php print render($content['field_interesse_collettivo']); ?>
        </div>
      </div>
      <?php endif; ?>
    </div>
    
    <div class="col-sm-6">
      <?php
        if(!empty($field_dove_progetto[LANGUAGE_NONE][0]['locality'])) {
          print render($content['field_geo']);
        }
      ?>
      
      <?php if(isset($content['field_bene_intervento']) || $content['field_bene_comune_collegato']): ?>
      <div class="panel">
        <div class="panel-heading">
          <h2 class="panel-title"><?php print t('Bene Comune oggetto di intervento'); ?></h2>
        </div>
        <div class="panel-body">
          <?php print render($content['field_bene_intervento']); ?>
          <?php print render($content['field_bene_comune_collegato']); ?>
        </div>
        <?php if(isset($content['field_allegati_bene_oggetto'])): ?>
        <div class="panel-footer">
          <?php print render($content['field_allegati_bene_oggetto']); ?>
        </div>
        <?php endif; ?>
      </div>
      <?php endif; ?>
      
      <?php if(isset($content['field_strumento_finanziamento'])): ?>
      <div class="panel">
        <div class="panel-heading">
          <h2 class="panel-title"><?php print t('Strumento di finanziamento'); ?></h2>
        </div>
        <div class="panel-body">
          <?php print render($content['field_strumento_finanziamento']) ?>
        </div>
      </div>
      <?php endif; ?>
      
      <?php if(isset($content['field_patrocinio'])): ?>
      <div class="panel">
        <div class="panel-heading">
          <h2 class="panel-title"><?php print t('Patrocinio'); ?></h2>
        </div>
        <div class="panel-body">
          <?php print render($content['field_patrocinio']) ?>
        </div>
      </div>
      <?php endif; ?>
      
      <?php if(isset($content['field_supporto_capacita']) || $content['field_supporto_strumenti'] || $content['field_supporto_materiali'] || $content['field_supporto_spazi']): ?>
      <div class="panel">
        <div class="panel-heading">
          <h2 class="panel-title"><?php print t('Supporto richiesto'); ?></h2>
        </div>
        <div class="panel-body">
          <?php print render($content['field_supporto_capacita']); ?>
          <?php print render($content['field_supporto_strumenti']); ?>
          <?php print render($content['field_supporto_materiali']); ?>
          <?php print render($content['field_supporto_spazi']); ?>
        </div>
      </div>
      <?php endif; ?>
      
      <?php if(isset($content['field_data_avvio'])): ?>
      <div class="panel panel-title-small">
        <div class="row">
          <div class="col-sm-3">
            <div class="panel-heading">
              <h2 class="panel-title"><?php print t('Avvio'); ?></h2>
            </div>
            <div class="panel-body">
              <?php print render($content['field_data_avvio']) ?>
            </div>
          </div>
          <div class="col-sm-3">
            <div class="panel-heading">
              <h2 class="panel-title"><?php print t('Chiusura'); ?></h2>
            </div>
            <div class="panel-body">
              <?php print render($content['field_data_chiusura']) ?>
            </div>
          </div>
          <div class="col-sm-6">
            <div class="panel-heading">
              <h2 class="panel-title"><?php print t('Rendicontazione'); ?></h2>
            </div>
            <div class="panel-body">
              <?php print render($content['field_momento_rendicontazione']) ?>
            </div>
          </div>
        </div>
      </div>
      <?php endif; ?>
        
      <?php if(isset($content['field_risorse_impiegate'])): ?>
      <div class="panel">
        <div class="panel-heading">
          <h2 class="panel-title"><?php print t('Risorse impiegate / pianificate'); ?></h2>
        </div>
        <div class="panel-body">
          <?php print render($content['field_risorse_impiegate']) ?>
        </div>
        <?php if(isset($content['field_allegati_risorse_impiegate'])): ?>
        <div class="panel-footer">
          <?php print render($content['field_allegati_risorse_impiegate']); ?>
        </div>
        <?php endif; ?>
      </div>
      <?php endif; ?>
      
      <?php if(!empty($content['comments'])): ?>
      <div class="panel panel-comments">
        <div class="panel-heading">
          <h2>Commenti</h2>
        </div>
        <div class="panel-body">
          <?php print render($content['comments']); ?>
        </div>
      </div>
      <?php endif; ?>
      
      <?php
        $view = views_get_view('segnalazioni');
        $view->set_display('block_3');
        $view->set_arguments(array($node->nid));
        $view->pre_execute();
        $view->execute();
        if (!empty($view->result)) :
      ?>
      <div class="panel">
        <div class="panel-heading">
          <h2 class="panel-title"><?php print $view->get_title() ?></h2>
        </div>
        <div class="panel-body">
          <?php print $view->preview(); ?>
        </div>
      </div>
      <?php endif; $view->destroy();?>
      
    </div>
  </div>
  </div>
</article>