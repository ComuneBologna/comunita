<article<?php print $attributes; ?> class="news-item">
  <?php print $user_picture; ?>
  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
  <header>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
    <div class="group"><span class="from"><?php print t("Promotore: "); ?></span><?php print render($content['og_group_ref']); ?></div>
  </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($display_submitted): ?>
  <footer class="submitted"><?php print $date; ?> -- <?php print $name; ?></footer>
  <?php endif; ?>  
  
  <?php if($page): ?>
  <div class="row">
    <div class="col-sm-8">
      <div class="panel panel-blog">
        <div class="panel-heading">
          <?php
            $view = views_get_view('proposte');
            $view->set_display('block');
            $view->set_arguments(array($node->nid));
            $view->pre_execute();
            $view->execute();
            if (!empty($view->result)) :
          ?>
          <div class="num-proposte">
            <span class="glyphicon glyphicon-file"></span> <?php $prop = count($view->result); print $prop . (($prop > 1) ? ' proposte' : ' proposta'); ?>
          </div>
          <?php endif; ?>
          <h1><?php print $title ; ?></h1>
          <?php if(isset($content['og_group_ref'])): ?>
          <span>Promotore: <?php print render($content['og_group_ref']); ?></span>
          <?php endif; ?>
          <?php
            // Controllo se è parte di un Gruppo di Consultazioni
            $is_gruppo = FALSE;
            $query = new EntityFieldQuery();
            $query->entityCondition('entity_type', 'node')
                ->entityCondition('bundle', 'gruppo_di_consultazioni')
                ->propertyCondition('status', NODE_PUBLISHED)
                ->fieldCondition('field_consultazioni_incluse', 'target_id', $node->nid, '=');
            $result = $query->execute();
            
            if(isset($result['node'])) {
              $gruppo_nids = array_keys($result['node']);
              $gruppo = array_pop(entity_load('node', $gruppo_nids));
              print 'Questa discussione è parte della consultazione: ' . l($gruppo->title, 'node/' . $gruppo->nid);
              $is_gruppo = TRUE;
            }
          ?>
        </div>
        <div class="panel-body">
          <?php
            hide($content['og_group_ref']);
            hide($content['comments']);
            hide($content['links']);
            hide($content['field_apertura_consultazione']);
            hide($content['field_chiusura_consultazione']);
            hide($content['field_documenti_allegati']);
            hide($content['field_stato_consultazione']);
            print '<div class="tags">' . render($content['field_tags']) . '</div>';
            print render($content);
            if(!$is_gruppo):
          ?>
          <div class="row row-date">
            <div class="col-sm-6">
              <?php print render($content['field_apertura_consultazione']); ?>
            </div>
            <div class="col-sm-6">
              <?php print render($content['field_chiusura_consultazione']); ?>
            </div>
          </div>
          <?php endif; ?>
        </div>
        <div class="panel-footer">
          <?php if($user->uid > 0): ?>
          <div class="action-links">
            <?php print l(t('Fai una proposta'), 'node/add/proposta', array('query' => array('field_consultazione' => $node->nid))); ?>
          </div>
          <?php else: ?>
          <p>Accedi per inviare la tua proposta.</p>
          <?php endif; ?>
        </div>
      </div>
      <?php
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
    <div class="col-sm-4">
      <?php if(!empty($field_documenti_allegati)): ?>
      <div class="panel panel-side">
        <div class="panel-heading">
          <h2 class="panel-title"><?php print t('Documenti utili'); ?></h2>
        </div>
        <div class="panel-body">
          <?php print render($content['field_documenti_allegati']); ?>
        </div>
      </div>
      <?php endif; ?>
    </div>
  </div>
  <?php else: ?>
  <div<?php print $content_attributes; ?>>
    <?php
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>
  <?php endif; ?>
</article>