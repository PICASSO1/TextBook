#include <stdio.h>
#include <termios.h>
#include <string.h>

#define	PASSWORD_LEN	8

int 
main()
{
	struct termios initialrsettings, newrsettings;
	char password[PASSWORD_LEN + 1];

	bzero((void *)&initialrsettings, sizeof(struct termios));
	tcgetattr(fileno(stdin), &initialrsettings);

	bzero((void *)&newrsettings, sizeof(struct termios));
	newrsettings = initialrsettings;
	newrsettings.c_lflag &= ~ECHO;
	printf("Enter password: ");

	if (tcsetattr(fileno(stdin), TCSAFLUSH, &newrsettings) != 0)
		fprintf(stderr, "Could not set attributes!! \n");
	else {
		fgets(password, sizeof(char) * PASSWORD_LEN, stdin);
	//	tcsetattr(fileno(stdin), TCSANOW, &newrsettings);
		tcsetattr(fileno(stdin), TCSANOW, &initialrsettings);
		fprintf(stdout, "\nYou entered: %s \n", password);
	}

	return 0;
}
