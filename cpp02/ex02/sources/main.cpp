#include "../headers/Fixed.hpp"

// SUBJECT MAIN
// int main(void)
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }

int main()
{
    Fixed a(2.5f);
    Fixed b(3.5f);

	std::cout << a << " / " << b << " = " << (a / b) << std::endl;
	
    // Ativando o manipulador std::boolalpha para imprimir true/false
    std::cout << std::boolalpha;

    // Demonstrando min e max
    std::cout << "Min between " << a << " and " << b << " is " << Fixed::min(a, b) << std::endl;
    std::cout << "Max between " << a << " and " << b << " is " << Fixed::max(a, b) << std::endl;

    // Demonstrando operadores de comparação
    std::cout << a << " > " << b << " : " << (a > b) << std::endl;
    std::cout << a << " >= " << b << " : " << (a >= b) << std::endl;
    std::cout << a << " < " << b << " : " << (a < b) << std::endl;
    std::cout << a << " <= " << b << " : " << (a <= b) << std::endl;
    std::cout << a << " == " << b << " : " << (a == b) << std::endl;
    std::cout << a << " != " << b << " : " << (a != b) << std::endl;

    // Demonstrando operadores aritméticos
    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
    std::cout << a << " - " << b << " = " << (a - b) << std::endl;
    std::cout << a << " * " << b << " = " << (a * b) << std::endl;
    std::cout << a << " / " << b << " = " << (a / b) << std::endl;

    // Demonstrando incremento e decremento
    std::cout << "a++ : " << a++ << " => " << a << std::endl;
	
    std::cout << "++a : " << ++a << std::endl;
	
    std::cout << "a-- : " << a-- << " => " << a << std::endl;
    std::cout << "--a : " << --a << std::endl;
	
    return 0;
}
