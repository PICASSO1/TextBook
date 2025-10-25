#include <iostream>

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	cout << "硂や祘Αす砛ㄏノ块2~4㏑把计盢把计!! " << endl;
	if(argc<2 || argc>4)
	{
		cout << "块岿粇!! " << endl;
		exit(1);
	}
	else
	{
		for(int i(0); i<argc; i++)
			cout << argv[i] << endl;
	}

	return 0;
}
