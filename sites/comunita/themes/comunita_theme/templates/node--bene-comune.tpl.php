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
        <div class="panel panel-notitle">
          <div class="panel-body">
            <?php print render($content['stato_bene']); ?>
            <div class="row">
              <div class="col-sm-4">
                <?php print render($content['field_fotografia']) ?>
              </div>
              <div class="col-sm-8">
                <div class="profile-title">
                  <h1><?php print $title ; ?></h1>
                </div>
                <div class="row">
                  <div class="col-sm-12">
                    <?php
                      print render($content['field_tipologia']);
                      print render($content['field_progetto_collegato']);
                      print render($content['og_group_ref']);
                    ?>
                  </div>
                </div>
              </div>
            </div>
          </div>
          <?php if(count(array_intersect(array('redazione', 'administrator'), array_values($user->roles))) > 0): ?>
          <div class="panel-footer">
            <h3>Azioni redazione</h3>
            <div class="action-links">
              <?php print l('Aggiungi patto di collaborazione', 'node/add/patto-di-collaborazione', array('query' => array('field_contenuto_collegato' => $node->nid))); ?>
            </div>
          </div>
          <?php endif; ?>
        </div>

        <?php if(isset($content['body'])): ?>
        <div class="panel">
          <div class="panel-heading">
            <h2 class="panel-title"><?php print t('Descrizione'); ?></h2>
          </div>
          <div class="panel-body">
            <?php print render($content['body']); ?>
          </div>
        </div>
        <?php endif; ?>

        <?php if(isset($content['field_motivazione_bene'])): ?>
        <div class="panel">
          <div class="panel-heading">
            <h2 class="panel-title"><?php print t('Motivazione dell\'individuazione come Bene Comune'); ?></h2>
          </div>
          <div class="panel-body">
            <?php print render($content['field_motivazione_bene']); ?>
          </div>
        </div>
        <?php endif; ?>
      </div>

      <div class="col-sm-6">
        <?php
          print render($content['field_geo']);
        ?>
        
        <?php
          $view = views_get_view('patti_di_collaborazione');
          $view->set_display('block');
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

        <?php if(!empty($field_link_a_risorse_online_di_i)): ?>
        <div class="panel">
          <div class="panel-heading">
            <h2 class="panel-title"><?php print t('Link a risorse online di interesse specifico'); ?></h2>
          </div>
          <div class="panel-body">
              <?php print render($content['field_link_a_risorse_online_di_i']); ?>
          </div>
        </div>
        <?php endif; ?>
      </div>
      
    </div>
  </div>
  
</article>