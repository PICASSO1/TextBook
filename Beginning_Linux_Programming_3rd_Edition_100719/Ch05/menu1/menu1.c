#include <stdio.h>

/*
*	File Name: menu1.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build022416
*
*	Date: 2016 / 02 / 24
*
*	Description: 
*	1. 這一支程式的缺點：當每輸入一次'a', 'd', 'q'之后，都會自動地出現"Incorrect choice, select again. \n"的錯誤訊息，是因為當我們輸入
*	    a，在按下"Enter"鍵時，getchar()所抓到的是" a 0x0D 0x0A"。字元'a'處理完之後，接著又再處理0x0D, 0x0A....
*	2. 註解掉的部份可解決此一問題！！
*/

char *menu[] = {
	"a - add new record", 
	"d - delete record",
	"q - quit",
	(char *)NULL
};

int getchoice(char *, char *[]);

int 
main()
{
	int choice = 0;

	do {
		choice = getchoice("Please select an action", menu);
		printf("You have chosen: %c \n", choice);
	} while (choice != 'q');

	return 0;
}

int 
getchoice(greet, choices)
char *greet;
char *choices[];
{
	int chosen = 0, selected = 0;
	char **option = (char **)NULL;

	do {
		printf("Choice: %s \n", greet);
		option = choices;

		while (*option) {
			printf("%s \n", *option);
			option++;
		}

		selected = getchar();
	/*	do {
			selected = getchar();
		} while (selected == '\n');
	*/	option = choices;

		while (*option) {
			if (selected == *option[0]) {
				chosen = 1;
				break;
			}
			option++;
		}

		if (!chosen)
			printf("Incorrect choice, select again. \n");
	} while (!chosen);

	return selected;
}
