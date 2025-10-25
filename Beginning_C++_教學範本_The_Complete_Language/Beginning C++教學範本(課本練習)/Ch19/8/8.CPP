#include <iostream>
#include "Box.H"
#define TEXT "../Text.TXT"
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	try
	{
		ofstream out(TEXT);
		if(!out)
			throw (ios::failure(string("Failed to open output file ") + TEXT));

		Box BigBox(50, 60, 70), SmallBox(2, 3, 4);

		out << BigBox << endl;
		out << SmallBox << endl;
		out.close();
		out.clear();
		cout << endl << "Write two box objects to the file: ";
		cout << endl << "BigBox is " << BigBox << endl;
		cout << "SmallBox is " << SmallBox << endl;

		ifstream in(TEXT);
		if(!in)
			throw (ios::failure(string("Failed to open input file ") + TEXT));

		cout << "Reading objects from the file: ";
		Box newBox;

		in >> newBox;
		cout << "First Box read is " << newBox << endl;
		in >> newBox;
		cout << "Second Box read is " << newBox << endl;
	}
	catch(exception &EX)
	{
		cout << typeid(EX).name() << ": " << EX.what() << endl;
	}

	return 0;
}
