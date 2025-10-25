/*pi502 94951042 ¼B¬K«B*/

#include <stdio.h>

int main(void)
{
	int row,i,j;
	
	for(row=1; row<=9; row=row+2){
		for(i=0; i<(9-row)/2; i++)
			printf(" ");
		for(j=1; j<=row; j++)
			printf("*");
		printf("\n");
	}
	for(row=9-2; row>=0; row=row-2){
		for(i=0; i<(9-row)/2; i++)
			printf(" ");
		for(j=1; j<=row; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}