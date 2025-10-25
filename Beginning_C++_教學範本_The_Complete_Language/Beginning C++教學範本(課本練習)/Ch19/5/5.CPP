#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#define FileName "../ABC.TXT"
#include "FunC.H"

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	int nprimes = 0, count = 0, tries = 0;
	long lastprime = 0;

	cout << "How many primes would you like(at least 3)??";
	do
	{
		if(tries == 0)
			cout << endl << "You must request at least 3, try again: ";
		cin >> nprimes;
		if(++tries == 5)
		{
			cout << endl << "I give up!! " << endl;
			return 1;
		}
	}while(nprimes < 3);

	ifstream inFile;
	inFile.open(FileName, ios::in | ios::binary);
	cout << endl;
	if(inFile.fail() == false)     // 檢查檔案串流是否正常；false表示正常!!
	{
		do
		{
			read(inFile, lastprime);
			cout << (count++ % 5 == 0? "\n": "") << setw(10) << lastprime;
		}while(count < nprimes && inFile.eof() != true);
		inFile.close();
	}
	inFile.clear();     // 清除檔案串流中的錯誤!!

	try
	{
		ofstream outFile;
		if(count == 0)
		{
			outFile.open(FileName, ios::out | ios::binary | ios::app);
			if(outFile.is_open() == false)      // 檢查檔案是否正常開啟!!
			{
				throw ios::failure(string("Error open out put file ") + string(FileName) + string(" in main() "));
//				throw ios::fail(string("Error open out put file ") + string(ABC) + string(" in main() "));
			}
			write(outFile, 2);
			write(outFile, 3);
			write(outFile, 5);
			outFile.close();
			cout << setw(10) << 2 << setw(10) << 3 << setw(10) << 5;
			lastprime = 5;
			count = 3;
		}
		while(count < nprimes)
		{
			lastprime = nextprime(lastprime, FileName);
			outFile.open(FileName, ios::out | ios::binary | ios::app);
			if(outFile.is_open() == false)
			{
				throw ios::failure(string("Error open out put file ") + string(FileName) + string(" in main() "));
//				throw ios::fail(string("Error open out put file ") + string(ABC) + string(" in main() "));
			}
			write(outFile, lastprime);
			outFile.close();
			cout << (count++ % 5 == 0? "\n": "") << setw(10) << lastprime;
		}
		cout << endl;
		return 0;
	}
	catch(exception &EX)
	{
		cout << endl << typeid(EX).name() << ": " << EX.what();
	}

	return 0;
}
