#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

const char  KEY []="the quieter you become, the more you are able to hear!";


int main(){
	FILE* fr=fopen("pass.tgz","rb");
	FILE* fw=fopen("1.zip","wb");

	char buf[BUFSIZE]={0};
	size_t size,index=16,index2=0,i=0,n=0;
 

	while((size=fread(buf,1,BUFSIZE,fr))){
 
		while(index-index2<size)
		{
			buf[index-index2] ^= KEY[i];
			++n;
			index <<=1;
			if (++i==sizeof(KEY)) i=0;
		}

		fwrite( buf,1,size,fw);
		index2+=size;
	}

	printf("%ld\n",n );
	return 0;
}



