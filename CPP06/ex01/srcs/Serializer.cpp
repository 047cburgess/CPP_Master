#include "Serializer.hpp"
#include <limits>
#include <iostream>
#include <cstdlib>
#include <cerrno>

Serializer::Serializer(void)
{
	return ;
}

Serializer::Serializer(const Serializer& other)
{
	*this = other;
}

Serializer&	Serializer::operator=(const Serializer& other)
{
	(void)other;
	return (*this);
}

Serializer::~Serializer(void)
{
	return ;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* 		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
