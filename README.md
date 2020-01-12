#  [ COOL NAME PROJET  NOT  FOUND ] 


## INSTALLATION PROCESS ...  

### curl installation 
https://curl.haxx.se/download.html ->  download curl  lastest release  

```
#After  downloading  curl  tar or zip  archive  
#make   an  extraction   ```  tar -xzvf  <curl_archive.tar.gz>  
#go inside  the curl  folder  and compile  source 
./configure  --with-ssl  
# with out this  flag   some  protocole 'll be not enabled like https 
make 
make install  
```     
if  you have some errors search  for  libssl-dev  required by the flag 

### openssl  installation  to activate https protocol 

https://www.openssl.org/source/    -> dowload openssl latest release

``` 
# After  downloading  openssl tar or zip  archive  
# make   an  extraction   ```  tar -xzvf  <openssl_archive.tar.gz>
# o inside  the curl  folder  and compile  source
./config --prefix=/usr/local/ssl --openssldir=/usr/local/ssl shared zlib 
make
make test
make install 
```
