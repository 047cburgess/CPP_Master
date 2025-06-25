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

}

Data* 		Serializer::deserialize(uintptr_t raw)
{

}
