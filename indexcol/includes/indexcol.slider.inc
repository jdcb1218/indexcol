<?php

/**
 * @file
 * Custom Module // Created
 * @author Juan David Ceballos.
 */

/**
 * Implements function indexcol_list_request().
 */

function indexcol_slider(){
  if (variable_get('request_data') == TRUE) {
    drupal_add_js(drupal_get_path('module', 'indexcol') . '/js/slider_one.js');
    $slider['subject'] = '';
    $id = 'sld' . 'indexcol';
    $delta = 'indexcol';

    $slider['content'][FALSE] = array(
      '#prefix' => '<div id="' . $id . '" class="cbp-fwslider sliderfw">',
      '#suffix' => '</div>',
      'ul' => array(
        '#prefix' => '<ul>',
        '#suffix' => '</ul>',
      ),
    );
    $results = file_get_contents(variable_get('request_photos'));
    $query_result = json_decode($results);

    $cant_photos = variable_get('request_photos_cant');

    $cant = isset($cant_photos) ? $cant_photos : 10; 
    $salida = array_slice($query_result, 0, $cant);

    foreach ($salida as $key => $value) {
      $image = $value->url;
      $render = theme_image(  
        array(
          'path' => $image,
          'alt' => $value->title,
          'title' => $value->title,
          'width' => '',
          'height' => '',
          'attributes' => array('class' => 'img-responsive'),
        )
      );
      $slider['content'][FALSE]['ul'][] = array(
        '#prefix' => '<li>',
        '#suffix' => '<div id=slide_'.$key.'></div></li>',
        '#markup' => l($render, '', array('html' => TRUE)),
      );
    }
    drupal_add_js(array('sliderOne' => array($delta => $id)), 'setting');
  }else{
    $slider = t('Service disabled');
  }  
	return $slider;
}	