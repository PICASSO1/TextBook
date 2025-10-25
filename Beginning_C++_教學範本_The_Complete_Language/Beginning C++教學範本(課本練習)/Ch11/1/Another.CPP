#include <iostream>

namespace std
{
	double volume(const std::Box &aBox)
	{
		return aBox.length * aBox.breadth * aBox.length;
	}
}
