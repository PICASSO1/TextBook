#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARSIZE 1000
#define DATFILE "number.dat"

int main(void)
{
    FILE *fp=NULL;
    int i;
    long lnPos=0;
    double dValue=0.000000;
    double numbers[ARSIZE];

    memset(numbers, 0, sizeof(numbers));

    for(i=0; i<ARSIZE; i++)
        numbers[i]=100.0*i+1.0/(i+1);      // numbers[0]=1.000000; numbers[1]=100.500000; numbers[2]=200.333333;

    fp=fopen(DATFILE, "wb");
    if(fp==NULL)
    {
        fprintf(stderr, "Couldn't open %s for output. \n", DATFILE);
        fclose(fp);
        exit(1);
    }
    fwrite(numbers, sizeof(double), ARSIZE, fp);
    fclose(fp);

    fp=fopen(DATFILE, "rb");
    if(fp==NULL)
    {
        fprintf(stderr, "Couldn't open %s for random access. \n", DATFILE);
        fclose(fp);
        exit(1);
    }
    printf("Enter an index in the range 0-%d. \n", ARSIZE-1);
    scanf("%d", &i);

    while(i>=0 && i<ARSIZE)
    {
        lnPos=(long)i*sizeof(double);
        fseek(fp, lnPos, SEEK_SET);
        fread(&dValue, sizeof(double), 1, fp);
        printf("The dValue there is %f. \n", dValue);
        printf("Next index (out of range to quit): \n");
        scanf("%d", &i);
    }
    fclose(fp);
    puts("Bye!!");

    return 0;
}