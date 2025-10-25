#ifndef CURVEBALL_H
#define CURVEBALL_H
#include <exception>
#include <iostream>

using namespace std;

class CurveBall: public exception
{
public:
	const char *what(void) const throw();
};

#endif