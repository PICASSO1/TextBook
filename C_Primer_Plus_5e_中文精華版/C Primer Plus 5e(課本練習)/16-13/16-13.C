#include <stdio.h>
#include <stdlib.h>

void sign_off(void);
void too_bad(void);
void test(void); //

int main(void)
{
    int n;

	atexit(sign_off);      // 先註冊這一個函式!!
	atexit(test); //
	puts("Enter an integer: ");
	if(scanf("%d", &n)!=1)
	{
	    puts("That's no integer!!");
		atexit(too_bad);      // 後註冊的這一個函式，會先被執行!!
		exit(1);
	}
	fprintf(stdout, "%d is %s. \n", n, (n%2==0)?"even":"odd");

	return 0;
}
//============================================================================
void sign_off(void)
{
    puts("Thus terminates another magnificent program from");
	puts("SeeSaw Software! ");

	return;
}
//============================================================================
void too_bad(void)
{
    puts("SeeSaw Software extends its heartfelt condolences");
	puts("to you upon the failure of your program. ");

	return;
}
//============================================================================
void test(void) //
{
    fprintf(stdout, "Test!! \n");

	return;
}
