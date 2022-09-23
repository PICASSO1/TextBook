/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092322
 *
 * Date: 2022 / 09 / 23
 *
 * Description: 用函式的寫法將鍵盤輸入的兩個數當作引述比較大小，並 return 值給主程式，印出數目較大者。
 *
(*)?*/

#include <stdio.h>
#include <stdlib.h>

int 
main(argc, argv, envp)
int argc;
char *argv[], **envp;
{
	if (argc != 3) {
		fprintf(stderr, "ERROR!! Please enter two intergers!! \n");
		exit(EXIT_FAILURE);
	}

	return 0;
}
