#include <stdio.h>
#include <string.h>

void copy_2_arrays(double SOURCE[][2], double TARGET[][2], int n);

int main(void)
{
	int a, b;
    double dSource[5][2]={{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 0}};
	double dTarget[5][2];

	memset(dTarget, 0, sizeof(dTarget));

	puts("原本的陣列內容: ");
	for(a=0; a<5; a++)
	{
	    for(b=0; b<2; b++)
			printf("%3.2lf ", dSource[a][b]);
		putc('\n', stdout);
	}
	copy_2_arrays(dSource, dTarget, 5);
	puts("複製過的陣列內容: ");
	for(a=0; a<5; a++)
	{
	    for(b=0; b<2; b++)
			printf("%3.2lf ", dTarget[a][b]);
		putc('\n', stdout);
	}

	return 0;
}
//===============================================================================================
void copy_2_arrays(double SOURCE[][2], double TARGET[][2], int n)
{
    int a, b;

	for(a=0; a<n; a++)
	{
	    for(b=0; b<2; b++)
			TARGET[a][b]=SOURCE[a][b];
	}

	return;
}