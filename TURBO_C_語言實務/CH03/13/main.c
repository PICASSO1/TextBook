/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build091522
 *
 * Date: 2022 / 09 / 15
 *
 * Description: 寫一程式由鍵盤輸入兩個數，並印出其相加的結果。
 *
(*)?*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	long double ldTmp1 = 0L, ldTmp2 = 0L;

	fprintf(stdout, "Please input 2 numbers: \n1st: ");
	while (fscanf(stdin, "%LF", &ldTmp1) == 0) { }

	fprintf(stdout, "2nd: ");
	while (fscanf(stdin, "%LF", &ldTmp2) == 0) { }

	fprintf(stdout, "\nYour input: \n1st: %LF; \n2nd: %LF \n", ldTmp1, ldTmp2);

	fprintf(stdout, "\nAnd, the sum is: %LF \n", ldTmp1 + ldTmp2);

	return 0;
}
