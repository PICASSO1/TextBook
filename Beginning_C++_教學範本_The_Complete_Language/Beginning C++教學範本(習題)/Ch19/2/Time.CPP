#include <iostream>
#include <fstream>
#include <iomanip>
#include "Time.H"
#include <string>
#include <cstdlib>
#include <cstring>

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
//=============================================================================================
istream &operator>>(istream &in, Time &time)
{
	size_t nHour = 0, nMinute = 0, nSecond = 0;
	char strTemp[15], strHour[3], strMinute[3], strSecond[3];
	memset(strTemp, '\0', sizeof(char));
	memset(strHour, '\0', sizeof(char));
	memset(strMinute, '\0', sizeof(char));
	memset(strSecond, '\0', sizeof(char));
	in >> strTemp;
	strncpy(strHour, strTemp, 2);       strHour[2] = '\0';
	strncpy(strMinute, strTemp + 3, 2); strMinute[2] = '\0';
	strncpy(strSecond, strTemp + 6, 2); strSecond[2] = '\0';
	nHour = atoi(strHour);
	nMinute = atoi(strMinute);
	nSecond = atoi(strSecond);
	time.setHour(nHour);
	time.setMinute(nMinute);
	time.setSecond(nSecond);

	return in;
}

