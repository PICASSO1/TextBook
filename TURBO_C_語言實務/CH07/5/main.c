/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092722
 *
 * Date: 2022 / 09 / 27
 *
 * Description: 寫一產生「整數」亂數的函式叫 my_rnd(); 令其產生 1,000 個 0 ~ 10 間的任意值，並計算其「平均值」及「標準差」。
 *
(*)?*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define	SIZE	1000

size_t my_rnd();

int main(void)
{
	size_t rnd_array[SIZE], idx = 0U, sum = 0U, rnd = 0U;
	size_t pos = 0U, tmp = 0U;
	double compute = 0.00F, standard = 0.00F, sigma = 0.00F, value = 0.00F;

	/* 設定亂數種子 */
	srand((unsigned int)time((time_t *)NULL) + (unsigned int)getpid());
	/* 初始化陣列 */
	memset(rnd_array, 0, sizeof(size_t) * SIZE);
	/* 先填入一組固定數值 */
	for (idx = 0; idx < SIZE; idx++) {
		rnd = (rnd > 10)? 0: rnd;
		rnd_array[idx] = rnd++;
	}

	/* 將剛才填入的固定值重新洗牌 */
	for (idx = 0; idx < SIZE; ++idx) {
		pos = 9 * my_rnd() / RAND_MAX;
		tmp = rnd_array[idx];
		rnd_array[idx] = rnd_array[pos];
		rnd_array[pos] = tmp;
	}

	/* 計算總和 */
	for (idx = 0; idx < SIZE; idx++)
		sum += rnd_array[idx];

	/* 計算平均值 */
	compute = (double)sum / SIZE;

	/* 計算標準差 */
	for (idx = 0; idx < SIZE; idx++) {
		standard = rnd_array[idx] - compute;
		standard *= standard;
		sigma += standard;
	}
	sigma /= SIZE;
	value = sqrt(sigma);

	/* 呈現在螢幕上。。。。。 */
	for (idx = 0; idx < SIZE; idx++) {
		fprintf(stdout, "rnd_array[%3zu] = %2zu; ", idx, rnd_array[idx]);
		/* 每乙行只列印 5 個元素 */
		if ((idx + 1) == 5 || (idx + 1) == 10)
			puts("");
		else {
			if (idx >= 10 && ((idx + 1) % 5) == 0)
				puts("");
		}
		/* 每 100 個元素再多送乙行 */
		if ((idx + 1) % 100 == 0)
			puts("");
	}

	/* 結果！ */
	fprintf(stdout, "The sum is: %zu, its Average Value is: %.2f; and the Standard Deviation is: %.2f \n", sum, compute, value);

	return 0;
}

size_t my_rnd(void)
{
	return ((10 - 0) * rand() / RAND_MAX + 10);
}
