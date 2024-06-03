#include "../headers/Data.hpp"

// constructor
Data::Data() : value("Nescau Serial") {}

Data::Data(const Data &src)
{
	*this = src;
}


// destructor
Data::~Data() {}

// overload
Data &Data::operator=(Data const &src)
{
	if (this != &src)
	{
		*this = src;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Data const &i)
{
	o << i.getValue();
	return (o);
}

// getters
std::string	Data::getValue(void) const
{
	return (value);
}
