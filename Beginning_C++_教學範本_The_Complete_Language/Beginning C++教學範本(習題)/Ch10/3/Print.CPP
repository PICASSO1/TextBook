#include <iostream>
#include <string>

namespace print1
{
	void Print(const std::string &s)
	{
		std::cout << "Print1 NameSpace Version: ";
		std::cout << s << std::endl;

		return;
	}
}

namespace print2
{
	void Print(const std::string &s)
	{
		std::cout << "Print2 NameSpace Version: ";
		std::cout << s << std::endl;

		return;
	}
}
