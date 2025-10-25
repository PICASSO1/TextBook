#include <iostream>
#include <string>
// Quick Sort 範例!!
using namespace std;

void swap(string *pStr[], int first, int second);
void sort(string *pStr[], int start, int end);
int countWords(const string &text, const string &separators);
void extractWords(string *pStr[], const string &text, const string &separators);
void showWords(string *pStr[], int count);

int main(void)
{
	string text;
	const string separators(" ,.\"\n");

	cout << "Enter a string terminated by #: " << endl;
	getline(cin, text, '#');

	int word_count(countWords(text, separators));
	if(word_count == 0)
	{
		cout << endl;
		cout << "No words in text. " << endl;
		return 0;
	}
	string **pWords = new string *[word_count];
	extractWords(pWords, text, separators);
	sort(pWords, 0, word_count-1);
	showWords(pWords, word_count);
	for(int i(0); i<word_count; i++)
		delete pWords[i];

	delete []pWords;

	return 0;
}
//=====================================================================================
void swap(string *pStr[], int first, int second)
{
	string *temp = pStr[first];
	pStr[first] = pStr[second];
	pStr[second] = temp;

	return;
}
//=====================================================================================
void sort(string *pStr[], int start, int end)
{
	if(!(start < end)) //??
		return;
	swap(pStr, start, (start+end)/2);

	int current(start);
	for(int i(start+1); i<=end; i++)
	{
		if(*(pStr[i]) < *(pStr[start]))
			swap(pStr, ++current, i);
	}
	swap(pStr, start, current);
	sort(pStr, start, current-1);
	sort(pStr, current+1, end);

	return;
}
//=====================================================================================
int countWords(const string &text, const string &separators) // 計算所輸入的字串裡，有幾個單字!!
{
	int start(text.find_first_not_of(separators));
	int end(0), word_count(0);
	while(start != string::npos)
	{
		end = text.find_first_of(separators, start+1);
		if(end == string::npos)
			end = text.length();
		word_count++;
		start = text.find_first_not_of(separators, end+1);
	}

	return word_count;
}
//=====================================================================================
void extractWords(string *pStr[], const string &text, const string &separators)
{
	int start(text.find_first_not_of(separators));
	int end(0), index(0);

	while(start != string::npos)
	{
		end = text.find_first_of(separators, start+1);
		if(end == string::npos)
			end = text.length();
		pStr[index++] = new string(text.substr(start, end-start));
		// 把字串裡的每一個單字，都配置記憶體位置!!
		start = text.find_first_not_of(separators, end+1);
	}
	// 所以，陣列裡面所儲存的是每一個單字的記憶體位置!!

	return ;
}
//=====================================================================================
void showWords( string *pStr[], int count)
{
	const int word_per_line(5);

	cout << endl << *pStr[0];

	int word_in_line(0);
	for(int i(1); i< count; i++)
	{
		if(((*pStr[i])[0] != (*pStr[i-1])[0]) || (word_in_line++ == word_per_line))
		{
			word_in_line = 0;
			cout << endl;
		}
		cout << *pStr[i];
	}
	cout << endl;

	return;
}
