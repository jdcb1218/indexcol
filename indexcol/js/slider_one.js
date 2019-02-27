(function($) {
  Drupal.sliderOne = Drupal.sliderOne || {};
  Drupal.behaviors.sliderOne = {
    attach:function(context, settings) {
      $('body').once('pintar-sliders', function() {
        $slides = Drupal.settings.sliderOne;
        $.each($slides, function(i, v) {
          $('#' + v).cbpFWSlider();
        });
      });
    }
  }
})(jQuery);
