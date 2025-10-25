#ifndef SEQUENCE_H
#define SEQUENCE_H

using namespace std;

class Sequence
{
private:
	int *nNum;
public:
	Sequence(int n = 0, int LEN = 10)
	{
		nNum = new int[LEN];      // 動態配置陣列的大小!!
		for(int i = 0; i<LEN; i++)
			nNum[i] = n++;
		Print(LEN, nNum);
		delete nNum;
		nNum = 0;
		if(nNum != 0)      // 確認是否已釋放記憶體!!
			cout << "\a";
	}

	void Print(int LEN, int NUM[]);
};

#endif