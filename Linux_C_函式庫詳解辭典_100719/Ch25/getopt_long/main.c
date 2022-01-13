#include <stdio.h>
#include <stdlib.h>

#define	_GNU_SOURCE
#include <getopt.h>

int 
main(argc, argv, envp)
int argc;
char **argv;
char *envp[];
{
	int c = 0;
	int option_index = 0;
	static struct option long_options[] = {
		{"add", 1, NULL, 0},
		{"append", 0, NULL, 0},
		{"delete", 1, NULL, 0},
		{"verbose", 0, NULL, 0},
		{"create", 1, NULL, 'c'},
		{"file", 1, NULL, 0},
		{"\0", 0, NULL, 0}
	};

	while ((c = getopt_long(argc, argv, "abc:d:012", long_options, &option_index)) != -1) {
		switch (c) {
			case 0:
				printf("option %s", long_options[option_index].name);
				if (optarg)
					printf(" with arg %s", optarg);
				printf("\n");
				break;
			case 'a':
				printf("option a \n");
				break;
			case 'b':
				printf("option b \n");
				break;
			case 'c':
				printf("option c with value '%s' \n", optarg);
				break;
			case 'd':
				printf("option d with value '%s' \n", optarg);
				break;
			case '?':
				break;
			default:
				printf("?? getopt returned character code %c ?? \n", c);
				break;
		}
	}
/*	printf("optind = %d \n", optind);	// for testing!!
	printf("argc = %d \n", argc);	// for testing!!
*/	if (optind < argc) {
		printf("non-option ARGV-elements: ");
		while (optind < argc)
			printf("%s", argv[optind++]);
		printf("\n");
	}
	return 0;
}
