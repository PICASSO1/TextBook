#include <stdio.h>
#include <string.h>

void Enter(double ARRY[][5], int n);
double Average(double ARRY[][5], int n);
double TotalAvg(double ARRY[][5], int n);
double MAX(double ARRY[][5], int n);

int main(void)
{
	int a, b;
	double dTotalAvg=0.000000, dMax=0.000000;
	double dArray[3][5], dAvg[3];

	memset(dArray, 0, sizeof(dArray));
	memset(dAvg, 0, sizeof(dAvg));

	puts("這支程式會輸入三組─一組五個的倍精數!!");
	Enter(dArray, 3);      // a 功能
	for(a=0; a<3; a++)      // b 功能
	{
		dAvg[a]=Average(dArray, a);
	    if(a==0)
			printf("第一組數字為: ");
		else if(a==1)
			printf("第二組數字為: ");
		else // if(a==2)
			printf("第三組數字為: ");
		for(b=0; b<5; b++)
			printf("%4.2lf ", dArray[a][b]);
		printf("平均數為: %4.2lf \n", dAvg[a]);
	}
	dTotalAvg=TotalAvg(dArray, 3);      // c 功能
	printf("這15個數的總平均數為: %4.2lf \n", dTotalAvg);
	dMax=MAX(dArray, 3);
	printf("這15個數中，極大值者是: %4.2lf \n", dMax);

    return 0;
}
//================================================================
void Enter(double ARRY[][5], int n)
{
	int a, b;

	for(a=0; a<n; a++)
	{
		if(a==0)    // 第一組
			puts("請輸入第一組: ");
		else if(a==1)      // 第二組
			puts("請輸入第二組: ");
		else // if(a==2)      // 第三組
			puts("請輸入第三組: ");

	    for(b=0; b<5; b++)
		    scanf("%lf", &ARRY[a][b]);
		putchar('\n');
	}

	return;
}
//=================================================================
double Average(double ARRY[][5], int n)
{
    int a;
	double dTotal=0.000000, dAvg=0.000000;

	for(a=0; a<5; a++)
	{
		dTotal+=ARRY[n][a];
	    dAvg=dTotal/5;
	}

	return dAvg;
}
//==================================================================
double TotalAvg(double ARRY[][5], int n)
{
    int a, b;
	double dTotal=0.000000;

	for(a=0; a<n; a++)
	{
	    for(b=0; b<5; b++)
			dTotal+=ARRY[a][b];
	}

	return dTotal/15;
}
//===================================================================
double MAX(double ARRY[][5], int n)
{
    int a, b;
	double dMax=ARRY[0][0];

	for(a=0; a<n; a++)
	{
	    for(b=0; b<5; b++)
		{
		    if(ARRY[a][b]>dMax)
				dMax=ARRY[a][b];
		}
	}

	return dMax;
}
