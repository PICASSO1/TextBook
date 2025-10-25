#include <iostream>
#include "MyString.H"
#include <cstdlib>
#include <cstring>

using namespace std;

mystring::mystring(void)      // ⊿Τ把计篶ㄧ计!!
{
	nLen = 0;
	ptr = new char[nLen + 1];
//	memset(ptr, '\0', sozeof(ptr));
	*ptr = '\0';
}
//=================================================================
mystring::mystring(char *STR)      // 肚﹃秈ㄓ篶ㄧ计!!
{
	nLen = strlen(STR);
	ptr = new char[nLen + 1];
	strcpy(ptr, STR);
}
//=================================================================
mystring::mystring(const char cKey, const int Count)      // 肚じの滦Ω计篶ㄧ计!!
{
	nLen = Count;
	ptr = new char[nLen + 1];
	for(int i(0); i<Count; i++)
		ptr[i] = cKey;
	ptr[Count] = '\0';
}
//=================================================================
mystring::mystring(const int NUM, const int Index)      // 肚计の膀计篶ㄧ计!!
{
	ptr = new char[10];
	memset(ptr, '\0', sizeof(ptr));

	itoa(NUM, ptr, Index);
	nLen = strlen(ptr);
}
//=================================================================
mystring::~mystring(void)      // 秆篶ㄧ计!!
{
	if(ptr == 0)
	{
		delete []ptr;
		ptr = 0;
	}
}
//=================================================================
mystring::mystring(const mystring &STR)      // 滦籹篶ㄧ计!!
{
	nLen = STR.nLen;
	ptr = new char[nLen + 1];
	strcpy(ptr, STR.ptr);
}
//=================================================================
int mystring::find(char *STR)
{
	int LEN(0), i(0), n(0);
	LEN = strlen(STR);
	if((LEN==1) && (nLen==1))      // ボ璶穓碝の砆穓碝琌じ!!
	{
		for(i=0; i<nLen; i++)
		{
			if(STR[0] == ptr[i])
				return i+1;      // т碞肚琌材碭!!
		}
	}
	else if((LEN!=1) && (nLen==1))      // ボ璶穓碝琌﹃砆穓碝琌じ!!
		;
	else     // ボ璶穓碝の砆穓碝琌﹃!!
	{
		for(i = 0; i<(strlen(ptr)-LEN); i++)
		{
			n = strncmp(ptr+i, STR, LEN);
			if(n == 0)
				return i+1;
		}
	}

	return -1;      // ⊿т碞肚-1
}
//	琌13彻策肈!!
//	琌14彻策肈!!
mystring &mystring::operator =(const mystring &STRING)
{
	if(this == &STRING)
		return *this;

	delete []ptr;
	ptr = new char[STRING.nLen + 1];
	strcpy(this->ptr, STRING.ptr);
	nLen = STRING.nLen;

	return *this;
}
//=================================================================
mystring mystring::operator +(const mystring &STRING)
{
	char *ptrTemp = new char[(this->nLen) + STRING.nLen + 1];
	memset(ptrTemp, '\0', sizeof(ptrTemp));
	strcpy(ptrTemp, this->ptr);
	strcat(ptrTemp, STRING.ptr);
	mystring UUU(ptrTemp);
	delete []ptrTemp;

	return UUU;
}
//=================================================================
mystring &mystring::operator +=(const mystring &STRING)
{
	char *Temp = new char[(this->nLen) + (STRING.nLen) + 1];
	memset(Temp, '\0', sizeof(Temp));
	strcpy(Temp, this->ptr);
	strcat(Temp, STRING.ptr);
	strcpy(this->ptr, Temp);
	delete []Temp;
	this->nLen = strlen(Temp);

	return *this;
}
//=================================================================
char &mystring::operator [](int RET) const
{
	if(RET < 0)
		exit(1);

	return (this->ptr)[RET];
}
//=================================================================
bool mystring::operator ==(const mystring &STRING)
{
	int nRet = strcmp(this->ptr, STRING.ptr);
	if(nRet == 0)
		return true;
	else
		return false;
}
//=================================================================
bool mystring::operator !=(const mystring &STRING)
{
	int nRet = strcmp(this->ptr, STRING.ptr);
	if(nRet != 0)
		return true;
	else
		return false;
}
//=================================================================
bool mystring::operator >(const mystring &STRING)
{
	return (this->nLen) > (STRING.nLen);
}
//=================================================================
bool mystring::operator <(const mystring &STRING)
{
	return (this->nLen) < (STRING.nLen);
}
//=================================================================
mystring mystring::operator ()(const int start, const int LEN)
{
	if((start + LEN > nLen) || (start > nLen) || (start < 0))
		exit(1);

	char *Temp = new char[LEN];
	strncpy(Temp, (this->ptr) + start, LEN);
	mystring III(Temp);
	delete []Temp;

	return III;
}
