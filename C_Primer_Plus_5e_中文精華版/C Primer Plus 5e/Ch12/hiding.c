/* hiding.c -- variables in blocks */
#include <stdio.h>
int main()
{
    int x = 30;
    printf("x in outer block: %d\n", x);
    {
        int x = 77;  /* new x, hides first x */
        printf("x in inner block: %d\n", x);
    }
    printf("x in outer block: %d\n", x);
    while (x++ < 33)
    {
        int x = 100; /* new x, hides first x */
        x++;
        printf("x in while loop: %d\n", x);
    }
    return 0;
}
