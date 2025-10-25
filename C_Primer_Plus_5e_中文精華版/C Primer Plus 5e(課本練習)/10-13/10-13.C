#include<stdio.h>
int main(void)
{
	int urn[3]={100,200,300};
	int *ptr1,*ptr2;

	ptr1=urn;
	ptr2=&urn[2];
	printf("ptr1=%p,*ptr1=%d,&ptr1=%p \n",ptr1,*ptr1,&ptr1);
	ptr1++;
	printf("values after ptr1++ \n");
	printf("ptr1=%p,*ptr1=%d,&ptr1=%p \n",ptr1,*ptr1,&ptr1);
	printf("ptr2=%p,*ptr2=%d,&ptr2=%p \n",ptr2,*ptr2,&ptr2);
	ptr2--;
    printf("values after --ptr2 \n");
	printf("ptr2=%p,*ptr2=%d,&ptr2=%p \n",ptr2,*ptr2,&ptr2);
	--ptr1;
	++ptr2;
	printf("ptr2-ptr1=%d \n",ptr2-ptr1);
	return 0;
}