<?php global $user, $base_url; ?>
<div id="header" class="header">
    <div class="container-fluid">
        <div class="row header-social">
          <div class="container">
            <div class="row">
              <div class="col-search">
                <form action="http://comune.bo.it/trova" class="navbar-form" role="search">
                    <div class="input-group">
                        <div class="input-group-btn">
                            <button class="btn btn-default" type="submit"><i class="glyphicon glyphicon-search"></i></button>
                        </div>
                        <input type="text" class="form-control" placeholder="Search" name="trova" id="srch-term">
                    </div>
                </form>
              </div>
              <div class="col-social">
                <div class="social">
                    <a target="_blank" class="tw" title="Twiperbole" href="http://twitter.com/Twiperbole"></a>
                    <a target="_blank" class="fb" title="Seguici su facebook" href="http://www.facebook.com/pages/Comune-di-Bologna-Iperbole-Rete-Civica/98223087991?ref=ts"></a>
                    <a target="_blank" class="fl" title="flickr" href="http://www.flickr.com/photos/iperbole-bologna/"></a>
                    <a target="_blank" class="pt" title="Pinterest" href="http://pinterest.com/iperbole"></a>
                    <a target="_blank" class="yt" title="You Tube" href="http://www.youtube.com/ComuneDiBologna"></a>
                    <a target="_blank" class="instagram" title="Instagram" href="http://instagram.com/twiperbole"></a>
                    <a target="_blank" class="rss" title="RSS" href="http://www.comune.bologna.it/news/all/feed"></a>
                    <!--a href="http://dati.comune.bologna.it/" title="OpenData Comne di Bologna" class="od" target="_blank"></a-->
                </div>
              </div>
              <div class="col-contact">
                <div class="iperbole-newsletter">
                  <a class="" href="http://www.comune.bologna.it/node/1000">newsletter</a>
                </div>
                <div class="iperbole-mail">
                  <a class="" href="http://webmail.iperbole.bologna.it/horde/login.php">@<strong>iperbole</strong> mail</a>
                </div>
                <div class="iperbole-contact">
                  <a href="http://www.comune.bologna.it/comune/luoghi/17:3773"><strong>call</strong> center</a> <span class="callcenter">051203040</span>
                </div>
              </div>
            </div>
          </div>
        </div>
        <div class="row header-logos">
          <div class="container">
            <div class="row">
                <div class="col-sm-2 col-md-2">
                    <img src="<?php print $base_url . '/' . path_to_theme(); ?>/images/comune-di-bologna.png" class="logo-comune" alt="Comune di Bologna" />
                </div>    
              <div class="col-sm-8 col-md-8 logo-iperbole">                
                <img src="<?php print $base_url . '/' . path_to_theme(); ?>/images/retecivica_comunita.png" class="logo-retecivica" alt="Rete civica Iperbole" />
              </div>
              <div class="col-sm-2 col-md-2 logo-ebologna">
                <img src="<?php print $base_url . '/' . path_to_theme(); ?>/images/ebologna/eBologna_1.png" class="pull-right" alt="&Egrave; Bologna - City brand" />
              </div>
            </div>
          </div>
        </div>
      <div class="row header-logos-mobile">
        <div class="container">
          <img src="<?php print $base_url . '/' . path_to_theme(); ?>/images/logo-mobile.png" class="logo-mobile"/>
        </div>
      </div>
        <div class="row header-menu">
            <div class="container">
                <div class="row">
                  <div class="col-sm-9 col-xs-11">
                      <ul class="menu">
                          <li><a href="http://www.comune.bologna.it">Il Comune</a></li>
                          <li><a href="https://servizi.comune.bologna.it/fascicolo/web/fascicolo">Servizi Online</a></li>
                          <li class="active"><a href="<?php print $base_url; ?>">Comunità</a></li>
                      </ul>
                  </div>
                  <div class="col-sm-3 col-xs-1 user-buttons">
                      <?php if($user->uid > 0): ?>
                        <?php
                          $user_data = user_load($user->uid);
                        ?>
                        <div class="picture">
                        <?php print theme_image(array('path' => $user_data->field_avatar[LANGUAGE_NONE][0]['uri'], 'width' => 42, 'height' => 42)); ?>
                        </div>
                        <div style="display: none" id="user-tooltip">
                          <div class="user-tooltip">
                            <div class="account"><a href="https://servizi.comune.bologna.it/fascicolo/user/<?php print strtolower($user->name); ?>/area-profilo">Vai al tuo <strong>account</strong> della Rete Civica</a></div>
                            <div class="profilo"><?php print l('Vai al tuo <strong>profilo</strong> di Comunità', 'user/' . $user->uid, array('html' => TRUE)); ?></div>
                          </div>
                        </div>
                        <div class="user-links">
                          <div class="login">
                          <?php
                            print t('Ciao,');
                            print l(html_entity_decode($user_data->field_nome[LANGUAGE_NONE][0]['value']), 'user/' . $user->uid);
                          ?>
                          </div>
                          <div class="logout">
                              <br/>
                          <?php
                            print l(t('Logout'), 'caslogout');
                          ?>
                          </div>
                        </div>
                      <?php else: ?>
                      <div class="user-not-logged pull-right">
                        <a href="<?php print $base_url; ?>/cas"><span class="glyphicon glyphicon-user"></span></a> <p><a href="<?php print $base_url; ?>/cas" class="login">Accedi</a></p>
                      </div>
                      <?php endif; ?>
                  </div>
                </div>
            </div>
        </div>
    </div>
</div>