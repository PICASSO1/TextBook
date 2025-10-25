#ifndef INTEGER_H
#define INTEGER_H

using namespace std;

class Integer
{
private:
	int nRet;
public:
	Integer(void)
	{
		cout << "硂琌硓筁⊿Τ把计篶ㄧ计┮玻ネ: ";
		nRet = 0;
	}
	Integer(int RET)
	{
		cout << "硂琌硓筁Τ把计篶ㄧ计┮玻ネ: ";
		nRet = RET;
	}
	int getnRet(void)
	{
		return nRet;
	}
};
//=================================================================
int Call_by_Value(Integer RET);
int Call_by_Reference(Integer &RET);

#endif