#include <iostream>
#include <fstream>
#include <iomanip>
#include "Time.H"

using namespace std;

Time::Time(size_t H, size_t M, size_t S)
{
	Hour = H;
	Minute = M;
	Second = S;
}
//=============================================================================================
Time::~Time(void)
{
}
//=============================================================================================
ostream &operator<<(ostream &out, const Time &time)
{
	return out << time.getHour() << ":" << time.getMinute() << ":" << time.getSecond() << endl;
}
