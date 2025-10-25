#include <iostream>
#include <limits>

using namespace std;

// 這支程式可以展示出所有型態的值域範圍!!

int main(void)
{
	cout << "The range for type int is from " << numeric_limits<int>::min() << " to " << numeric_limits<int>::max() << endl;
	cout << "The range for type unsigned int is from " << numeric_limits<unsigned int>::min() << " to " << numeric_limits<unsigned int>::max() << endl;
	cout << endl;
	cout << "The range for type short is from " << numeric_limits<short>::min() << " to " << numeric_limits<short>::max() << endl;
	cout << "The range for type unsigned short is from " << numeric_limits<unsigned short>::min() << " to " << numeric_limits<unsigned short>::max() << endl;
	cout << endl;
	cout << "The range for type long is from " << numeric_limits<long>::min() << " to " << numeric_limits<long>::max() << endl;
	cout << "The range for type unsigned long is from " << numeric_limits<unsigned long>::min() << " to " << numeric_limits<unsigned long>::max() << endl;
	cout << endl;
	cout << "The range for type float is from " << numeric_limits<float>::min() << " to " << numeric_limits<float>::max() << endl;
	cout << endl;
	cout << "The range for type double is from " << numeric_limits<double>::min() << " to " << numeric_limits<double>::max() << endl;
	cout << endl;
	cout << "The range for type long double is from " << numeric_limits<long double>::min() << " to " << numeric_limits<long double>::max() << endl;
	cout << "The range for type unsigned long double is from " << numeric_limits<unsigned long double>::min() << " to " << numeric_limits<unsigned long double>::max() << endl;
	cout << endl;

	return 0;
}
