#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
	size_t a=0, b=0;
	FILE *fp=NULL;
	char cKey='\0';
    char strFileName[32];
	char strTemp[64][256];

	memset(strFileName, 0, sizeof(strFileName));
	memset(strTemp, 0, sizeof(strTemp));

	strcpy(strFileName, "./");
	strcat(strFileName, argv[2]);
	fp=fopen(strFileName, "rb");
	if(fp==NULL)
	{
	    puts("ERROR!! \a");
		fclose(fp);
		exit(1);
	}
	else
	{
		cKey=getc(fp);
	    while(cKey!=EOF)
		{
			if(cKey=='\n')
			{
				cKey='\0';
				a++;
				b=0;
			}
			else
			{
			    strTemp[a][b]=cKey;
				b++;
			}
			cKey=getc(fp);
		}
		fclose(fp);
	}

	for(a=0; a<64; a++)
	{
		for(b=0; b<strlen(strTemp[a]); b++)
		{
		    if(strTemp[a][b]==argv[1][0])
			{
				printf("%s \n", strTemp[a]);
				break;
			}
		}
	}

	return 0;
}