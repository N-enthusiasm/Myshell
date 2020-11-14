#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define BUFFSIZE 512
int main(int argc,char **argv)
{
    char c;
    int line = 10;
    char buffer[BUFFSIZE][BUFFSIZE];
    int count=0;
   
    while((c=getopt(argc,argv,"n:"))!=-1)
	{
        int x=atoi(optarg);
        line = x;
    }
    
    char *path = argv[optind];
    FILE *fp;
    int index = 0;
   
    if((fp = fopen(path,"r")) == NULL)
    {
        printf("文件不存在");
        return -1;
    }
   
   
    while(!feof(fp))
    {
		count++;
        fgets(buffer[index],BUFFSIZE,fp);
		index++;
    }
   
    fclose(fp);
    if(count<line){
		printf("文件行数不够\n");
	}
    else{
	index=0;
	int i=0;
   	for(i=0;i<line;i++)
    	{
        	printf("%s",buffer[index++]);
    	}
	}
	return 0;
}
