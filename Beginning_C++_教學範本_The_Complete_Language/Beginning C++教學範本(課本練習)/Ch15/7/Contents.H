#ifndef CONTENTS_H
#define CONTENTS_H

using namespace std;

class Contents
{
protected:
	char *pName;
	double volume;
	double unitweight;
public:
	Contents(const char *pStr = "cereal", double weight = 0.3, double vol = 0.0);
	~Contents(void);
	double getWeight(void) const;
};

#endif