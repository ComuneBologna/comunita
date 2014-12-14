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
          <img src="<?php print $base_url . '/' . path_to_theme(); ?>/images/beniebologna.png" />
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
          <h2 class="panel-title"><img src="<?php print $base_url . '/' . path_to_theme(); ?>/images/partecipa_bandi-e-avvisi.png" /> <?php print t('Il percorso e il regolamento'); ?></h2>
        </div>
        <div class="panel-body">
          <p>
            Grazie al progetto <a href="http://www.cittabenicomuni.it/bologna/il-progetto">Le città come beni comuni</a>, avviato nel 2012 insieme a Labsus e Centro Antartide
            è stato possibile studiare e sperimentare pratiche di cittadinanza attiva per la cura dei beni comuni.
            Sono beni comuni quei beni, materiali, immateriali e digitali, che cittadini e amministrazione riconoscono essere funzionali
            al benessere individuale e collettivo, il cui arricchimento arricchisce tutti e il cui impoverimento impoverisce tutti.
            I risultati di questo progetto hanno permesso di sviluppare un regolamento
            che semplifica e promuove le forme di collaborazione nella gestione dei beni comuni, e che prevede tre modalità di impegno per tutti i soggetti
            (cittadini, imprese, associazioni, gruppi informali, etc.).
          </p>
        </div>
      </div>
      
      <div class="panel panel-odd">
        <div class="panel-heading">
          <h2 class="panel-title"><img src="<?php print base_path() . path_to_theme(); ?>/images/beni-comuni_cosa-puoi-fare.png" /> <?php print t('Cosa puoi fare?') ?></h2>
          <p><?php print t('Gli interventi sui beni comuni urbani previsti dal regolamento possono riguardare: spazi pubblici, spazi privati a uso pubblico, edifici pubblici, la promozione dell’innovazione sociale e dei servizi collaborativi, la promozione della creatività urbana, e l\'innovazione digitale.'); ?></p>
          <br>
        </div>
        <div class="panel-body">
          <div class="row row-border">
            <p>In particolare, puoi presentare:</p>
            <ul>
              <li>Una <a href="cura-beni-comuni">proposta di collaborazione con l’Amministrazione per la cura e la rigenerazione dei beni comuni</a></li>
              <li>Una proposta in uno degli ambiti previsti da ipotesi tipiche, per i quali l’Amministrazione ha già definito con precisione presupposti, condizioni ed iter istruttorio per la loro attivazione, quali gli interventi di <a href="vandalismo-grafico">Rimozione del Vandalismo Grafico</a></li>
            </ul>
          </div>
        </div>
      </div>
    </div>
    
    <div class="col-sm-6">
      <div class="panel">
        <div class="panel-heading panel-heading-blue">
          <h2 class="panel-title"><img src="<?php print base_path() . path_to_theme(); ?>/images/beni-comuni_patto-collaborazione.png" /> <?php print t('I Patti di Collaborazione'); ?></h2>
        </div>
        <div class="panel-body">
          <p><?php print t('Il Patto di Collaborazione è il documento con cui cittadini e amministrazione si accordano sull\'intervento di cura di un bene comune e sulle sue modalità. Di seguito ne trovi alcuni selezionati tra i progetti più recenti.'); ?></p>
          <?php
            $nodes = node_load_multiple(array(), array('type' => 'patto_di_collaborazione'));
            if(!empty($nodes)) {
              print '<ul>';
              foreach ($nodes as $node) {
                print '<li class="patto-item">' . l($node->title, 'node/' . $node->nid) . '</li>';
              }
              print '</ul>';
            }
            
          ?>
        </div>
      </div>
      
      <div class="panel panel-schede">
        <div class="panel-heading">
          <h2 class="panel-title"><?php print t('Schede dei Beni Comuni'); ?></h2>
        </div>
        <div class="row">
          <div class="panel-body">
            <?php print views_embed_view('beni_comuni', 'block_1'); ?>
            <?php print l('Elenco Beni Comuni »', 'beni-comuni/elenco', array('attributes' => array('class' => array('scopri', 'scopri-destra')))) ?>
          </div>
        </div>
      </div>
      
      <?php
        $view = views_get_view('blog');
        $view->set_display('block_2');
        $view->pre_execute();
        $view->execute();
        if (!empty($view->result)) :
      ?>
      <div class="panel panel-odd">
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