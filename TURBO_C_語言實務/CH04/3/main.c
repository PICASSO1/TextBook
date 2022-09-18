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
 * Description: 請寫一程式，分別以字元，8進位碼，16進位碼印出字母A。
 *
(*)?*/

#include <stdio.h>
#define	CASE	'A'

void main(void)
{
	printf("%c; %o; %02X \n", CASE, CASE, CASE);

	return;
}
