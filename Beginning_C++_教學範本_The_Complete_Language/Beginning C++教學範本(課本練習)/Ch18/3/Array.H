#ifndef ARRAY_H
#define ARRAY_H
#include <stdexcept>

using namespace std;

template<typename T> class Array
{
private:
	T *elements;
	size_t size;
	long start;
public:
	explicit Array(size_t arraySize, long startIndex = 0);
	Array(const Array &theArray);
	~Array(void);
	T &operator[](long index);
	const T &operator[](long index) const;
	Array &operator=(const Array &theArray);
};
//===============================================================================================
template<typename T> Array<T>::Array(size_t arraySize, long startIndex): size(arraySize), start(startIndex)
{
//	cout << "Array Constructor!! " << endl;
	elements = new T[size];
}
//----------------------------------------------------------------------------------------------
template<typename T> Array<T>::Array(const Array &theArray)
{
//	cout << "Array Copy Constructor!! " << endl;
	size = theArray.size;
	start = theArray.start;
	elements = new T[size];
	for(int i(0); i<size; i++)
		elements[i] = theArray.elements[i];
}
//----------------------------------------------------------------------------------------------
template<typename T> Array<T>::~Array()
{
//	cout << "Array Destructor!! " << endl;
	delete []elements;
	elements = 0;
}
//----------------------------------------------------------------------------------------------
template<typename T> T &Array<T>::operator[](long index)
{
	if(index<start || index>static_cast<long>(size) + start - 1)
		throw out_of_range(index< start? "Index too small": "Index too large");
	
	return elements[index - start];
}
//-----------------------------------------------------------------------------------------------
template<typename T>const T &Array<T>::operator[](long index) const
{
	if(index<start || index>static_cast<long>(size) + start - 1)
		throw out_of_range(index< start? "Index too small": "Index too large");
	
	return elements[index - start];
}
//-----------------------------------------------------------------------------------------------
template <typename T> Array<T> &Array<T>::operator=(const Array &theArray)
{
	if(this == &theArray)
		return *this;
	if(elements)
		delete []elements;
	
	size = theArray.size;
	start = theArray.start;
	elements = new T[size];
	for(int i(0); i<size; i++)
		elements[i] = theArray.elements[i];
}

#endif
