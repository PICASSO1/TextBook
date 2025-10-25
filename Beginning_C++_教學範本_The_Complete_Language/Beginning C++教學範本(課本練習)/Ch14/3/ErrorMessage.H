#ifndef ERRORMESSAGE_H
#define ERRORMESSAGE_H

using namespace std;

class ErrorMessage
{
private:
	char *pMessage;
public:
	ErrorMessage(const char *pText = "Error");      // Constructor
	~ErrorMessage(void);      // Destructor
	void resetMessage(void);
	inline char *what(void) const
	{
		return pMessage;
	}
	ErrorMessage &operator=(const ErrorMessage &Message);
};

#endif