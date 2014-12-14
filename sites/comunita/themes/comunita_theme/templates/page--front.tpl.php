<?php
global $user;
print render($page['iperbole_header']);
?>

<header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
  <div class="container">
    <div class="navbar-header">

      <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
      <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
        <span class="sr-only">Toggle navigation</span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>
    </div>

    <?php if (!empty($primary_nav)): ?>
      <div class="navbar-collapse collapse">
        <nav role="navigation">
          <?php if (!empty($primary_nav)): ?>
            <?php print render($primary_nav); ?>
          <?php endif; ?>
        </nav>
        <ul class="nav navbar-nav navbar-right">
          <li class="feedback"><?php print l('<span class="glyphicon glyphicon-exclamation-sign"></span> Scrivici', 'feedback', array('html' => TRUE)); ?></li>
        </ul>
      </div>
    <?php endif; ?>
  </div>
</header>

<div style="display: none" id="feedback-tooltip">
  <div class="feedback-tooltip">
    <p>Se hai idee per migliorare le funzionalità di questa piattaforma, lascia un feedback.</p>
  </div>
</div>

<div class="main-container container">

  <header role="banner" id="page-header">
    <?php print render($page['header']); ?>
  </header> <!-- /#page-header -->

  <div class="row">
    <section<?php print $content_column_class; ?>>
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
      <a id="main-content"></a>
      <?php print $messages; ?>
        <?php 
          $block = module_invoke('comunita_blocchi', 'block_view', 'intro');
          print render($block['content']);
        ?>
      
        <?php 
          $block = module_invoke('comunita_leaflet_map', 'block_view', 'mappa_homepage');
          print render($block['content']);
        ?>
      
        <div class="row row1">
          <div class="col-md-4">
            <?php if($user->uid == 0): ?>
            <div class="panel panel-info-secondary panel-accedi">
              <?php $block = module_invoke('block', 'block_view', '3'); ?>
              <div class="panel-heading">
                <h2 class="panel-title"><?php print t('Iscriviti alla Rete Civica') ?></h2>
              </div>
              <div class="panel-body">
                <?php
                  print render($block['content']);
                ?>
              </div>
            </div>
            <?php else: ?>
            <div class="panel panel-odd panel-accedi">
               <?php
                $user_data = user_load($user->uid);
                $block = module_invoke('block', 'block_view', '4');
              ?>
              <div class="panel-heading">
                <h2 class="panel-title"><?php print t('Ciao') . ' ' . $user_data->field_nome[LANGUAGE_NONE][0]['value']; ?></h2>
              </div>
              <div class="panel-body">
                <p>Benvenuto nel canale Comunità della Rete Civica! Visualizza i tuoi profili sulla Rete Civica:</p>
                <p>
                  <?php print l('>> Vai al tuo profilo di Comunità', 'user') ?><br/>
                  <?php print l('>> Vai al tuo account personale', 'https://servizi.comune.bologna.it/fascicolo/user/' . strtolower($user->name) . '/area-profilo', array('external' => TRUE)); ?>
                </p>
              </div>
              <div class="panel-footer">
                <?php print l('Esci', 'caslogout'); ?>
              </div>
            </div>
            <?php endif; ?>
          </div>
          
          <div class="col-md-8 home-blog">
            <div class="panel panel-odd panel-no-title panel-blog-home">
              <div class="panel-body">
                <div class="col-sm-6"><?php print views_embed_view('blog', 'block', '123'); ?></div>
                <div class="col-sm-6"><h3>Ultimi post</h3><?php print views_embed_view('blog', 'block_1', '123'); ?></div>
              </div>
            </div>
          </div>
        </div>
      
        <div class="row row2">
          <div class="col-sm-8 home-progetti panel-2-col">
            <?php print views_embed_view('progetti', 'block'); ?>
          </div>
          
          <div class="col-sm-4">
            <div class="panel panel-info">
              <?php $block = module_invoke('block', 'block_view', '1'); ?>
              <div class="panel-heading">
                <h2 class="panel-title"><?php print t('Consultazioni') ?></h2>
              </div>
              <div class="panel-body">
                <?php
                  print render($block['content']);
                ?>
              </div>
            </div>
          </div>
        </div>
        
        <div class="row row3">
          
          <div class="col-sm-4">
            <div class="panel panel-info">
              <?php $block = module_invoke('block', 'block_view', '2'); ?>
              <div class="panel-heading">
                <h2 class="panel-title"><?php print t('Partecipa') ?></h2>
              </div>
              <div class="panel-body">
                <?php
                  print render($block['content']);
                ?>
              </div>
            </div>
          </div>
          
          <div class="col-sm-8 home-beni panel-2-col">
            <?php print views_embed_view('beni_comuni', 'block'); ?>
          </div>
        </div>
        
        <div class="row row4">
          <div class="col-sm-8 home-profili panel-2-col">
            <?php print views_embed_view('profili', 'block'); ?>
          </div>
          
          <?php if($user->uid > 0): ?>
          <div class="col-sm-4 home-news">
            <div class="panel panel-odd">
              <div class="panel-heading">
                <h2 class="panel-title"><?php print t('Cosa succede su Comunità') ?></h2>
              </div>
              <div class="panel-body">
                <?php print views_embed_view('blog', 'block_succede'); ?>
              </div>
            </div>
          </div>
          <?php endif; ?>
        </div>
        
    </section>

  </div>
</div>
<footer class="footer container">
  <?php print render($page['footer']); ?>
</footer>
