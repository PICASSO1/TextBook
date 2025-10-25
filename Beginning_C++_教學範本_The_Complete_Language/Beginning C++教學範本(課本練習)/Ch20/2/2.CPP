#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Show_Sequence(const int *first, const int *last);
void inspect_vector(const vector<int> &ref);

int main(int argc, char *argv[], char *envp[])
{
	vector<int> v;
	cout << "New vector created:               ";
	inspect_vector(v);

	cout << "Filling from array:               ";
	int values[] = {1, 3, 7, 5};
	v.insert(v.end(), values + 1, values + 3);
	inspect_vector(v);

	cout << "Appending values 5:               ";
	v.push_back(5);
	inspect_vector(v);

	cout << "Erasing elements of offset 1:     ";
	v.erase(&v[1]);
	inspect_vector(v);

	cout << "Inserting elements 4 at offset 1: ";
	v.insert(v.begin() + 1, 4);
	inspect_vector(v);

	cout << "Clearing all elements:            ";
	v.clear();
	inspect_vector(v);

	return 0;
}

void Show_Sequence(const int *first, const int *last)
{
	cout << "{ ";
	copy(first, last, ostream_iterator<int>(cout, " "));
	cout << " }" << endl;
}

void inspect_vector(const vector<int> &ref)
{
	cout << "Vector has " << ref.size() << " elements: ";
	Show_Sequence(ref.begin(), ref.end());
}