/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092122
 *
 * Date: 2022 / 09 / 21
 *
 * Description: 回答下面程式執行的結果。
 *
(*)?*/

#include <stdio.h>

int value[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
void sort(int *, int);
void output(int *, int);

void main(void)
{
/*  // 已不支援這種舊式的寫法。。。。。
    void sort();
    void output();

    void sort(value, 10);
    void output(value, 10);
*/
    sort((int *)NULL, 0);
    output((int *)NULL, 0);

    sort(value, 10);
    output(value, 10);

    return;
}

void 
sort(data, max)
int *data, max;
{
    int i, j, ind, tmp;

    for (i = 0; i < max; i++) {
        tmp = data[ind = i] % 7;
        for (j = j + 1; j < max; j++)
            if (tmp < (data[j] % 7))
                tmp = data[ind = j] % 7;

        tmp = data[1];
        data[i] = data[ind];
        data[ind] = tmp;
    }
    return;
}

void 
output(data, max)
int *data, max;
{
    while (max-- > 0)
        printf("%d \n", *data++);

    return;
}
