#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

inline void Show_Sequence(const string *first, const string *last)
{
	copy(first, last, ostream_iterator<string>(cout, "\n"));
}

void inspect_vector(const vector<string> &ref);

int main(int argc, char *argv[], char *envp[])
{
	string strCity;
	vector<string> v;

	while(1)
	{
		cout << "請輸入一個城市名(# to exit): ";
		cin >> strCity;
		if(strCity[0] == '#')
			break;
		v.push_back(strCity);
	}
	sort(v.begin(), v.end());  // 多加這一行來做排序!!
	cout << endl;
	inspect_vector(v);

	return 0;
}
//=============================================================================================
void inspect_vector(const vector<string> &ref)
{
	cout << "您剛剛輸入了" << ref.size() << "個城市: " << endl;
	Show_Sequence(ref.begin(), ref.end());
}
