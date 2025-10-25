#include <iostream>

using namespace std;

long sum(long a, long b);
long product(long a, long b);

int main(void)
{
	long (*pDolt)(long, long)=product;
	long (*ptr)(long, long)=sum;

	cout << "3 * 5 = " << pDolt(3, 5) << endl;

//	pDolt = sum;

	cout << "3 * (4 + 5) + 6 = " << ptr(pDolt(3, ptr(4, 5)), 6) << endl;

	return 0;
}
//==================================================================================
long sum(long a, long b)
{
	return a+b;
}
//==================================================================================
long product(long a, long b)
{
	return a*b;
}
// 函數指標─就是指「指到函數的指標變數」，當宣告成函數指標變數時，該指標變數就可以當函數來使用!!
