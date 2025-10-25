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
	delete []ptr;
	ptr = 0;
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
