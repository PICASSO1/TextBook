#include "Bean.H"

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	Bean A, B;
	A = B;

	if(A == B)
		cout << "All beans are created equal. " << endl << endl;

	if(A < B)
		cout << "Big trouble. " << endl;

	usage_report("assign, compare, and order ");
	Bean *pB = new Bean[10];
	delete []pB;

	usage_report("new and delete 10 elements. ");

	return 0;
}
