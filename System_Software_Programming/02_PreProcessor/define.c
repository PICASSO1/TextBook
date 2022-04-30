/**
 * File Name: define.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build042922
 *
 * Date: 2022 / 04 / 29
 *
 * Description: 
 * 1. 這個範例用來呈現當前置處理器 (PreProcessor)，遇到巨集 (Macro)的時候是如何運作的。
 *
(*)?*/

#include <stdio.h>

#define MAX(A, B)	(A>B? A: B)

int main(void)
{
	printf("MAX(4, 6): %d \n", MAX(4, 6));

	return 0;
}
