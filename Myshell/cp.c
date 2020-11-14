#include<stdio.h>

int main(int argc,char * argv[])
{
	if (argc != 3)
	{
		printf("error,there are not enough parameters\n");
		return -1;
	}
  	
	FILE *rfp = fopen(argv[1],"r");
	FILE *wfp = fopen(argv[2],"w");

  	
	int ret;
	char a[1024*4];
	while(1)
	{
		ret = fread(a,1,sizeof(a),rfp);
		if (ret == 0)
		{
			break;
		}
		fwrite(a,1,ret,wfp); 
	}
  	
	fclose(rfp);
	fclose(wfp);
	return 0;
}
