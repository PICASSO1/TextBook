#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

extern float phi;
extern int count;
//extern const double pi;
//extern const string days[];
extern double pi;
extern string days[];

int main(void)
{
	cout << setprecision(3) << fixed;
	cout << "To 3 decimal places..." << endl;
	cout << "...a circle with a diameter of phi has an area of " << pi*phi*phi/4 << endl;
	cout << "...phi squared is " << phi*phi << endl;
	cout << "...in fact, phi+1 is also " << phi+1 << endl;
	cout << "Value of count is " << count << endl;
	count+=3;
	cout << "Today is " << days[count] << endl;

	return 0;
}
