#include "SizeBox.H"
#include <iostream>

using namespace std;

int SizeBox::TotalSize(void)
{
	size_t a = sizeof(length);
	size_t b = sizeof(breadth);
	size_t c = sizeof(height);
	size_t d = sizeof(pMaterial);

	return (a + b + c + d);
}
