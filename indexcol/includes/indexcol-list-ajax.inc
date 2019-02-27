<?php 

/**
 * @file
 * Custom Module // Created
 * @author Juan David Ceballos.
 */

/**
 * Implements hook_form().
 */

function indexcol_form($form, &$form_state){
  if (variable_get('request_data') == TRUE) {
      $default = !empty($form_state['values']['list_quotes']) ? $form_state['values']['list_quotes'] : 1;
      $form['list_quotes'] = array(
        '#title' => t('Agrupacion de resultados por indixe'),
        '#type' => 'select',
        '#options' => array(1 => 1, 2 => 2, 3 => 3, 4 => 4),
        '#default_value' => $default,
        '#ajax' => array(
          'callback' => 'ajax_indexcol_callback',
          'wrapper' => 'indexcol-list-refresh',
          'method' => 'replace',
          'effect' => 'fade',
        ),
      );

      $form['lists_fieldset'] = array(
        '#title' => t("Lista generada Ajax"),
        '#prefix' => '<div id="indexcol-list-refresh">',
        '#suffix' => '</div>',
        '#type' => 'fieldset',
        '#description' => t('Esta es la lista de resultados generados por grupos de USERID'),
      );

      $results = file_get_contents(variable_get('request_list'));
      $data = json_decode($results);

      $header = array(
        'userId' => t('userId'),
        'id' => t('iD'),
        'title' => t('title'),
        'body' => t('body'),
      );

      $options = array();
      $select_request = !empty($form_state['values']['list_quotes']) ? 
      $form_state['values']['list_quotes'] : 1;
      
     
      foreach($data as $data){
        if ($select_request == $data->userId) {
          $options[$data->id] = array (
            'userId' => $data->userId, 
            'id' => $data->id,
            'title' => $data->title,
            'body' => $data->body, 
          ); 
        }
      }
      
      $form['lists_fieldset']['result_data'] = array(
        '#type' => 'tableselect',
        '#header' => $header,
        '#options' => $options,
      );

      return $form;
    
    }else{
  
     $form['disabled'] = array(
        '#markup' => t('Disabled service'),
     );

    return $form;
  }
}

/**
 * Implements function ajax_indexcol_callback().
 */

function ajax_indexcol_callback($form, $form_state) {
  return $form['lists_fieldset'];
}