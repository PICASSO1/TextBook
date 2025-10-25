#include <iostream>
#include <string>
#include "PrintThis.H"
#include "PrintThat.H"
#define DO_THIS

using namespace std;

int main(void)
{
#ifdef DO_THIS
	PrintThis("Hello!! ");
#else
	PrintThat("World!! ");
#endif

	return 0;
}
