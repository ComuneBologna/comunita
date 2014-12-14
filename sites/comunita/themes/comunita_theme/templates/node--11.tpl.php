<?php global $user, $base_url; ?>
<article<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
  <header>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  
  <div class="row">
    <div class="col-sm-12">
      <div class="panel panel-info panel-intro-page">
        <div class="col-sm-6 intro-img">
          <img src="<?php print $base_url . '/' . path_to_theme(); ?>/images/collaborareebologna.png" style="margin: 0" />
        </div>
        <div class="col-sm-6">
          <div class="panel-heading">
            <h1><?php print $title ; ?></h1>
          </div>
          <div class="panel-body">
            <?php print render($content['body']); ?>
          </div>
        </div>
      </div>
    </div>
    
    <div class="col-sm-6">
      <div class="panel">
        <div class="panel-heading panel-heading-blue">
          <h2 class="panel-title"><img src="<?php print $base_url . '/' . path_to_theme(); ?>/images/partecipa_bandi-e-avvisi.png" /> <?php print t('Bandi e avvisi'); ?></h2>
        </div>
        <div class="panel-body">
          <p><?php print t('Consulta gli avvisi pubblici e i bandi di interesse collettivo pubblicati da enti e altre organizzazioni.'); ?></p>
        </div>
      </div>
      
      <div class="panel prenditicura panel-odd">
        <div class="panel-heading">
          <h2 class="panel-title"><img src="<?php print $base_url . '/' . path_to_theme(); ?>/images/partecipa_salva-beni-comuni.png" /> <?php print t('La cura dei Beni Comuni') ?></h2>
          <p><?php print t('Il Comune di Bologna promuove l’impegno di tutti per la cura e la gestione dei beni comuni. '); ?></p>
          <?php print l('Vai alla sezione Beni Comuni »', 'beni-comuni', array('attributes' => array('class' => array('scopri')))) ?>
        </div>
        <div class="panel-body">
          <div class="row row-border">
            <p><?php print t("Puoi presentare una 'proposta spontanea' oppure impiegare una delle ipotesi tipiche di collaborazione."); ?></p>
            <a class="scopri scopri-tipico" href="vandalismo-grafico">Rimozione Vandalismo Grafico</a>
            <a class="scopri scopri-tipico" href="cura-beni-comuni">Proposte per la cura e la rigenerazione dei beni comuni</a>
          </div>
        </div>
      </div>
    </div>
    
    <div class="col-sm-6">
      <div class="panel">
        <div class="panel-heading panel-heading-blue">
          <h2 class="panel-title"><img src="<?php print $base_url . '/' . path_to_theme(); ?>/images/partecipa_consultazioni.png" /> <?php print t('Consultazioni e Discussioni') ?></h2>
        </div>
        <div class="panel-body">
          <p><?php print t('Partecipa alle consultazioni dall’Amministrazione Comunale e da altri enti e soggetti, con la tua opinione o con tue proposte.'); ?></p>
          <a class="scopri" href="<?php print $base_url; ?>/consultazioni">Vai all'area Consultazioni e Discussioni</a>
        </div>
      </div>
      
      <?php
        $view = views_get_view('progetti_proposti_organizzazione');
        $view->set_display('block_3');
        $view->pre_execute();
        $view->execute();
        if (!empty($view->result)) :
      ?>
      <div class="panel panel-odd">
        <div class="panel-heading">
          <h2 class="panel-title"><?php print $view->get_title() ?></h2>
        </div>
        <div class="panel-body">
          <div class="row">
            <?php print $view->preview(); ?>
          </div>
        </div>
        <div class="panel-footer">
          <a class="scopri scopri-destra" href="/progetti">Visualizza tutti i progetti »</a>
        </div>
      </div>
      <?php endif; $view->destroy();?>
      
      <?php
        $view = views_get_view('blog');
        $view->set_display('block_2');
        $view->pre_execute();
        $view->execute();
        if (!empty($view->result)) :
      ?>
      <div class="panel panel">
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
  
</article>