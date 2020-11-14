#include<stdio.h>
#include<sys/types.h>
#include<pwd.h>

int main(int ac,char *av[])
{
	struct passwd *pw=NULL;
	pw= getpwuid(getuid());
	if(pw==NULL){
		perror(*av);
		return -1;
	}
	
	printf("%s\n",pw->pw_name);
        return 0;
}
