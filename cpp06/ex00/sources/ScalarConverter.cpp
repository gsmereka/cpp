#include "../headers/ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &input)
{
    if (tryConvertToChar(input))
        return;
    else if (tryConvertToInt(input))
        return;
    else if (tryConvertToFloat(input))
        return;
    else if (tryConvertToDouble(input))
        return;
    else if (checkPseudoLiterals(input))
        return;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

// aux functionss
bool ScalarConverter::tryConvertToChar(const std::string    &input)
{
    if (input.length() != 1)
        return false;
    if (!isprint(input[0]))
        return false;
    if (isdigit(input[0]))
        return false;
    char myChar = static_cast<char>(*input.begin());
    std::cout << "char: " << "'" << myChar << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(myChar) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(myChar) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(myChar) << std::endl;
    return (true);
}

bool ScalarConverter::tryConvertToInt(const std::string &input)
{
    char    *remainder;
    errno = 0;

    long myInt = std::strtol(input.c_str(), &remainder, 10);
    if (*remainder != '\0')
        return false;
    if (errno == ERANGE)
        return false;
    if (myInt < std::numeric_limits<int>::min())
        return false;
    if (myInt > std::numeric_limits<int>::max())
        return false;
    int i = static_cast<int>(myInt);
    std::cout << "char: ";
    if (isprint(i)) 
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
    return (true);
}

bool ScalarConverter::tryConvertToFloat(const std::string   &input)
{
    char    *remainder;
    errno = 0;

    float myFloat = std::strtof(input.c_str(), &remainder);
    if (*remainder != 'f')
        return false;
    if (remainder[1] != '\0')
        return false;
    if (errno == ERANGE)
        return false;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << myFloat << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(myFloat) << std::endl;
    return (true);
}

bool ScalarConverter::tryConvertToDouble(const std::string  &input)
{
    char    *remainder;
    errno = 0;

    double myDouble = std::strtod(input.c_str(), &remainder);
    if (*remainder != '\0')
        return false;
    if (errno == ERANGE)
        return false;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << static_cast<float>(myDouble) << "f" << std::endl;
    std::cout << "double: " << myDouble << std::endl;
    return (true);
}

bool ScalarConverter::checkPseudoLiterals(const std::string &input)
{
    if (input == "-inff" || input == "+inff" || input == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input << std::endl;
        std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
        return (true);
    }
    if (input == "-inf" || input == "+inf" || input == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input + "f" << std::endl;
        std::cout << "double: " << input << std::endl;
        return (true);
    }
    return (false);
}

// Private constructor and destructor
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}
