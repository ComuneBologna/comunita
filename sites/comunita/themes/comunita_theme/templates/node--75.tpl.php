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
          <img src="<?php print $base_url . '/' . path_to_theme(); ?>/images/openebologna.png" />
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
    
    <div class="col-sm-12 col-md-6">
      <div class="panel panel-odd">
        <div class="panel-heading">
          <h2 class="panel-title"><?php print t('La strategia dell\'Agenda Digitale'); ?></h2>
        </div>
        <div class="panel-body">
          <p>
            Le risorse digitali, i dati e le infrastrutture, sono al centro del percorso di sviluppo dell'Agenda Digitale, avviato nel 2011 con il contributo di
            soggetti pubblici, privati e della società civile. Si tratta di un documento strategico che ha l’obiettivo di rendere la città più “intelligente”,
            “inclusiva” e “aperta” con l’impiego delle tecnologie dell’informazione, attuandosi anch’esso in maniera partecipata, tramite iniziative che attuino la strategia dell’agenda,
            e il portale Open Data dove sono pubblicati i dati - resi disponibili in formato aperto dall’Amministrazione e da altri soggetti a partecipazione pubblica
            (Cineca, Aci, Tper, etc.), puntando sulla trasparenza e la partecipazione attiva dei cittadini.
          </p>
        </div>
      </div>
    
      <div class="panel">
        <div class="panel-heading panel-heading-blue">
          <h2 class="panel-title"><?php print t('Il Portale Open Data'); ?></h2>
        </div>
        <div class="panel-body">
          <p>
            Il portale <a href="http://dati.comune.bologna.it/" target="_blank">dati.comune.bologna.it</a> intende essere un punto di riferimento metropolitano a disposizione
            di tutti i soggetti che, nelle loro attività, producono ed incamerano dati di qualità. Dunque, un portale aperto a 360° - che abilita,
            ma nello stesso tempo attinge al contributo di altri soggetti (pubblici, privati e della società civile) - per disegnare di fatto una
            traiettoria verso l’interoperabilità tra dati eterogenei provenienti da fonti diverse. Oltre ai dati, anche le reti e le infrastutture informative del progetto
            Open Data sono riconosciute come beni comuni digitali e, come tali, saranno messi al servizio della collettività per condividerne la cura e l’impiego.
          </p>
        </div>
      </div>
      
      <div class="panel panel-odd">
        <div class="panel-heading">
          <h2 class="panel-title"><?php print t('I dati aperti di Comunità'); ?></h2>
        </div>
        <div class="panel-body">
          <p>
            Le informazioni e i dati prodotti dall'impiego di questa piattaforma sono anch'essi pubblici e riutilizzabili, coerentemente con la strategia in materia di
            Open Data e in linea con quanto previsto dalla Carta. Di seguito trovi i riferimenti delle API relative ai contenuti pubblicati,
            che sono quindi aggiornati in tempo reale. Riutilizzali e racconta sul tuo profilo come li hai impiegati!
          </p>
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
    
    <div class="col-sm-12 col-md-6">
      <div class="panel panel-infografica">
        <div class="panel-heading panel-heading-blue">
          <h2 class="panel-title"><?php print t('Infografica'); ?></h2>
        </div>
        <div class="panel-body">
          <div id="piktowrapper-embed">
            <div class="pikto-canvas-wrap">
                <div class="pikto-canvas"></div>
            </div>
         </div>
         <script>
            (function(d){
                var js, id="pikto-embed-js", ref=d.getElementsByTagName("script")[0];
                if (d.getElementById(id)) {return;}
                js=d.createElement("script"); js.id=id; js.async=true;
                js.src="https://magic.piktochart.com/assets/embedding/embed.js?UID=3489094-i_numeri_di-_open_data_bologna";
                ref.parentNode.insertBefore(js, ref);
            }(document));
         </script> 
        </div>
      </div>
    </div>
  </div>
  
</article>