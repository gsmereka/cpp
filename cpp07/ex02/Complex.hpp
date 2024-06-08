#ifndef COMPLEX_HPP
# define COMPLEX_HPP

# include <iostream>

class Complex
{
    public:
        Complex();
        Complex(int number);
        Complex(const Complex &other);
        Complex& operator=(const Complex &other);
        ~Complex();
        int     getNumber();
    private:
        int     number;
};

std::ostream& operator<<(std::ostream &out, Complex &c);
#endif