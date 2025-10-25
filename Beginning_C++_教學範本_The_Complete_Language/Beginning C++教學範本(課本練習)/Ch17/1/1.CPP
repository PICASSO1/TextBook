#include <iostream>

using namespace std;

int main(void)
{
	for(int i(0); i<7; i++)
	{
		try
		{
			if(i<3)
				throw i;
			cout << "i not thrown-value is " << i << endl;
			if(i>5)
				throw "Here is another!! ";
			cout << "End of the try block. " << endl;
		}
		catch(const int i)
		{
			cout << "i caught-value is " << i << endl;
		}
		catch(const char *pMessage)
		{
			cout << "\"" << pMessage << "\" caught " << endl;
		}
		cout << "End of the for loop(after the catch blocks) - i is " << i << endl;
	}

	return 0;
}
