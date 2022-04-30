/**
 * File Name: inline.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build042922
 *
 * Date: 2022 / 04 / 29
 *
 * Description: 
 * 1. 這個範例用來呈現當前置處理器 (PreProcessor)，遇到內嵌 (Inline)函式的時候是如何運作的。
 *
 * 2. "inline" 前面一定要加上 "static" ，要不然編譯一定不會過。
 *
(*)?*/

#include <stdio.h>

static inline int MIN(int X, int Y)
{
	return (X<Y? X: Y);
}

int main(void)
{
	printf("MIN(3, 9): %d \n", MIN(3, 9));

	return 0;
}
