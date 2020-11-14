#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int beg=1;
	while(beg<argc){
	fprintf(stdout,argv[beg++]);
	if(argc != beg) 
	fprintf(stdout," ");
	}
	fprintf(stdout,"\n");
	exit(0);
}
