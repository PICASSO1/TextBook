#ifndef ARRAY_H
#define ARRAY_H
#include <stdexcept>

using namespace std;

template<typename T> class Array
{
private:
	T *elements;
	size_t size;
public:
	explicit Array(size_t arraySize);
	Array(const Array &theArray);
	~Array(void);
	T &operator[](size_t index);
	const T &operator[](size_t index) const;
	Array &operator=(const Array &theArray);
};
//===============================================================================================
template<typename T> Array<T>::Array(size_t arraySize)
{
//	cout << "Array Constructor!! " << endl;
	size = arraySize;
	elements = new T[size];
}
//----------------------------------------------------------------------------------------------
template<typename T> Array<T>::Array(const Array &theArray)
{
//	cout << "Array Copy Constructor!! " << endl;
	size = theArray.size;
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
template<typename T> T &Array<T>::operator[](size_t index)
{
	if(index<0 || index>=size)
		throw out_of_range(index< 0? "Negative index": "Index too large");
	
	return elements[index];
}
//-----------------------------------------------------------------------------------------------
template<typename T>const T &Array<T>::operator[](size_t index) const
{
	if(index < 0 || index >= size)
		throw out_of_range(index< 0? "Negative index": "Index too large");
	
	return elements[index];
}
//-----------------------------------------------------------------------------------------------
template <typename T> Array<T> &Array<T>::operator=(const Array &theArray)
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
