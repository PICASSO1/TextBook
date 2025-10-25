#pragma
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

typedef map<string, int> Ledger;

class Account
{
private:
	Ledger L;
public:
	Account(void) { }
	void clear(void) { L.clear(); }
	Account &operator<<(const string &Iter)
	{
		L[Iter]++;

		return *this;
	}
	void audit(void) const
	{
		Ledger::const_iterator iter;
		for(iter = L.begin(); iter != L.end(); ++iter)
			cout << setw(7) << iter->second << " " << iter->first << endl;
	}
};

#endif