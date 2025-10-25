#ifndef ARRAY_H
#define ARRAY_H
#include <stdexcept>

using namespace std;

template<typename T, long startIndex> class Array
{
private:
	T *elements;
	size_t size;
//	long start;
public:
//	explicit Array(size_t arraySize, long startIndex = 0);
	explicit Array(size_t arraySize);
	Array(const Array &theArray);
	~Array(void);
	T &operator[](long index);
	const T &operator[](long index) const;
	Array &operator=(const Array &theArray);
};
//===============================================================================================
template<typename T, long startIndex> Array<T, startIndex>::Array(size_t arraySize): size(arraySize)
{
//	cout << "Array Constructor!! " << endl;
//	size = arraySize;
	elements = new T[size];
}
//----------------------------------------------------------------------------------------------
template<typename T, long startIndex> Array<T, startIndex>::Array(const Array &theArray)
{
//	cout << "Array Copy Constructor!! " << endl;
	size = theArray.size;
	elements = new T[size];
	for(int i(0); i<size; i++)
		elements[i] = theArray.elements[i];
}
//----------------------------------------------------------------------------------------------
template<typename T, long startIndex> Array<T, startIndex>::~Array()
{
//	cout << "Array Destructor!! " << endl;
	delete []elements;
	elements = 0;
}
//----------------------------------------------------------------------------------------------
template<typename T, long startIndex> T &Array<T, startIndex>::operator[](long index)
{
	if(index<startIndex || index>=startIndex + static_cast<long>(size) - 1)
		throw out_of_range(index< startIndex? "Index too small": "Index too large");
	
	return elements[index - startIndex];
}
//-----------------------------------------------------------------------------------------------
template<typename T, long startIndex>const T &Array<T, startIndex>::operator[](long index) const
{
	if(index<startIndex || index>=startIndex + static_cast<long>(size) - 1)
		throw out_of_range(index< startIndex? "Index too small": "Index too large");
	
	return elements[index - startIndex];
}
//-----------------------------------------------------------------------------------------------
template <typename T, long startIndex> Array<T, startIndex> &Array<T, startIndex>::operator=(const Array &theArray)
{
	if(this == &theArray)
		return *this;
	if(elements)
		delete []elements;
	
	size = theArray.size;
	elements = new T[size];
	for(int i(0); i<size; i++)
		elements[i] = theArray.elements[i];
}

#endif
