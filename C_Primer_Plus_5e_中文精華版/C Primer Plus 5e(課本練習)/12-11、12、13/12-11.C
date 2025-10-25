#include "diceroll.h"
#include <stdio.h>
#include <stdlib.h>

int roll_count=0;

static int rollem(int sides)             // 這個函式，只能在這個檔案裡使用!!
{
    int roll;

	roll=rand()%sides+1;
	++roll_count;                        // 因為roll_count在*.h檔中已參考宣告過了，所以在這個函式裡就不再宣告!!
	return roll;
}
//=================================================
int roll_n_dice(int dice, int sides)     // 這個函式在*.h檔中已宣告過了，所以這裡是定義!!
{
    int d, total=0;

	if(sides < 2)
	{
	    printf("Need at least 2 sides. \n");
		return -2;
	}
	if(dice < 1)
	{
	    printf("Need at least 1 die. \n");
		return -1;
	}

	for(d=0; d<dice; d++)
	    total+=rollem(sides);

	return total;
}