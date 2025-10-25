//#include "Another.H"

namespace compare
{
	template<class A, class B>void normalize(A *data, B *newData, int size)
	{
		A minValue = min(data, size);
		for(int i(0); i<size; i++)
			newData[i] = static_cast<B>(data[i]-minValue);

		B maxValue = max(newData, size);
		for(int j(0); j<size; j++)
			newData[j] /= maxValue;

		return;
	}
}
