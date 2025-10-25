#include <iostream>

using namespace std;

int main(void)
{
	int mice(0), brown(0), white(0);

	cout << "How many brown mice do you have?? ";
	cin >> brown;
	cout << "How many white mice do you have?? ";
	cin >> white;

	mice=brown+white;
	cout << "You have " << mice << (mice==1? " mouse": " mice") << " in total." << endl;

	return 0;
}
