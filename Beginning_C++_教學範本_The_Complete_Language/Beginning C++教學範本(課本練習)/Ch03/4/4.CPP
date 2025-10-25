#include <iostream>
#include <iomanip>

using namespace std;

// 此一範例在介紹位元運算子，位元運算與低階的I/O較有相關!!

int main(void)
{
	unsigned long red=0XFF0000UL, white=0XFFFFFFUL;

	cout << hex;
	cout.fill('0');

	cout << "Try out bitwise AND and OR operators: ";
	cout << "\nInitial value red = " << setw(8) << red;
	cout << "\nComplement ~red = " << setw(8) << ~red;
	cout << "\nInitial value white = " << setw(8) << white;
	cout << "\nComplement ~white = " << setw(8) << ~white;
	cout << "\n Bitwise AND red & white = " << setw(8) << (red & white);
	cout << "\n Bitwise OR red | white = " << setw(8) << (red | white);

	cout << "\n\nNow we can try out successive XOR operators: ";
	unsigned long mask=(red ^ white);
	cout << "\n mask = red ^ white = " << setw(8) << mask;
	cout << "\n mask ^ red = " << setw(8) << (mask ^ red);
	cout << "\n mask ^ white = " << setw(8) << (mask ^ white);

	unsigned long flags=0XFF, bit1mask=0X1, bit6mask=0X20, bit20mask=0X80000;
	cout << "\n\nNow use masks to select or set a particular flag bit. ";
	cout << "\nSelect bit 1 from flags: " << setw(8) << (flags & bit1mask);
	cout << "\nSelect bit 6 from flags: " << setw(8) << (flags & bit6mask);
	cout << "\nSwitch off bit 6 in flags: " << setw(8) << (flags &= ~bit6mask);
	cout << "\nSwitch off bit 20 in flags: " << setw(8) << (flags |= bit20mask);
	cout << endl;

	return 0;
}
