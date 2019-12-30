#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
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

void curl_stack_process (CURL * curl , D_U *  data  ,DETAIL * status) 
{
    curl_easy_setopt(curl , CURLOPT_URL          , data->direct_link) ; 
    curl_easy_setopt(curl , CURLOPT_WRITEFUNCTION, data->curl_buffer ); 
    
    if (* status== TRUE) 
        curl_easy_setopt(curl, CURLOPT_VERBOSE , 1L);

}


