#pragma
#include <iostream>
#include "Account.H"

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	Account A;

	cout << "First audit: " << endl;
	A << "event 1";
	A << "event 2";
	A << "event 1";
	A.audit();

	cout << "Second audit: " << endl;
	A << "torpedo";
	A << "event1";
	A.audit();

	return 0;
}
