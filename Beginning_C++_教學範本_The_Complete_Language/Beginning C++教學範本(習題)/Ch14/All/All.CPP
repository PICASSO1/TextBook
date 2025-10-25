#include <iostream>
#include "MyString.H"

using namespace std;

void Show(int RET, char *STR, int Flag);

int main(int argc, char *argv[], char *envp[])
{
/*	mystring s0;
	mystring s1("Hello!! World!!");
	mystring s2('c', 5), s3('A');
	mystring s4(10), s5(16, 16);

	cout << endl << "測試複製建構函數!! "<< endl;
	mystring s6(s1), s7(s2), s8(s3), s9(s4), s10(s5);

	cout << endl << "測試長度: " << endl;
	cout << "S0的長度: " << s0.GetnLen() << endl;
	cout << "S1的長度: " << s1.GetnLen() << endl;
	cout << "S2的長度: " << s2.GetnLen() << endl;
	cout << "S3的長度: " << s3.GetnLen() << endl;
	cout << "S4的長度: " << s4.GetnLen() << endl;
	cout << "S5的長度: " << s5.GetnLen() << endl;

	cout << endl << "測試列印: " << endl;
	cout << "S0的內容: "; s0.Print();
	cout << "S6的內容: "; s6.Print();
	cout << "S7的內容: "; s7.Print();
	cout << "S8的內容: "; s8.Print();
	cout << "S9的內容: "; s9.Print();
	cout << "S10的內容: "; s10.Print();

	cout << endl << "測試搜尋: " << endl;
	cout << "在S1中搜尋'W': ";    Show(s1.find("W"), "W", 1);
	cout << "在S1中搜尋'a': ";    Show(s1.find("a"), "a", 1);
	cout << "在S1中搜尋\"lo\": "; Show(s1.find("lo"), "lo", 2);
	cout << "在S1中搜尋\"! \": "; Show(s1.find("! "), "! ", 2);
	cout << "在S1中搜尋\"d!\": "; Show(s1.find("d!"), "d!", 2);
	cout << "在S2中搜尋\"Aa\": "; Show(s2.find("Aa"), "Aa", 2);
	cout << "在S3中搜尋\"D\": "; Show(s3.find("D"), "D", 2);
	cout << "在S3中搜尋\"ff\": "; Show(s3.find("ff"), "ff", 2);
	cout << "在S3中搜尋\"A\": "; Show(s3.find("A"), "A", 1);
	cout << "在S3中搜尋\"AA\": "; Show(s3.find("AA"), "AA", 2);
*/
//	以上是13章的習題!!
//	以下是14章的習題!!
	mystring s1("Hello!! ");      cout << "S1 = "; s1.Print();
	mystring s2 = s1;             cout << "S2 = "; s2.Print();
	         s1 = s1;             cout << "S1 = "; s1.Print();
	mystring s3;
	mystring s4 = s3 = s2;        cout << "S3 = "; s3.Print();
	                              cout << "S4 = "; s4.Print();
	cout << "以上為第1題的部份!!" << endl << endl;

	mystring s5("World!! ");      cout << "S5 = "; s5.Print();
	mystring s6 = s4 + s5;        cout << "S4 + S5 = "; s6.Print();
	s5 += s4; /* s5 = s5 + s4; */ cout << "S5 += S4 → "; s5.Print();
	cout << "以上為第2題的部份!!" << endl << endl;

	mystring s7("World!! ");
	cout << "S7 = "; s7.Print();
	cout << "S7[4] = " << s7[4] << endl;
	s7[4] = s5[2];   cout << "S5 = "; s5.Print();
	cout << "S7[4] =  S5[2] , S7[4] =  " << s7[4] << endl;
	cout << "以上為第3題的部份!!" << endl << endl;

	if(s1 == s2)
		cout << "S1 == S2 " << endl;
	if(s1 != s5)
		cout << "S1 != S5 " << endl;
	if(s5 > s1)
		cout << "S5 > S1 " << endl;
	if(s7 < s5)
		cout << "s7 < s5 " << endl;
	cout << "以上為第4題的部份!!" << endl << endl;

	mystring s8 = s1(2, 3);
	cout << "S8 = S1(2, 3), S8 = "; s8.Print();
	cout << "以上為第5題的部份!!" << endl << endl;

	return 0;
}
//=====================================================================
void Show(int RET, char *STR, int Flag)
{
	if(Flag == 1)      // 找的是一個字元!!
	{
		if(RET != -1)
			cout << "'" << STR[0] << "'在第 " << RET << " 個!! " << endl;
		else
			cout << "沒找到喔!! " << endl;
	}
	else      // 找的是一個字串!!
	{
		if(RET != -1)
			cout << "\"" << STR << "\"在第 " << RET << " 個!! " << endl;
		else
			cout << "沒找到喔!! " << endl;
	}

	return;
}
