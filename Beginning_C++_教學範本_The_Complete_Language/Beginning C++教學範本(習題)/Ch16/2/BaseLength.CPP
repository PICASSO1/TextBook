#include <iostream>
#include "BaseLength.H"

using namespace std;

BaseLength::BaseLength(double MINIMETER): nMinimeter(MINIMETER) {}
BaseLength::~BaseLength(void)
{
//	cout << "BaseLength Destructor!! " << endl;
}
//--------------------------------------------------------------------------
double BaseLength::length(void)
{
	return nMinimeter;
}
//==========================================================================
Inches::Inches(double INCHES): BaseLength(INCHES) {}
Inches::~Inches(void)
{
//	cout << "Inches Destructor!! " << endl;
}
//--------------------------------------------------------------------------
double Inches::length(void)
{
	return nMinimeter * 25.4;
}
//--------------------------------------------------------------------------
double Inches::getData(void) const {	return nMinimeter; }
//==========================================================================
Meters::Meters(double METERS): BaseLength(METERS) {}
Meters::~Meters(void)
{
//	cout << "Meters Destructor!! " << endl;
}
//--------------------------------------------------------------------------
double Meters::length(void)
{
	return nMinimeter * 1000;
}
//--------------------------------------------------------------------------
double Meters::getData(void) const {	return nMinimeter; }
//==========================================================================
Yards::Yards(double YARDS): BaseLength(YARDS) {}
Yards::~Yards(void)
{
//	cout << "Yards Destructor!! " << endl;
}
//--------------------------------------------------------------------------
double Yards::length(void)
{
	return nMinimeter * 36 * 25.4;
}
//--------------------------------------------------------------------------
double Yards::getData(void) const {	return nMinimeter; }
//==========================================================================
Perches::Perches(double PERCHES): BaseLength(PERCHES) {}
Perches::~Perches(void)
{
//	cout << "Perches Destructor!! " << endl;
}
//--------------------------------------------------------------------------
double Perches::length(void)
{
	return nMinimeter * 5.5 * 36 * 25.4;
}
//--------------------------------------------------------------------------
double Perches::getData(void) const {	return nMinimeter; }