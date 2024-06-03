#include "../headers/Serializer.hpp"

// constructor
Serializer::Serializer() {}
Serializer::Serializer(const Serializer &src)
{
	*this = src;
}

// destructor
Serializer::~Serializer() {}

// overload
Serializer &Serializer::operator=(Serializer const &src)
{
	if (this != &src)
	{
		*this = src;
	}
	return (*this);
}

// methods
uintptr_t	Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
