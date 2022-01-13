#include <stdio.h>
#include <unistd.h>

#define	_GNU_SOURCE
#include <getopt.h>

int 
main(argc, argv, envp)
int argc;
char **argv;
char *envp[];
{
	int opt = 0;
	struct option longopts[] = {
		{"initialize", 0, NULL, 'i'},
		{"file", 1, NULL, 'f'},
		{"list", 0, NULL, 'l'},
		{"restart", 0, NULL, 'r'},
		{"\0", 0, NULL, 0},
	};

	while ((opt = getopt_long(argc, argv, "if:lr", longopts, NULL) != 0)) {
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
				printf("Unknown options: %c \n", optopt);
				break;
			default:
				break;
		}
	}

	for (; optind < argc; optind++)
		printf("Argument: %s \n", argv[optind]);

	return 0;
}
