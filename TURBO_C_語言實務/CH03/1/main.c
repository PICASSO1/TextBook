/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build091822
 *
 * Date: 2022 / 09 / 18
 *
 * Description: printf("%__", "My friends"); 式子中的空格，如填入以下各值，結果將如何？
 *
(*)?*/

#include <stdio.h>

int main(void)
{
	printf("a). %10s \n", "My friends");

	printf("b). %-10s \n", "My friends");

	printf("c). %20s \n", "My friends");

	printf("d). %-20s \n", "My friends");

	printf("e). %20.8s \n", "My friends");

	printf("f). %.8s \n", "My friends");

	return 0;
}
