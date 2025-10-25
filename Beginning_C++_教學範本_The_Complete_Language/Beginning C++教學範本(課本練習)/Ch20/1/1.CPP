#include <iostream>
#include <vector>
#define SIZE 10

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	int a[SIZE];
	vector<int> v(SIZE);

	cout << "Size of 10 elements array : " << sizeof(a) << endl;
	cout << "Size of 10 elements vector: " << sizeof(v) << endl;

	for(int i(0); i<SIZE; ++i)
		a[i] = v[i] = i;

	int aSum = 0, vSum = 0;
	for(i = 0; i<SIZE; ++i)
	{
		aSum += a[i];
		vSum += v[i];
	}
	cout << "Sum of 10 array  elements: " << aSum << endl;
	cout << "Sum of 10 vector elements: " << vSum << endl;

	return 0;
}
