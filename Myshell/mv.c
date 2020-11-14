#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
char * getFileName(char * fileName){
	char tp[100],*nm=(char*)malloc(sizeof(char));
	int i,j=0;
	for(i=strlen(fileName)-1;i>=0;i--)
	{
		if(fileName[i]=='/')break;
	}
	for(i++;i<strlen(fileName);i++)
	{
		tp[j++]=fileName[i];
	}
	tp[j]='\0';
	strcpy(nm,tp);
	return nm;
}
int main(int ac,char * av[]){
	struct stat st;
	if(ac!=3){
		fprintf(stderr,"usage: %s source destination not found\n",*av);
	}
	
	if(stat(av[1],&st)==-1 || S_ISDIR(st.st_mode)){
		printf("source is not a file");
		exit(1);
	}
	if(stat(av[2],&st)!=-1){
		if(S_ISDIR(st.st_mode)){
			strcpy(av[2]+strlen(av[2]),"/");
			strcpy(av[2]+strlen(av[2]),getFileName(av[1]));
			strcpy(av[2]+strlen(av[2]),"\0");
		}else{
			printf("destination file is already exist\n");
			
		}
	}
	if(rename(av[1],av[2])==-1){
		printf("error!\n");
	}
	return 1;
}
