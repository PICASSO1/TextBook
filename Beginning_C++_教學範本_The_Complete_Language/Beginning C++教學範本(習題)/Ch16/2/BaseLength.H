#ifndef BASELENGTH_H
#define BASELENGTH_H

using namespace std;

class BaseLength
{
public:
	explicit BaseLength(double MINIMETER = 1.0);
	virtual ~BaseLength(void);
	virtual double length(void);
	virtual double getData(void) const = 0;
protected:
	double nMinimeter;
};
//==========================================================================
class Inches: public BaseLength
{
public:
	explicit Inches(double INCHES = 2.0);
	~Inches(void);
	virtual double length(void);
	virtual double getData(void) const;
};
//==========================================================================
class Meters: public BaseLength
{
public:
	explicit Meters(double METERS = 3.0);
	~Meters(void);
	virtual double length(void);
	virtual double getData(void) const;
};
//==========================================================================
class Yards: public BaseLength
{
public:
	explicit Yards(double YARDS = 4.0);
	~Yards(void);
	virtual double length(void);
	virtual double getData(void) const;
};
//==========================================================================
class Perches: public BaseLength
{
public:
	explicit Perches(double PERCHES = 5.0);
	~Perches(void);
	virtual double length(void);
	virtual double getData(void) const;
};

#endif