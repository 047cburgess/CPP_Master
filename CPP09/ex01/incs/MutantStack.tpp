#include "MutantStack.hpp"
#include "utils.hpp"

template <class T>
MutantStack<T>::MutantStack(void): std::stack<T>()
{
};

template <class T>
MutantStack<T>::MutantStack(const MutantStack& other): std::stack<T>(other)
{
};

template <class T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack& other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return (*this);
};

template <class T>
MutantStack<T>::~MutantStack(void)
{
};

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return (this->c.begin());
};

template <class T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{
	return (this->c.begin());
};

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (this->c.end());
};

template <class T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const
{
	return (this->c.end());
};
