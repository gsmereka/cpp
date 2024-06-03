#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# include <iostream>
# include <iomanip>
# include <limits>
# include <cstdlib>
# include <cerrno>
# include <cmath>

class ScalarConverter
{
	public:
		static void convert(const std::string &input);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();

		// aux functions
		static bool	tryConvertToChar(const std::string &input);
		static bool tryConvertToInt(const std::string &input);
		static bool tryConvertToFloat(const std::string &input);
		static bool tryConvertToDouble(const std::string &input);
		static bool checkPseudoLiterals(const std::string &input);
};

#endif // SCALARCONVERTER_HPP
