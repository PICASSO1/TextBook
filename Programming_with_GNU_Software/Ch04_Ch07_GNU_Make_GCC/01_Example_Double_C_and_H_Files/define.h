#ifndef _DEFINE_H_
#define _DEFINE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

typedef struct {
	int *abc;
	int (*myFunc)(int *, int *);
} data_t;

int hhhh(int *, int *);
void test(void *);

#endif
