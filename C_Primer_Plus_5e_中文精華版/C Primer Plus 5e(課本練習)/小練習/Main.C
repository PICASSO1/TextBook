#include <stdio.h>
#include "Exercise.h"

extern int CheckDot(char *string);

int main(int argc, char *argv[])
{
    int bl=1;

    bl=CheckDot(argv[1]);

    if(bl==1)
        printf("格式正確!! \n");
    else if(bl==0)
        printf("格式錯誤!! \n");

    return 0;
}