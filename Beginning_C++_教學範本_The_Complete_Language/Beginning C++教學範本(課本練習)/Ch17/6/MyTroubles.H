#ifndef MYTROUBLES_H
#define MYTROUBLES_H

using namespace std;

class Trouble
{
private:
	const char *pMessage;
public:
	Trouble(const char *pStr = "There's a problem ");
	virtual ~Trouble(void);
	virtual const char *what(void) const;
};
//====================================================================
class MoreTrouble: public Trouble
{
public:
	MoreTrouble(const char *pStr = "There's more trouble ");
};
//===================================================================
class BigTrouble: public MoreTrouble
{
public:
	BigTrouble(const char *pStr = "Really big trouble ");
};

#endif