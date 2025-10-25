#include <iostream>
#include <cstring>  // for memset();
#include <cstdio>   // for scanf();
#define SIZE 10

using namespace std;

int main(void)
{
	int nRet(0), i(0), nFlag(0);
	long *lnArry=NULL;
	long lnTemp(0L);
	lnArry=new long[SIZE];

	memset(lnArry, 0L, sizeof(lnArry)*SIZE);

	cout << "請依序輸入" << SIZE << "個以內的整數(非數字離開): " << endl;
	while(i<SIZE)
	{
		nRet=scanf("%ld", &lnTemp);
		if(nRet==0)
			break;
		lnArry[i]=lnTemp;
		i++;
	}
	cout << "您剛剛輸入的數是: ";
	for(int j(0); j<i; j++)
		cout << lnArry[j] << " ";
	cout << endl;
	delete []lnArry;
	lnArry=0;

	return 0;
}
