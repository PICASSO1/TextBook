#ifndef INTEGER_H
#define INTEGER_H

using namespace std;

class Integer
{
private:
	int nRet;
public:
	Integer(int RET = 0)      // Constructor.
	{
		nRet = RET;
	}
	int GetnRet(void);
	void SetnRet(int RET);
};

#endif