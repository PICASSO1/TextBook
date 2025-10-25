#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H
#include <iostream>
#include "Box.H"

using namespace std;

typedef list<Box> Contents;
typedef Contents::const_iterator const_iterator;

class TruckLoad
{
private:
	Contents Load;
public:
	inline TruckLoad(void) { }
	inline TruckLoad(const Box &one_box): Load(1, one_box) { }
	template<typename FwdIter>TruckLoad(FwdIter first, FwdIter last): Load(first, last) { }
	void add_box(const Box &new_box) { Load.push_back(new_box); }
	const_iterator begin(void) const { return Load.begin(); }
	const_iterator end(void) const   { return Load.end();   }
};

#endif