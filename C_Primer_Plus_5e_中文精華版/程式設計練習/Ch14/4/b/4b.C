#include <stdio.h>
#define MAX 40

struct Second
{
	char strFirst[MAX];
	char strMiddle[MAX];
	char strLast[MAX];
};
struct First
{
	long lnSocialID;
	struct Second stSecond;
};

void Show(struct First *Data);

int main(void)
{
	struct First stData[5] =
	{
		{111111111, {"Pablo", "Gan", "Picasso"}},
		{222222222, {"Silvia", "\0", "Huang"}},
		{333333333, {"Calvin", "Chin", "Klein"}},
		{444444444, {"Drift", "\0", "King"}},
		{555555555, {"Clark", "Steel", "Paul"}}
	};
	int a;

	for(a=0; a<5; a++)
		Show(&stData[a]);

	return 0;
}
//==================================================================
void Show(struct First *Data)
{
	if(Data->stSecond.strMiddle[0]=='\0')
		printf("%-10s, %-10s %C  -- %ld \n", Data->stSecond.strFirst, Data->stSecond.strLast, Data->stSecond.strMiddle[0], Data->lnSocialID);
	else
		printf("%-10s, %-10s %C. -- %ld \n", Data->stSecond.strFirst, Data->stSecond.strLast, Data->stSecond.strMiddle[0], Data->lnSocialID);

	return;
}
