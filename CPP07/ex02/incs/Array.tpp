#include "Array.hpp"

#include <stdexcept>

template <class T>
Array<T>::Array(void): _elements(NULL), _size(0)
{
	
}

template <class T>
Array<T>::Array(unsigned int n): _elements(new T[n]), _size(n)
{
	for (unsigned int i = 0; i < _size; i++)
		_elements[i] = T();
}

template <class T>
Array<T>::Array(const Array& other): _elements(NULL), _size(0)
{
	*this = other;
}

template <class T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete [] _elements;
		_size = other.size();
		_elements = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_elements[i] = other[i];
	}
	return (*this);
}

template <class T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index < 0 || index >= _size)
		throw std::range_error("Exception thrown: invalid index");
	return (_elements[index]);
}

template <class T>
const T&	Array<T>::operator[](unsigned int index) const
{
	if (index < 0 || index >= _size)
		throw std::range_error("Exception thrown: invalid index");
	return (_elements[index]);
}

template <class T>
unsigned int	Array<T>::size(void) const
{
	return (_size);
}

template <class T>
Array<T>::~Array(void)
{
	delete[] _elements;
}
