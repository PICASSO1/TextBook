/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build040722
 *
 * Date: 2022 / 04 / 07
 *
 * Description: 
 * 1. 這一個範例並沒有太大的意義；主要是為了學習 Makefile 而寫的一個*.C檔。
 *
 * 2. 程序可以判斷系統為 Big-Endian 還是 Little-Endian ；
 *
 * 3. 程式可以呈現該作業系統上每乙種資料型態及其指標的大小。
 *
(*)?*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	unsigned char buf[4];
	signed int n = 0xDEADBEEF;

	printf("Data: 0x%X \n", n);

	memset(buf, 0x00, sizeof(unsigned char) * 4);
	memcpy(buf, &n, sizeof(unsigned char) * 4);
	if (buf[0] == 0xEF && buf[1] == 0xBE && buf[2] == 0xAD && buf[3] == 0xDE)
		printf("Byte Order: Little-Endian (Host): %02X %02X %02X %02X \n\n", buf[0], buf[1], buf[2], buf[3]);
	else if (buf[0] == 0xDE && buf[1] == 0xAD && buf[2] == 0xBE && buf[3] == 0xEF)
		printf("Byte Order: Big-Endian (Network): %02X %02X%02X%02X \n\n", buf[0], buf[1], buf[2], buf[3]);
	else { }

	printf("sizeof(char) = %d \n", sizeof(char));
	printf("sizeof(short) = %d \n", sizeof(short));
	printf("sizeof(int) = %d \n", sizeof(int));
	printf("sizeof(long) = %d \n", sizeof(long));
	printf("sizeof(float) = %d \n", sizeof(float));
	printf("sizeof(double) = %d \n", sizeof(double));
	printf("sizeof(long long) = %d \n", sizeof(long long));
	printf("sizeof(long double) = %d \n", sizeof(long double));
	printf("\n");

	printf("sizeof(char *) = %d \n", sizeof(char *));
	printf("sizeof(short *) = %d \n", sizeof(short *));
	printf("sizeof(int *) = %d \n", sizeof(int *));
	printf("sizeof(long *) = %d \n", sizeof(long *));
	printf("sizeof(float *) = %d \n", sizeof(float *));
	printf("sizeof(double *) = %d \n", sizeof(double *));
	printf("sizeof(long long *) = %d \n", sizeof(long long *));
	printf("sizeof(long double *) = %d \n", sizeof(long double *));

	return 0;
}
