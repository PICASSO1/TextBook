#include <iostream>
#define SIZE 10

using namespace std;

int main(void)
{
	long lnArry[SIZE]={1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	for(int i(0); i<SIZE; i++)
	{
		if(*(lnArry+i)%2==0)
			cout << *(lnArry+i) << endl;
	}

	return 0;
}
