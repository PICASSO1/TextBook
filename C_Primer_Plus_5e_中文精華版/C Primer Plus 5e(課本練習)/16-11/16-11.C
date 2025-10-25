#include <stdio.h>

void why_me(void);

int main(void)
{
    fprintf(stdout, "The file is %s. \n", __FILE_);
	fprintf(stdout, "The date is %s. \n", __DATE_);
	fprintf(stdout, "The time is %s. \n", __TIME_);
	fprintf(stdout, "The version is %ld. \n", __STDC_VERSION_);
	fprintf(stdout, "This is line %d. \n", __LINE_);
	fprintf(stdout, "This fuction is %s \n", __func_);
	why_me();

	return 0;
}
//================================================================
void why_me(void)
{
    fprintf(stdout, "This function is %s. \n", __func_);
	fprintf(stdout, "This is line %d. \n", __LINE_);

	return;
}