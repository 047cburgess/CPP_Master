#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include "Data.hpp"
# include <stdint.h>

class	Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
	public:
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};

#endif
