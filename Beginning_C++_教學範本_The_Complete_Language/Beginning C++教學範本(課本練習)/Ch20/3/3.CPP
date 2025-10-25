#include <iostream>
#include <vector>

using namespace std;

template<typename Iter>double average(Iter a, Iter end)
{
	double sum = 0.0;
	int count = 0;
	for(; a != end; ++count)
		sum += *a++;

	return sum / count;
}

int main(int argc, char *argv[], char *envp[])
{
	double temperature[] = {10.5, 20.0, 8.5};
	cout << "Array average = "
		 << average(temperature, temperature + (sizeof(temperature) / sizeof(temperature[0])))
		 << endl;

	vector<int> sunny;
	sunny.push_back(7);
	sunny.push_back(12);
	sunny.push_back(15);
	cout << sunny.size() << " months on record " << endl;
	cout << "average number of sunny days: ";
	cout << average(sunny.begin(), sunny.end()) << endl;

	return 0;
}
