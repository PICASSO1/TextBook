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
 * Description: 寫一程式輸入 20 個學生的成績，成績在 80 ～ 100 分列為 A ，60 ～ 79 分列為 B ，60 以下為 C ，然後印出 A, B, C 各有幾人。
 *
(*)?*/

#include <stdio.h>
#include <string.h>

#define	NUM	20

void main(void)
{
	unsigned int score[NUM], idx = 0U, cntA = 0U, cntB = 0U, cntC = 0U;

	memset(score, 0U, sizeof(unsigned int) * NUM);
	fprintf(stdout, "Please enter the grades of %d students: \n", NUM);
	for (idx = 0; idx < NUM; idx++) {
		fprintf(stdout, "%02d: ", idx + 1);
		while (fscanf(stdin, "%u", &score[idx]) == 1) {
			if (score[idx] < 0 || score[idx] > 100) {
				fprintf(stderr, "ERROR!! Retry: \n");
				while (getchar() != '\n');
				fprintf(stdout, "%02d: ", idx + 1);
				continue;
			}
			else
				break;
		}
	}

	fprintf(stdout, "\nThe results of the %d students are: \n", NUM);
	for (idx = 0; idx < NUM; idx++)
		fprintf(stdout, "%02d: %u \n", idx + 1, score[idx]);

	for (idx = 0; idx < NUM; idx++) {
		if (score[idx] >= 80 && score[idx] <= 100)
			cntA++;
		else if (score[idx] >= 60 && score[idx] <= 79)
			cntB++;
		else if (score[idx] < 60)
			cntC++;
	}

	fprintf(stdout, "\nClass A: %d; Class B: %d; Class C: %d \n", cntA, cntB, cntC);

	return;
}
