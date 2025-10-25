#ifndef BEAN_H
#define BEAN_H
#include <iostream>
#include <string>
#include "Account.H"

using namespace std;

class Bean
{
private:
	static Account log;
public:
	Bean(void)
	{
		log << "Default Constructor!! ";
	}
	Bean(const Bean &x)
	{
		log << "Copy Constructor!! ";
	}
	Bean &operator=(const Bean &x)
	{
		log << ((this == &x)? "self_assignment": "assignment");
		return *this;
	}
	~Bean(void)
	{
		log << "Destructor!! ";
	}
	bool operator==(const Bean &x) const
	{
		log << "equality_test";
		return false;
	}
	bool operator<(const Bean &x) const
	{
		log << "operator_less";
		return false;
	}
	friend void clear_bean_log(void)
	{
		log.clear();
	}
	friend void usage_report(const string &caption = "")
	{
		if(!caption != "")
			cout << caption << end;
		log.audit();
		cout << "-end-" << endl;
		log.clear();
	}
};
