#include <iostream>
#include <cstring>      // new!!
#include <cctype>

using namespace std;

int main(void)
{
//	int height[10];
	int *height=NULL;      // new!!
	int count(0);
	char reply('\0');
	height = new int[10];
	memset(height, 0, sizeof(int)*10);      // new!!

	do
	{
		cout << "Enter a height as an integral number of inches: ";
		cin >> height[count++];
		cout << "Do you want to enter another(y or n)? ";
		cin >> reply;
	}while(count<10 && tolower(reply)=='y');
	if(count==10)
		cout << endl << "Maximum height count reached. " << endl;

	double average(0.00000);
	for(int i(0); i<count; i++)
		average += height[i];
	average /= count;
	cout << endl << "Average height is " << average << " inches" << endl;

	int above_average(0);
	for(int j(0); j<count; j++)
	{
		if(height[j]>average)
			above_average++;
	}
	cout << "There " << (above_average==1? "is ": "are ") << above_average << " height"
		 << (above_average==1? "": "s ") << "above average. " << endl;
	delete []height;      // new!!
	height = 0;      // new!!

	return 0;
}
