#ifndef SEQUENCE_H
#define SEQUENCE_H
#define SIZE 20

using namespace std;

class Sequence
{
private:
	int nLen;
	int nNum[SIZE];
public:
	Sequence(int n = 0, int LEN = 10)
	{
		nLen = LEN;
		for(int i(0); i<LEN; i++)
			nNum[i] = n++;
		Print(LEN, nNum);
	}

	void Print(int LEN, int NUM[]);
	int Compare(Sequence SEQ);
};

#endif