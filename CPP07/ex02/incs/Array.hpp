#pragma once
#include <iostream>

template <class T>
class	Array
{
	private:
		T* _elements;
		unsigned int _size;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array(void);

		unsigned int size(void) const;
		T& operator[](unsigned int index);	
		const T& operator[](unsigned int index) const;	
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Array<T>& rhs)
{
	for (unsigned int i = 0; i < rhs.size(); i++)
	{
		os << "[" << rhs[i] << "]-";
	}
	os << std::endl;
	return (os);
}

#include "Array.tpp"
