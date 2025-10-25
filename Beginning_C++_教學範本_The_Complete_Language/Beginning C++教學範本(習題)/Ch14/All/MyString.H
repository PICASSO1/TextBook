#ifndef MYSTRING_H
#define MYSTRING_H

using namespace std;

class mystring
{
private:
	int nLen;
	char *ptr;
public:
	mystring(void);
	explicit mystring(char *STR); // 註1
	mystring(const char cKey, const int Count = 1);
	mystring(const int NUM, const int Index = 10);
	~mystring(void);
	mystring(const mystring &STR);
	inline int GetnLen(void)
	{
		return nLen;
	}
	inline void Print(void)
	{
		cout << ptr << endl;
	}
	int find(char *STR);
//	以上是13章的習題!!
//	以下是14章的習題!!
	mystring &operator=(const mystring &STRING);
	mystring operator+(const mystring &STRING);
	mystring &operator+=(const mystring &STRING);
	char &operator[](int RET) const;
	bool operator==(const mystring &STRING);
	bool operator!=(const mystring &STRING);
	bool operator>(const mystring &STRING);
	bool operator<(const mystring &STRING);
	mystring operator()(const int start, const int LEN);
};
/*
第一個建構函數應宣告為explicit，因為它所傳進去的參數只有一個，為了防止該參數的資料型態被改變
為類別型態，所以要宣告為explicit!!
*/
#endif