#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	TOTAL	5
#define	__FUNC__	__func__
#define	DBG(fmt, args...)	fprintf(stderr, fmt, ##args)

void Password(int);

int main(void)
{
	Password(10000);

	return 0;
}

void Password(int MAX)
{
	int password[TOTAL], i = 0;

	srand(time(NULL));
	for (i = 1; i <= TOTAL; i++) {
		password[i] = (rand() % MAX);
#ifdef DEBUG
		DBG("%s %s %s: %d: %s: Password[%d] = %04d \n", __DATE__, __TIME__, __FILE__, __LINE__, __FUNC__, i, password[i]);
#endif
	}

	return;
}

/*
NOTE:
We declared an array named "password[]", and it was a five-int size, like as: 

password[0];
password[1];
password[2];
password[3];
password[4];

But we store their value to:

password[1];
password[2];
password[3];
password[4];
password[5];

We don't have "password[5]" this item....so the process will be "Segmentation Fault"!!
*/