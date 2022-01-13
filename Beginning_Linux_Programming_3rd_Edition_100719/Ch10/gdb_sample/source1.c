#include <stdio.h>
#include <stdlib.h>

static int func();
static int func1();
static int func2();
static int func3();

int main(void)
{
	int ret = 0;

	ret += func1();
	ret += func2();
	ret += func3();

	return ret;
}

static int func(void)
{
	static int i = 0;
	++i;
	return ((i == 2)? 1: 0);
}

static int func1(void)
{
	return func();
}

static int func2(void)
{
	return func();
}

static int func3(void)
{
	return func();
}

