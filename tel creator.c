#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#define BUFSIZE 1024

 
int main(){
	FILE* fr=fopen("tel.txt","rb");
	FILE* fw=fopen("t2.txt","wb");

	char buf[BUFSIZE]={0};
	size_t size, i ;
 	char tel[16]={0};
 	while((size=fread(buf,1,BUFSIZE,fr))){
 		i=0;
 		while(i<size){
 			if (isdigit(buf[i]))
 			{
 				memcpy(tel,buf+i,7);

 				for (int n = 0; n < 10000; ++n)
 				{
 					sprintf(tel+7,"%04d\n",n);
 					fwrite(tel,1,12,fw);
 				}
 				
 				i+=7;
 			}else ++i;
 		}

 	}
 


	return 0;
}
