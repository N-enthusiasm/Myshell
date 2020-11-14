#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define LENTH 255

int main()
{
	char path[LENTH];
	puts(getcwd(path,LENTH));
	return 0;
}
