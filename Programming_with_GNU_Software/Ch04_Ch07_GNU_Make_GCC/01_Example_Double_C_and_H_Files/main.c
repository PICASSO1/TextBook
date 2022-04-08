/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build040822
 *
 * Date: 2022 / 04 / 08
 *
 * Description: 
 * 1. 這乙支程序主要是為了搭配 Makefile 而寫的；用２個 *.C 檔和１個 *.H 檔來完成。其餘內容並不贅述！
 *
 * 2. 
 *
(*)?*/

#include "./define.h"

int main(void)
{
	data_t *myData = (data_t *)malloc(sizeof(data_t));
	int *def = (int *)malloc(sizeof(int));
	int *a = (int *)malloc(sizeof(int));
	int *b = (int *)malloc(sizeof(int));

	*def = 6;
	bzero(myData, sizeof(data_t));
	myData->abc = def;
	myData->myFunc = hhhh;

	test((void *)myData);

	printf("*(myData->abc) = %d \n", *(myData->abc));
	
	*a = 5;
	*b = 6;
	printf("myData->myFunc(%d, %d) = %d \n", *a, *b, myData->myFunc(a, b));

	return 0;
}
