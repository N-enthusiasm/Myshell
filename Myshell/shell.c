#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<pwd.h>
#include<sys/wait.h>
#include<unistd.h>

void GetLoginName()
{
    struct passwd * pass;
    pass = getpwuid(getuid());

    printf("[%s@",pass->pw_name);
}
void GetHostName()
{
    char name[128];
    gethostname(name,sizeof(name)-1);

    printf("%s",name);
}
void GetDir()
{
    char pwd[128];
    getcwd(pwd,sizeof(pwd)-1);

    int len = strlen(pwd);
    char* p = pwd+len-1;

    while(*p != '/' && len--)
    {
        p--;
    }
    p++;
    printf("%s]@",p);
}
int main()
{
    while(1)
    {
        GetLoginName();
        GetHostName();
        GetDir();
        fflush(stdout);
        
        char *buf;
		buf = (char *)malloc(sizeof(1024));

        int s = read(0,buf,1024);

        if(s < 0)
        {
            continue;
        }

        char* start = buf;
        int i =1,j=0;
        char* MyArgv[10];
		for(j=0;j<10;j++)
			MyArgv[j] = (char *)malloc(sizeof(char));

        MyArgv[0] = start; 
        while(*start)
        {
            if(isspace(*start))
            {
                *start = '\0';
                start++;
                MyArgv[i++] = start;
            }
            else
            {
                ++start;
            }
        }
        MyArgv[i-1] = NULL; 

       
        int  id = fork();
        if(id == 0)
        {
			/*if(strcmp(MyArgv[0],"cat")==0)
				execvp("./cat",MyArgv);
			else if(strcmp(MyArgv[0],"cp")==0)
				execvp("./cp",MyArgv);
			else if(strcmp(MyArgv[0],"ls")==0)
				execvp("./ls",MyArgv);
			else if(strcmp(MyArgv[0],"pwd")==0)
				execvp("./pwd",MyArgv);
			else if(strcmp(MyArgv[0],"rmdir")==0)
				execvp("./rmdir",MyArgv);
			else if(strcmp(MyArgv[0],"whoami")==0)
				execvp("./whoami",MyArgv);
			else if(strcmp(MyArgv[0],"clear")==0)
				execvp("./clear",MyArgv);
			else if(strcmp(MyArgv[0],"echo")==0)
				execvp("./echo",MyArgv);
			else if(strcmp(MyArgv[0],"head")==0)
				execvp("./head",MyArgv);
			else if(strcmp(MyArgv[0],"mv")==0)
				execvp("./mv",MyArgv);
			else
				printf("Sorry,we haven't implement what you want.\n");*/
			char * envp[]={"PATH=/home/nmy/桌面/Myshell",NULL};
			execve(MyArgv[0],MyArgv,envp);
			exit(0);
		}	
        else
        {
            wait(NULL);
        }
    }
    return 0;
}
