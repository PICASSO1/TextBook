#include "CurveBall.H"
#include <iostream>
#include <exception>

using namespace std;

const char *CurveBall::what(void) const throw()
{
	return "CurveBall Exception!! ";
}
