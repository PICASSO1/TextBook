#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
	char cKey = '\0';
	
	opterr = 0;
	while ((cKey = getopt(argc, argv, "ae:io:u")) != -1) {
		switch(cKey) {
			case 'a':
				printf("This is an apple!! \n");
				break;
			case 'e':
				printf("The option 'e' has another argument: %s \n", optarg);
				break;
			case 'i':
				printf("This is an \"Ice cream Sandwitch\"!! \n");
				break;
			case 'o':
				printf("The option 'o' has another argument: %s \n", optarg);
				break;
			case 'u':
				printf("This is an oringe!! \n");
				break;
			default:
				printf("Other option: %c \n", cKey);
				break;
		}
	}
	printf("optopt = %c \n", optopt);
	
	return 0;
}
