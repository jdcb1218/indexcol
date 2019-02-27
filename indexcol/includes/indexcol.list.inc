<?php

/**
 * @file
 * Custom Module // Created
 * @author Juan David Ceballos.
 */


/**
 * Implements function indexcol_list_request().
 */

function indexcol_list_request(){
  if (variable_get('request_data') == TRUE) {
      $results = file_get_contents(variable_get('request_list'));
      $query_result = json_decode($results);

      $header_table_edit = array(
        array('data' => t('userId')),  
        array('data' => t('id')),
        array('data' => t('title')),
        array('data' => t('body')),
      ); 

      foreach ($query_result as $record_edit_table) {
        $rows_table_edit[] =  
          array(  
            array(   
              'data' => $record_edit_table->userId,
            ),
            array(  
               'data' => $record_edit_table->id,
            ),
            array(  
               'data' => $record_edit_table->title,
            ),
            array(  
               'data' => $record_edit_table->body,
            ),
        );
      } 
       $caption_table_edit = t('Table for views information peoples');

      $per_page = 30;

      $current_page = pager_default_initialize(count($rows_table_edit), $per_page);
      // Split your list into page sized chunks
      $chunks = array_chunk($rows_table_edit, $per_page, TRUE);
      // Show the appropriate items from the list
      $output = theme('table', array('header' => $header_table_edit, 'rows' => $chunks[$current_page], 'caption'=> $caption_table_edit ));
      // Show the pager
      $output .= theme('pager', array('quantity',count($rows_table_edit)));
      return $output;     
  }else{
    return "Service disabled";
  }
}
