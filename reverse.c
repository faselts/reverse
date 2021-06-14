#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void reverse(char *text,char *output){
    char *ptr=text;
    char *qtr=output;
    ptr=ptr+strlen(text)-2;
    while(*ptr){
        *qtr++=*ptr--;
    }
    *qtr='\0';
}

int main(int argc,char **argv){
	int fdo = open(argv[1], O_RDWR | O_CREAT);
    	int fdw = open(argv[2], O_RDWR | O_CREAT);
	char *r = (char *)calloc(100, sizeof(char));
	char text[100000];
	char output[100000];
	int sz=1;
	while(sz!=0){
		sz = read(fdo, r, 100);
		r[sz]='\0';
		strcat(text,r);
	}
    reverse(text,output);
    write(fdw,output,strlen(output));
	close(fdo);
	close(fdw);
}
