#include <stdio.h>
#include <unistd.h>

int 
main(argc, argv, envp)
int argc;
char **argv;
char *envp[];
{
	int opt = 0;

	while ((opt = getopt(argc, argv, "if:lr")) != -1) {
		switch (opt) {
			case 'i':
			case 'l':
			case 'r':
				printf("Option: %c \n", opt);
				break;
			case 'f':
				printf("Filename: %s \n", optarg);
				break;
			case ':':
				printf("Option needs a value!! \n");
				break;
			case '?':
				printf("Unknown option: %c \n", optopt);
				break;
			default:
				break;
		}
	}

	for (; optind < argc; optind++)
		printf("Argument: %s \n", argv[optind]);

	return 0;
}
