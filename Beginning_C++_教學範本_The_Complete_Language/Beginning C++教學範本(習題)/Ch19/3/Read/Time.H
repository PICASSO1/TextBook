#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <fstream>

using namespace std;

class Time
{
private:
	size_t Hour;
	size_t Minute;
	size_t Second;
public:
	Time(size_t H = 0, size_t M = 0, size_t S = 0);
	virtual ~Time(void);
	friend ostream &operator<<(ostream &out, const Time &time);
	friend istream &operator>>(istream &in, Time &time);
	inline size_t getHour(void) const   { return Hour;   }
	inline size_t getMinute(void) const { return Minute; }
	inline size_t getSecond(void) const { return Second; }
	inline void setHour(size_t hour)     { Hour = hour;     }
	inline void setMinute(size_t minute) { Minute = minute; }
	inline void setSecond(size_t second) { Second = second; }
};

#endif