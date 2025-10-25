#include <iostream>

using namespace std;

int main(void)
{
	const long feet_per_yard(3), inches_per_foot(12);
	double yards(0.0);
	long yds(0L), ft(0L), ins(0L);

	cout << "Enter a length in yards as a decimal: ";
	cin >> yards;
	yds = static_cast<long>(yards);
	ft = static_cast<long>((yards - yds) * feet_per_yard);
	ins = static_cast<long>(yards * feet_per_yard * inches_per_foot) % inches_per_foot;
	cout << endl
	     << yards << " yards converts to "
		 << yds << " yards "
		 << ft << " feet "
		 << ins << " inches " << endl;

	return 0;
}
