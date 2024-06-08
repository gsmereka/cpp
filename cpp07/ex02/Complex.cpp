#include "Complex.hpp"

Complex::Complex() : number(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Complex::Complex(int number) : number(number)
{
    // std::cout << "Parameterized constructor called" << std::endl;
}

Complex::Complex(const Complex &other) : number(other.number)
{
    // std::cout << "Copy constructor called" << std::endl;
}

Complex& Complex::operator=(const Complex &other)
{
    if (this != &other)
    {
        number = other.number;
    }
    // std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Complex::~Complex()
{
    // std::cout << "Destructor called" << std::endl;
}

// Getters
int Complex::getNumber()
{
    return number;
}

// Operador de saída
std::ostream& operator<<(std::ostream &out, Complex &c)
{
    out << c.getNumber();
    return out;
}
