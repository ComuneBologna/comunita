(function($) {
    // Helper for parsing twitter links
    String.prototype.hashify = function() {
        return this.replace(/#([A-Za-z0-9\/\.]*)/g, function(m) {
            return '<a target="_new" href="https://twitter.com/search?q=' + m.replace('#','') + '">' + m + "</a>";
        });
    };

    String.prototype.linkify = function(){
        return this.replace(/[A-Za-z]+:\/\/[A-Za-z0-9-_]+\.[A-Za-z0-9-_:%&\?\/.=]+/, function(m) {
            return m.link(m);
        });
    };

    String.prototype.atify = function() {
        return this.replace(/@[\w]+/g, function(m) {
            return '<a href="https://twitter.com/' + m.replace('@','') + '">' + m + "</a>";
        });
    };

    // Require Codebird.js library
    // Twitter App is read-only, no need for hiding keys
    var cb = new Codebird;
    cb.setConsumerKey("6ObgaMcBEU6qX9983I4kKCo8e", "wLuyQTiKP1gCCBRRseQDfU78PKhHdDkm1FEKl9kDh1fRiGlgkk");
    cb.setToken("271999088-dVg0Xb2bplM76V0pdOV76uhqA0DyqNfseSAmKE30", "KIHTqgJaA6V9dvr43uYo1JMkTaIJ5wKiFOHJ3XgAB4wNM");
    cb.__call(
        "oauth2_token",
        {},
        function (reply) {
            var bearer_token = reply.access_token;
            cb.setBearerToken(bearer_token);
        }
    );

    var params = 'screen_name=' + encodeURIComponent("twiperbole") + '&count=1&include_rts=false';
    cb.__call(
        "statuses_userTimeline",
        params,
        function (reply) {
            $('#twit_profile').html('<a href="https://twitter.com/' + reply[0].user.screen_name + '" target="_blank"><img src="' + reply[0].user.profile_image_url + '" /></a>');
            $('#twit').html('<a href="https://twitter.com/' + reply[0].user.screen_name + '" target="_blank" class="extname">' + reply[0].user.name + '</a> '
                            + '<span class="twittername">@' + reply[0].user.screen_name + '</span> '
                            + '<span class="text">' + reply[0].text.linkify().atify().hashify() + '</span>');
        }
    );
})(jQuery);