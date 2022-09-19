/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build091922
 *
 * Date: 2022 / 09 / 19
 *
 * Description: 寫一程式比較三個任意輸入的數字，並列印出最小值。
 *
(*)?*/

#include <stdio.h>
#include <string.h>

#define	LEN		3

void main(void)
{
	long double array[LEN], min = 3.4028237E+38;	/* The Maximum value of the "long double" data type. */
	size_t i = 0U;

	memset(array, 0U, sizeof(long double) * LEN);

	fprintf(stdout, "1st NO. : ");
	while (fscanf(stdin, "%Lf", &array[0]) != 1) {
		while (getchar() != '\n');
		fprintf(stdout, "1st NO. : ");
	}

	fprintf(stdout, "2nd NO. : ");
	while (fscanf(stdin, "%Lf", &array[1]) != 1) {
		while (getchar() != '\n');
		fprintf(stdout, "2nd NO. : ");
	}

	fprintf(stdout, "3rd NO. : ");
	while (fscanf(stdin, "%Lf", &array[2]) != 1) {
		while (getchar() != '\n');
		fprintf(stdout, "3rd NO. : ");
	}

	for (i = 0; i < LEN; i++) {
		if (array[i] < min)
			min = array[i];
	}

	fprintf(stdout, "\nYour input value: \n");
	fprintf(stdout, "1st NO. : %Lf \n2nd NO. : %Lf \n3rd NO. : %Lf \n", array[0], array[1], array[2]);

	fprintf(stdout, "\nThe minimum value is: %Lf !! \n", min);

	return;
}
