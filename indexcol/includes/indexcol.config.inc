<?php

/**
 * @file
 * Custom Module // Created
 * @author Juan David Ceballos.
 */


/**
 * Implements hook_form().
 */

function indexcol_form($form, &$form_state) {
  $form = array();

  $form['request_data'] = array(
    '#type' =>'checkbox', 
    '#title' => t('Enable index Get service Json'),
    '#default_value' => variable_get('request_data'),
  );

  $form['request_list'] = array(
    '#type' => 'textfield', 
    '#title' => t('Please add Link fot Get results list'), 
    '#default_value' => variable_get('request_list'), 
    '#size' => 60, 
    '#description' => t('Example: https://jsonplaceholder.typicode.com/posts'),
    '#maxlength' => 128, 
  );

  $form['request_photos'] = array(
    '#type' => 'textfield', 
    '#title' => t('Please add Link fot Get results slider'), 
    '#default_value' => variable_get('request_photos'), 
    '#description' => t('Example: https://jsonplaceholder.typicode.com/photos'),
    '#size' => 60, 
    '#maxlength' => 128, 
  );

  $form['request_photos_cant'] = array(
    '#type' => 'textfield', 
    '#title' => t('Please add count img to index'), 
    '#default_value' => variable_get('request_photos_cant'), 
    '#description' => t('Example: 10'),
    '#size' => 60, 
    '#maxlength' => 128, 
  );


  $form['request_list_data'] = array(
    '#type'=> 'item',
    '#title'=> t('Render table with pager (results list)'),
    '#markup'=> l('List Full Page', 'admin/config/indexcol/list'),
  );

  $form['request_list_data_ajax'] = array(
    '#type'=> 'item',
    '#title'=> t('Render table with pager (results list Ajax Groups)'),
    '#markup'=> l('List Full Page', 'admin/config/indexcol/groups'),
  );

  $form['request_list_data_slider'] = array(
    '#type'=> 'item',
    '#title'=> t('Render Data Sliders'),
    '#markup'=> l('Slider Touch', 'admin/config/indexcol/slider'),
  );
  
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Implementation of hook_form_validate().
 */
function indexcol_form_validate($form, $form_state) {
    if (drupal_valid_path($form_state['values']['request_list']) == FALSE) {
       form_set_error('request_list', t('Please check link'));
    }
    if (drupal_valid_path($form_state['values']['request_photos']) == FALSE) {
       form_set_error('request_photos', t('Please check link'));
    }

    if (!is_numeric($form_state['values']['request_photos_cant'])) {
      form_set_error('request_photos_cant', t('Please values numerics'));
    }
}

/**
 * Implementation of hook_form_submit().
 */
function indexcol_form_submit($form, $form_state) {
    variable_set('request_data', $form_state['values']['request_data']);
    variable_set('request_list', $form_state['values']['request_list']);
    variable_set('request_photos', $form_state['values']['request_photos']);
    variable_set('request_photos_cant', $form_state['values']['request_photos_cant']);
}