#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#else 
#include <unistd.h>
#endif 
#include "t_at.h"

//TODO :
// Make the programme run in every X time  
// use  global macr o  time 
// get the hours  
// make while loop  
//  
int main (int argc  , char **argv){ 
    
    // print date exec time 
    fprintf(stdout , "%s %c" , __DATE__ ,0x00a) ;
    fprintf(stdout , "%s %c" , __TIME__ ,0X00a)  ;

    //! the absolute path location 
    char destination_dir[MAX_CHAR_BUFF]= D_LOAD_PATH  ;
    //! file name to  write  data in 
    char *data_file_name = CSV_FILE_NAME; 
    // restitute the  complete path to save  data  
    restitute_abs_path(destination_dir , data_file_name) ;  
    
    fprintf(stdout  , "  %s  \n" ,  destination_dir ) ; 
    FILE *csv_file      = NULL ;
    CURL *curl_handler  = NULL ;
    D_U  data_util      = {TARGET_URL_LINK , (size_t)w_bin_data , destination_dir} ; 
    curl_handler        = curl_easy_init() ; 
     
    if ( curl_handler == NULL) { 
       fprintf(stderr, "Warning curl handler not initialized %c", 0x00a) ; 
       exit(EXIT_FAILURE) ;
    } 




    // watch time
    
    int h_time = 0 , min = 1;  
  
    while  (h_time != TIME_CLOCK && min != 0 )  {
           update_time(&h_time , &min) ;  
           sleep(STL) ; 
           puts("time watching"); 
    }
   
    
    // enable or disable  verbose mode  good 
    // to see  more detail about curl  request
    // probably help to  debug  curl request
    BOOL   status = FALSE ;  
    if ( argc == 2 ) 
        status  =  strcmp(argv[0x0001] , "--detail") == 0x000 ?  TRUE :FALSE ; 
        //if(strcmp(argv[1]  , "--detail") == 0x000) status = TRUE ;
     

    curl_stack_process(curl_handler , &data_util , &status ) ;  
    csv_file =fopen(data_util.csv_data_dest, "wb") ;

    if (csv_file == NULL) {
        fprintf(stderr , "connot open  file  %c" , 0x00a);  
        exit(EXIT_FAILURE) ; 
    }

    curl_easy_setopt(curl_handler , CURLOPT_WRITEDATA, csv_file) ;
    curl_easy_perform(curl_handler) ; 
    fclose(csv_file) ;
    curl_easy_cleanup(curl_handler); 
    curl_global_cleanup() ;


   
    
    return EXIT_SUCCESS;

}

