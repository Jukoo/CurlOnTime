#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <time.h>

#include "t_at.h"

/**
 * Show the usage of the programme 
 * \param [char] c_main_first_args  the  basename  of the programme 
 */
void  display_usage (const char *c_main_first_args) 
{
    (void) fprintf(stdout , "usage  of %s < URL_LINK > %c" ,c_main_first_args , 0x00a) ;
     exit(EXIT_FAILURE) ;  
}


size_t w_bin_data (void * ptr, size_t size  , size_t  nmemb  , void* f_stream) 
{
    size_t  stream_buffer_writen=fwrite(ptr , size , nmemb ,(FILE*) f_stream)  ; 
    return stream_buffer_writen ; 
} 

/*!
 * restitute_abs_path 
 * restitute the absolute path  to save file  
 * @param  char directory_name the main path  
 * @param  const char   filename  ->  data  file name 
 * @return char the absolute directory  
 *
 */
char  *restitute_abs_path(char * dir ,  const char * filename)  
{
    char  endpoint_char =  0 ; 
    int   endpoint_pos  =  0 ; 
    do {
        endpoint_char=dir[endpoint_pos] ; 
        endpoint_pos++ ; 
    }while(endpoint_char != '\0') ; 
    
    endpoint_pos-- ;  

    for (  int i = 0 ;  i  <  MAX_CHAR_BUFF ; i++) { 
        dir[endpoint_pos]  = filename[i]; 
        endpoint_pos++ ;  
    }

    return dir; 
}

/* ! 
 *  curl_stack_process  e
 *  execute  curl request  through  http or https  request  
 *  @param   CURL  * curl  handler  
 *  @param   D_U   * data_util   essential  user data 
 *  @param   BOOL  status   use  for debuging curl request  
 */
void curl_stack_process (CURL * curl , D_U *  data  ,  BOOL * status) 
{
    curl_easy_setopt(curl , CURLOPT_URL          , data->direct_link ) ; 
    curl_easy_setopt(curl , CURLOPT_WRITEFUNCTION, data->curl_buffer ) ; 
    
    if (* status== TRUE) 
        curl_easy_setopt(curl, CURLOPT_VERBOSE , 1L);

}


void update_time(int  *h_time , int *minutes) {
    
    time_t time_brute = 0  ; 
    time_brute= time(NULL) ;  
    struct tm * cur_time  =  NULL;    
    cur_time =  localtime(&time_brute)  ;  
 
    *h_time =  cur_time->tm_hour ;
    *minutes=  cur_time->tm_min  ; 
    /*
    *seconds=  cur_time->tm_sec  ; 
    fprintf(stdout ,  " sec  %d  \n"  ,  *seconds) ; 
    */ 
    fprintf(stdout ,  " time  %d \n "  ,  *h_time) ; 
    fprintf(stdout ,  " min  %d  \n "  ,  *minutes) ; 
}
