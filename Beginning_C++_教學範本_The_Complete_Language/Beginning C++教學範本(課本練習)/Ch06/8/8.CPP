#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(void)
{
	const int max_length(6);
	string names[max_length];
	int count(0);
	char answer('\0');
	
	do
	{
		cout << "Enter a name: ";
		cin >> names[count++];

		cout << endl << "Do you want to enter another name(y/n): ";
		cin >> answer; 
	}while(count < max_length && toupper(answer)!='N');
	if(count == max_length)
		cout << "Maximum name count reached. " << endl;

	int index_of_max(0), index_of_min(0);
	for(int i(1); i<count; i++)
	{
		if(names[i] > names[index_of_max])
			index_of_max = i;
		else
			index_of_min = i;
	}
	cout << endl << "The minimum name is " << names[index_of_min];
	cout << endl << "The maximum name is " << names[index_of_max] << endl;

	return 0;
}
