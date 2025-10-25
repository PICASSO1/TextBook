#include <iostream>
#include <string>
#include "Animal.H"
#include "Sheep.H"
#include "Dog.H"
#include "Cow.H"
#define SIZE 12

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	Sheep S001("¤pºø¦Ï", 20), S002("¤jºø¦Ï", 40), S003("²Ü¦Ï", 30), S004("¤s¦Ï", 63);
	Dog D001("¶Àª÷Ây¤ü", 25), D002("¤j³ÁËm¤ü", 26), D003("§B®¦¤s¤ü", 96), D004("«¢¤h©_", 36);
	Cow C001("¤£¨}¤û", 96), C002("¤j²Â¤û", 32), C003("¤û¤û", 23), C004("Âç¤û", 52);
	Animal *ZOO[SIZE] =
	{
		&S001, &D001, &C001,
		&S002, &D002, &C002,
		&S003, &D003, &C003,
		&S004, &D004, &C004,
	};
	for(int i(0); i<SIZE ;i++)
		ZOO[i]->who();

	return 0;
}
