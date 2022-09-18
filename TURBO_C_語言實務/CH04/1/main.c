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
 * Description: 下列各資料的長度 (Byte)為何？
 *
(*)?*/

#include <stdio.h>

int main(void)
{
	printf("1. sizeof(12)    : %zu \n", sizeof(12));
	printf("2. sizeof('B')   : %zu \n", sizeof('B'));
	printf("3. sizeof(\"AB\")  : %zu \n", sizeof("AB"));
	printf("4. sizeof(2.1)   : %zu \n", sizeof(2.1));
//	printf("5. sizeof(float 2.1): %zu \n", sizeof(float 2.1));	// 語法錯誤！GNUMake gcc 不支援此種寫法。
	printf("6. sizeof(\"ABCD\"): %zu \n", sizeof("ABCD"));
	printf("7. sizeof(576431): %zu \n", sizeof(576431));

	return 0;
}
