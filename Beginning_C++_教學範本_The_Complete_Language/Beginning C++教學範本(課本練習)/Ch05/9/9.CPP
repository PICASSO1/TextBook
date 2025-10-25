#include <iostream>
#include <iomanip>
#include <cctype>
#include <limits>

using namespace std;

int main(void)
{
	cout << setw(13) << "Character " << setw(13) << "Hexadecimal " << setw(13) << "Decimal "
		 << endl;
	cout << uppercase;

	unsigned char ch('\0');

	do
	{
		if(!isprint(ch))
			continue;
		cout << setw(7) << ch << hex
			 << setw(13) << static_cast<int>(ch) << dec
			 << setw(13) << static_cast<int>(ch) << endl;
	}while(ch++ < numeric_limits<unsigned char>::max());

	return 0;
}
