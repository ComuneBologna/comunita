<?php

/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */

global $user, $base_url;
$this_user = user_load($user_profile['field_nome']['#object']->uid);
?>
<div class="profile row"<?php print $attributes; ?>>
  <div class="col-sm-6">
    <div class="panel panel-notitle panel-user">
      <div class="panel-body">
        <div class="row">
          <div class="col-sm-6 col-pictures">
            <div class="profile-title">
              <h1><?php print $field_nome[0]['safe_value'] . ' ' . $field_cognome[0]['safe_value'] ; ?></h1>
            </div>
            <div class="row">
              <?php if(!empty($user_profile['user_picture']['#markup']) && file_exists($this_user->picture->uri)): ?>
              <div class="col-sm-7">
                <?php print render($user_profile['user_picture']); ?>
              </div>
              <div class="col-sm-5">
                <?php print render($user_profile['field_avatar']); ?>
                <?php print render($user_profile['field_ebologna_nickname']); ?>
                <div style="font-family: 'Calibre', arial; font-weight: 700; text-align: center; font-size: 1em;">è Bologna</div>
              </div>
              <?php else: ?>
              <div class="col-sm-7">
                <?php print render($user_profile['field_avatar']); ?>
              </div>
              <div class="col-sm-5">
                <?php print render($user_profile['field_ebologna_nickname']); ?>
                <div style="font-family: 'Calibre', arial; font-weight: 700; text-align: center; font-size: 1em;">è Bologna</div>
              </div>
              <?php endif; ?>
            </div>
            <?php if(isset($user_profile['links']['flag'])): ?>
              <?php print render($user_profile['links']['flag']); ?>
              <?php print l('<span class="glyphicon glyphicon-exclamation-sign"></span> Segnala questo utente', 'segnala-utente', array('html' => true, 'query' => array('field_utente_segnala' => $this_user->uid))); ?>
            <?php elseif($user->uid == $this_user->uid): ?>
            <?php else: ?>
              <a href="/comunita/cas" class="flag-register">Accedi per seguire</a>
            <?php endif;?>
            <?php
              if($user->uid == $this_user->uid) {
                print l('<span class="glyphicon glyphicon-pencil"></span> Aggiorna da account Rete Civica', 'user/' . $this_user->uid, array('html' => true, 'attributes' => array('class' => array('account-fetch')), 'query' => array('account' => 'fetch')));
              }
            ?>
          </div>
          <div class="col-sm-6">
            <?php
            if($user->uid == $this_user->uid) {
              //print l('[modifica profilo]', 'user/' . $this_user->uid . '/edit', array('attributes' => array('class' => array('profile-edit'))));
            }
            ?>
            
            <div class="row social-links-user">
              <div class="col-sm-12">
                <?php if(!empty($this_user->field_facebook)): ?>
                <a href="<?php print $this_user->field_facebook[LANGUAGE_NONE][0]['url']; ?>" target="_blank" rel="nofollow">
                  <img src="<?php print $base_url . '/' . path_to_theme(); ?>/images/facebook.png" class="facebook"/>
                </a>
                <?php endif; ?>
                <?php if(!empty($this_user->field_twitter)): ?>
                <a href="<?php print $this_user->field_twitter[LANGUAGE_NONE][0]['url']; ?>" target="_blank" rel="nofollow">
                  <img src="<?php print $base_url . '/' . path_to_theme(); ?>/images/twitter.png" class="twitter"/>
                </a>
                <?php endif; ?>
              </div>
            </div>
            <div class="row">
              <?php if(isset($user_profile['field_sito_personale'])): ?>
              <div class="col-sm-12">
                <?php print render($user_profile['field_sito_personale']); ?>
              </div>
              <?php endif; ?>
              <?php if(isset($user_profile['field_blog_personale'])): ?>
              <div class="col-sm-12">
                <?php print render($user_profile['field_blog_personale']); ?>
              </div>
              <?php endif; ?>
            </div>
            <div class="row">
              <?php if($this_user->field_mostra_email[LANGUAGE_NONE][0]['value'] && $user->uid > 0): ?>
              <div class="col-sm-12 user-mail">
                <span class="label">email:</span> <?php print $this_user->mail ?>
              </div>
              <?php endif; ?>
              <?php if($this_user->field_mostra_telefono[LANGUAGE_NONE][0]['value'] && $user->uid > 0): ?>
              <div class="col-sm-12">
                <span class="label">tel:</span> <?php print $this_user->field_telefono[LANGUAGE_NONE][0]['value']; ?>
              </div>
              <?php endif; ?>
            </div>
          </div>
        </div>
      </div>
      <?php if(isset($user_profile['field_statement'])): ?>
      <div class="panel-footer">
        <?php print render($user_profile['field_statement']); ?>
      </div>
      <?php endif; ?>
    </div>

    <?php if($user->uid == $this_user->uid): ?>
    <div class="panel interagisci">
      <div class="panel-heading">
        <h2 class="panel-title"><?php print t('Interagisci con la piattaforma'); ?></h2>
      </div>
      <div class="panel-body">
        <p>
          <?php print t('Nella sezione ' . l('Partecipa', 'partecipa') . ' trovi bandi, avvisi e altre occasioni d\'impegno.'); ?>
        </p>
        <div class="action-links">
        <?php print l('Racconta un progetto', 'node/add/progetto'); ?>
        <p>
          <?php print t("Puoi anche raccontare un progetto già concluso o proporre un'idea per cui cerchi supporto."); ?>
        </p>
        </div>
        <div class="action-links">
        <?php print l('Crea un profilo organizzazione', 'node/add/organizzazione'); ?>
        <p>
          <?php print t("Se fai parte di un'organizzazione puoi crearne un profilo con cui, tra le altre cose, potrai sviluppare e raccontare progetti e iniziative"); ?>
        </p>
        </div>
        <div class="action-links">
        <?php print l('Crea nuovo post nel blog', 'node/add/article'); ?>
        <p>
          <?php print t("Puoi anche creare post nel blog"); ?>
        </p>
        </div>
      </div>
    </div>
    <?php endif; ?>

    <?php if(isset($field_presentazione)): ?>
    <div class="panel">
      <div class="panel-heading">
        <h2 class="panel-title"><?php print t('Presentazione'); ?></h2>
      </div>
      <div class="panel-body">
        <?php print render($user_profile['field_presentazione']); ?>
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
        <?php print render($user_profile['field_risorse_capacita']); ?>
        <?php print render($user_profile['field_risorse_strumenti']); ?>
        <?php print render($user_profile['field_risorse_materiali']); ?>
        <?php print render($user_profile['field_risorse_spazi']); ?>
        <?php endif; ?>
        <?php if(!empty($field_supporto_capacita) || !empty($field_supporto_strumenti) || !empty($field_supporto_materiali) || !empty($field_supporto_spazi)): ?>
        <h3>Bisogni</h3>
        <?php print render($user_profile['field_supporto_capacita']); ?>
        <?php print render($user_profile['field_supporto_strumenti']); ?>
        <?php print render($user_profile['field_supporto_materiali']); ?>
        <?php print render($user_profile['field_supporto_spazi']); ?>
        <?php endif; ?>
      </div>
    </div>
    <?php endif; ?>
  </div>
  
  <div class="col-sm-6">
    
    <?php
      $view = views_get_view('progetti_proposti_organizzazione');
      $view->set_display('block_4');
      $view->set_arguments(array($this_user->uid));
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
    
    <?php if(in_array('redazione', $user->roles) && in_array('redazione', $this_user->roles)): ?>
    <?php
      $view = views_get_view('progetti_proposti_organizzazione');
      $view->set_display('block_5');
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
    <?php endif; ?>

    <?php
      $view = views_get_view('progetti_proposti_organizzazione');
      $view->set_display('block_2');
      $view->set_arguments(array($this_user->uid));
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
    
    <?php if($user->uid == $this_user->uid): ?>
      <?php
        $view = views_get_view('organizzazioni');
        $view->set_display('block_1');
        $view->set_arguments(array($this_user->uid));
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
      <?php endif; ?>
    <?php endif; ?>
    
    <!--<div class="panel">
      <div class="panel-heading">
        <h2 class="panel-title"><?php //print t('Attività recenti'); ?></h2>
      </div>
      <div class="panel-body">
        <?php //print views_embed_view('heartbeat_activity_fields_', 'block_user', $this_user->uid); ?>
      </div>
    </div>
    -->
    
    <?php
      $view = views_get_view('post_recenti_su_organizzazione');
      $view->set_display('block_2');
      $view->set_arguments(array($this_user->uid));
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
    <?php endif; ?>
    
    <?php
      $view = views_get_view('followers');
      $view->set_display('block_1');
      $view->set_arguments(array($this_user->uid));
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
    <?php endif; ?>
    
    <?php
        $view = views_get_view('segnalazioni');
        $view->set_display('block_1');
        $view->set_arguments(array($this_user->uid));
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
