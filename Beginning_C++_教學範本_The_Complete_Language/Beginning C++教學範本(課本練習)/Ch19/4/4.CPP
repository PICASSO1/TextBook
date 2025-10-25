#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	try
	{
		if(argc != 3)
			throw invalid_argument("Input and output file names required!! ");

		const string source = argv[1], target = argv[2];
		if(source == target)
			throw invalid_argument(string("Can't not copy ") + source + string(" to itself!! "));

		ifstream in(source.c_str(), ios::in | ios::binary);
		if(in.is_open() == false)
			throw ios::failure(string("Input file ") + source + string(" not found!! "));

		ifstream temp(target.c_str(), ios::in | ios::binary);
		char ch = '\0';
		if(temp)
		{
			temp.close();
			cout << endl << "Exists, do you want to overwrite it(y/n): ";
			ch = cin.get();
			if(toupper(ch) != 'Y')
				return 0;
		}
		ofstream out(target.c_str(), ios::out | ios::binary | ios::trunc);
		while(in.get(ch))
		{
			out.put(ch);
		}
		if(in.eof() == true)
			cout << endl << source << " copied to " << target << " successfully. ";
		else
			cout << endl << "Error coping file. ";

		return 0;
	}
	catch(exception &EX)
	{
		cout << endl << typeid(EX).name() << ": " << EX.what();

		return 1;
	}

	return 0;
}
