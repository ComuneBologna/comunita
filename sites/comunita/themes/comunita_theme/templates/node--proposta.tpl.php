<article<?php print $attributes; ?> class="news-item">
  <?php print $user_picture; ?>
  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
  <header>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($display_submitted): ?>
  <footer class="submitted"><?php print $date; ?> -- <?php print $name; ?></footer>
  <?php endif; ?>  
  
  <?php if($page): ?>
  <div class="row">
    <div class="col-sm-8">
      <div class="panel">
        <div class="panel-heading">
          <h1><?php print $title ; ?></h1>
          <?php if(isset($content['og_group_ref'])): ?>
          <span>Promotore: <?php print render($content['og_group_ref']); ?></span>
          <?php endif; ?>
        </div>
        <div class="panel-body">
          <div class="row row-counters">
            <div class="counters col-sm-6">
              <div class="impressions">0 <span class="glyphicon glyphicon-eye-open"></span></div>
              <div class="likes"><?php print (flag_get_counts('node', $node->nid)['voto']) ? flag_get_counts('node', $node->nid)['voto'] : 0; ?> <span class="glyphicon glyphicon-heart"></span></div>
              <div class="comments-count"><?php print $node->comment_count; ?> <span class="glyphicon glyphicon-comment"></span></div>
            </div>
            <div class="col-sm-6">
              <?php print render($content['field_consultazione']); ?>
            </div>
          </div>
          <?php
            hide($content['comments']);
            hide($content['links']);
            hide($content['field_consultazione']);
            print render($content);
          ?>
          <div class="action-links">
          <?php print render($content['links']['flag']); ?>
          </div>
        </div>
      </div>

      <div class="panel panel-comments">
        <div class="panel-heading">
          <h2>Commenti</h2>
        </div>
        <div class="panel-body">
          <?php print render($content['comments']); ?>
        </div>
      </div>
    </div>
  </div>
  <?php else: ?>
  <div<?php print $content_attributes; ?>>
    <div class="row row-counters">
      <div class="counters col-sm-6">
        <div class="impressions">0 <span class="glyphicon glyphicon-eye-open"></span></div>
        <div class="likes"><?php print (flag_get_counts('node', $node->nid)['voto']) ? flag_get_counts('node', $node->nid)['voto'] : 0; ?> <span class="glyphicon glyphicon-heart"></span></div>
        <div class="comments-count"><?php print $node->comment_count; ?> <span class="glyphicon glyphicon-comment"></span></div>
      </div>
    </div>
    <?php
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
    <a class="scopri scopri-destra" href="<?php print $node_url ?>" title="Scopri di più"><?php print t('Scopri di più »') ?></a>
  </div>
  <?php endif; ?>
</article>