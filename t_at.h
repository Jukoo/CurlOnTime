#ifndef W_T_AT
#define W_T_AT

#define  TARGET_URL_LINK "http://www.stats.govt.nz/assets/Uploads/Annual-enterprise-survey/Annual-enterprise-survey-2018-financial-year-provisional/Download-data/annual-enterprise-survey-2018-financial-year-provisional-size-bands-csv.csv"


//  ABSOLUTE  PATH  TO STORE   CSV  DOCUMENT FILE 
#define D_LOAD_PATH     "/home/juko/Downloads/Data/"

// CSV DOCUMENT FILE NAME 
#define CSV_FILE_NAME   "data.csv"

// the MAXIMUM SIZE OF CHAR  SIZE  
#define MAX_CHAR_BUFF   50  


/*! Pipe  curl  to  write  data on binary file*/
size_t w_bin_data(void * , size_t , size_t , void*) ;

/*! build  the absolute path location */
char  *restitute_abs_path( char * , const char *) ; 

typedef struct  DATA_UTILS  {
    char *direct_link       ; 
    size_t curl_buffer      ; 
    char * csv_data_dest    ;
} D_U;

typedef  enum {
    FALSE , TRUE 
} DETAIL; 

void curl_stack_process  (CURL * , D_U* , DETAIL * ) ; 


#endif
