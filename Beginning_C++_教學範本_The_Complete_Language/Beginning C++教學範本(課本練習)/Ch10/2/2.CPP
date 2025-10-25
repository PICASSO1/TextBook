#include <iostream>
#include <string>

namespace data
{
	extern const double pi;
	extern const std::string days[];
}

using namespace data;

int main(void)
{
	std::cout << "pi has the value " << pi << std::endl;
	std::cout << "The second day of the week is " << days[1] << std::endl;

	return 0;
}
