#include <iostream>

using namespace std;

int main(void)
{
	enum Language{English, French, German, Italian, Spanish};

	cout << "Possible languages are: " << endl
	     << English << ". English" << endl
		 << French << ". French" << endl
		 << German << ". German" << endl
		 << Italian << ". Italian" << endl
		 << Spanish << ". Spanish" << endl;

	Language tongue = German;
	tongue = static_cast<Language>(tongue+1);
	cout << endl << "Current language is now " << tongue << endl;

	return 0;
}
