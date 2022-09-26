/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092622
 *
 * Date: 2022 / 09 / 26
 *
 * Description: 寫一程式，以陣列方式求得一週營業額的平均值。
 *
(*)?*/

#include <stdio.h>

#define	DAYS	7

const float Turnover[DAYS] = {20.26F, 45.76F, 86.45F, 23.67F, 45.78F, 12.98F, 98.54F};

void main(void)
{
	float sum = 0.000000F;
	size_t idx = 0U;

	printf("Sun: %2.2f \nMon: %2.2f \nTue: %2.2f \nWed: %2.2f \nThu: %2.2f \nFri: %2.2f \nSat: %2.2f \n\n", \
		Turnover[0], Turnover[1], Turnover[2], Turnover[3], Turnover[4], Turnover[5], Turnover[6]);

	for (idx = 0; idx < DAYS; idx++)
		sum += Turnover[idx];

	printf("The Average Weekly Turnover: %2.2f \n", sum / DAYS);

    return;
}
