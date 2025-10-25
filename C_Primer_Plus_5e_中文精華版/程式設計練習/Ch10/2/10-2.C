#include <stdio.h>
#include <string.h>

void copy_arr(double SOURCE[], double TARGET[], int n);
void copy_ptr(double *SOURCE, double *TARGET, int n);

int main(void)
{
	int a, nSize=0;
    double source[5]={1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[5];
	double target2[5];

	memset(&target1, 0, sizeof(target1));
	memset(&target2, 0, sizeof(target2));

	copy_arr(source, target1, 5);
	puts("第一個: ");
	nSize=sizeof(target1)/sizeof(double);
	for(a=0; a<nSize; a++)
		printf("%lf ", target1[a]);
	putchar('\n');

	copy_arr(source, target2, 5);
	puts("第二個: ");
	nSize=sizeof(target2)/sizeof(double);
	for(a=0; a<nSize; a++)
		printf("%lf ", target2[a]);
	putchar('\n');

	return 0;
}
//==================================================================
void copy_arr(double SOURCE[], double TARGET[], int n)    // 使用陣列表示法來拷貝陣列
{
	int a, nSize=0;

    for(a=0; a<n; a++)
		TARGET[a]=SOURCE[a];

	return;
}
//===================================================================
void copy_ptr(double *SOURCE, double *TARGET, int n)    // 使用指標表示法來拷貝陣列
{
	int a;
    for(a=0; a<n; a++)
		TARGET[a]=(*SOURCE)+a;

	return;
}
