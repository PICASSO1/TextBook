#include <iostream>
#include <cstring>
#include "ErrorMessage.H"

using namespace std;

ErrorMessage::ErrorMessage(const char *pText)      // Constructor
{
	pMessage = new char[strlen(pText) + 1];
	strcpy(pMessage, pText);
}
//========================================================================
ErrorMessage::~ErrorMessage(void)      // Destructor
{
	cout << "Destructor called!! " << endl;
	delete []pMessage;
	pMessage = 0;
}
//========================================================================
void ErrorMessage::resetMessage(void)
{
	for(char *temp = pMessage; *temp != '\0'; *(temp++) = '*')
		;
}
//========================================================================
ErrorMessage &ErrorMessage::operator =(const ErrorMessage &message)
{
	if(this == &message)
		return *this;

	delete []pMessage;
	pMessage = new char[strlen(message.pMessage) + 1];
	strcpy(pMessage, message.pMessage);

	return *this;
}
