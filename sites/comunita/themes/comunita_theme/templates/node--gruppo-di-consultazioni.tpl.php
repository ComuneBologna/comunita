<article<?php print $attributes; ?> class="news-item">
  <?php print $user_picture; ?>
  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
  <header>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  
  <?php if($page): ?>
  <div class="row">
    <div class="col-sm-12">
      <div class="panel panel-consultazione">
        <div class="panel-heading">
          <h1><?php print $title ; ?></h1>
          <?php if(isset($content['og_group_ref'])): ?>
          <span>Promotore: <?php print render($content['og_group_ref']); ?></span>
          <?php endif; ?>
        </div>
        <div class="panel-body">
          <?php
            hide($content['comments']);
            hide($content['links']);
            hide($content['field_consultazioni_incluse']);
            print render($content);
          ?>
          <div class="row row-date">
            <?php
              $prima_discussione = node_load($field_consultazioni_incluse[0]['target_id']);
            ?>
            <div class="col-sm-6">
              <?php print render(field_view_field('node', $prima_discussione, 'field_apertura_consultazione', 'full')); ?>
            </div>
            <div class="col-sm-6">
              <?php print render(field_view_field('node', $prima_discussione, 'field_chiusura_consultazione', 'full')); ?>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
  <div class="row">
    <div class="col-sm-12">
      <div class="panel">
        <div class="panel-heading">
          <h2 class="panel-title">I punti della carta</h2>
        </div>
        <div class="panel-body">
          <?php
            print render($content['field_consultazioni_incluse']);
          ?>
        </div>
      </div>
    </div>
  </div>
  <?php else: ?>
  <div<?php print $content_attributes; ?>>
    <?php
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
    <a class="scopri scopri-destra" href="<?php print $node_url ?>" title="Scopri di più"><?php print t('Scopri di più »') ?></a>
  </div>
  <?php endif; ?>
</article>