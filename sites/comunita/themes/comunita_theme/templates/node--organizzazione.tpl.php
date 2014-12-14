<?php global $user, $base_url; ?>
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
          <div class="row">
            <div class="col-sm-4">
              <?php print render($content['field_org_picture']) ?>
              <?php if(isset($content['links']['flag'])): ?>
              <?php print render($content['links']['flag']); ?>
              <?php elseif($user->uid == 0): ?>
                <a href="/comunita/cas" class="flag-register">Accedi per seguire</a>
              <?php endif;?>
            </div>

            <div class="col-sm-8">
              <?php
//              if(og_user_access('node', $node->nid, 'administer group')) {
//                print l('[modifica pagina]', 'node/' . $node->nid . '/edit', array('attributes' => array('class' => array('profile-edit'))));
//              }
              ?>
              <div class="profile-title">
                <h1><?php print $title ; ?></h1>
              </div>
              <div class="row social-links-user">
                <div class="col-sm-12">
                  <?php if(!empty($node->field_facebook)): ?>
                  <a href="<?php print $node->field_facebook[LANGUAGE_NONE][0]['url']; ?>" target="_blank" rel="nofollow">
                    <img src="<?php print $base_url . '/' . path_to_theme(); ?>/images/facebook.png" class="facebook"/>
                  </a>
                  <?php endif; ?>
                  <?php if(!empty($node->field_twitter)): ?>
                  <a href="<?php print $node->field_twitter[LANGUAGE_NONE][0]['url']; ?>" target="_blank" rel="nofollow">
                    <img src="<?php print $base_url . '/' . path_to_theme(); ?>/images/twitter.png" class="facebook"/>
                  </a>
                  <?php endif; ?>
                </div>
              </div>
              <div class="row">
                <div class="col-sm-12">
                  <?php print render($content['field_sito_personale']); ?>
                </div>
              </div>
            </div>
          </div>
          <div class="segnala"><?php print l('<span class="glyphicon glyphicon-exclamation-sign"></span> Segnala quest\'organizzazione', 'segnala-organizzazione', array('html' => true, 'query' => array('field_org_segnala' => $node->nid))); ?></div>
        </div>
      </div>

      <?php if(og_user_access('node', $node->nid, 'administer group')): ?>
      <div class="panel interagisci">
        <div class="panel-heading">
          <h2 class="panel-title"><?php print t('Interagisci con la piattaforma'); ?></h2>
        </div>
        <div class="panel-body">
          <p>
            <?php print t('Vai nella sezione <a href="/partecipa">Partecipa</a> e scopri cosa puoi fare per la città e la comunità.<br/>Puoi anche raccontare un tuo progetto già concluso o proporre una tua idea e cercare collaboratori.'); ?>
          </p>
          <div class="action-links">
          <?php print l('Racconta un progetto', 'node/add/progetto', array('query' => array('og_group_ref' => $node->nid))); ?>
          </div>
          <p>
            <?php print t("Puoi anche creare post nel blog della pagina."); ?>
          </p>
          <div class="action-links">
          <?php print l(t('Crea nuovo post nel blog'), 'node/add/article', array('query' => array('og_group_ref' => $node->nid))); ?>
          </div>
        </div>
      </div>
      <?php endif; ?>

      <?php if(isset($body)): ?>
      <div class="panel">
        <div class="panel-heading">
          <h2 class="panel-title"><?php print t('Presentazione'); ?></h2>
        </div>
        <div class="panel-body">
          <?php print render($content['body']) ?>
        </div>
      </div>
      <?php endif; ?>

      <?php if(!empty($field_supporto_capacita) || !empty($field_supporto_strumenti) || !empty($field_supporto_materiali) || !empty($field_supporto_spazi) || !empty($field_risorse_capacita) || !empty($field_risorse_strumenti) || !empty($field_risorse_materiali) || !empty($field_risorse_spazi)): ?>
      <div class="panel panel-competenze">
        <div class="panel-heading">
          <h2 class="panel-title"><?php print t('Bisogni e Risorse'); ?></h2>
        </div>
        <div class="panel-body">
          <?php if(!empty($field_risorse_capacita) || !empty($field_risorse_strumenti) || !empty($field_risorse_materiali) || !empty($field_risorse_spazi)): ?>
          <h3>Risorse</h3>
          <?php print render($content['field_risorse_capacita']); ?>
          <?php print render($content['field_risorse_strumenti']); ?>
          <?php print render($content['field_risorse_materiali']); ?>
          <?php print render($content['field_risorse_spazi']); ?>
          <?php endif; ?>
          <?php if(!empty($field_supporto_capacita) || !empty($field_supporto_strumenti) || !empty($field_supporto_materiali) || !empty($field_supporto_spazi)): ?>
          <h3>Bisogni</h3>
          <?php print render($content['field_supporto_capacita']); ?>
          <?php print render($content['field_supporto_strumenti']); ?>
          <?php print render($content['field_supporto_materiali']); ?>
          <?php print render($content['field_supporto_spazi']); ?>
          <?php endif; ?>
        </div>
      </div>
      <?php endif; ?>

    </div>
    
    <div class="col-sm-6">

      <?php
        $view = views_get_view('progetti_proposti_organizzazione');
        $view->set_display('block_1');
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
          <div class="row">
            <?php print $view->preview(); ?>
          </div>
        </div>
      </div>
      <?php endif; $view->destroy();?>
      
      <?php
        $view = views_get_view('post_recenti_su_organizzazione');
        $view->set_display('block_1');
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
      
      <?php
        $view = views_get_view('followers');
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
          <div class="row">
            <?php print $view->preview(); ?>
          </div>
        </div>
      </div>
      <?php endif; $view->destroy();?>
      
      <?php
        $view = views_get_view('segnalazioni');
        $view->set_display('block_2');
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
  
</article>