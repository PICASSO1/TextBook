#ifndef MYTROUBLES_H
#define MYTROUBLES_H

using namespace std;

class Trouble
{
private:
	const char *pMessage;
public:
	explicit Trouble(const char *pStr = "There's a problem. ");
	const char *what(void) const;
	~Trouble(void);
};

#endif