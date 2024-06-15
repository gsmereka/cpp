#include "../headers/BitcoinExchange.hpp"

// CONSTRUCTOR


BitcoinExchange::BitcoinExchange() :  priceMap(), priceValue(0.0), dayValue("") { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange & src)
{
	*this = src;
}


//  DESTRUCTOR
BitcoinExchange::~BitcoinExchange() { }


// OVERLOAD

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	(void)rhs;
	return *this;
}

// Validations
bool	BitcoinExchange::isLeapYear(int year)
{
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		return (true);
	return (false);
}

bool	BitcoinExchange::isValidDateFormat(const std::string &dateStr)
{
	if (dateStr.size() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
		return false;
	return true;
}

bool	BitcoinExchange::isValidYear(int year)
{
	if (year >= 2008 && year <= 2023)
		return (true);
	return (false);
}

bool	BitcoinExchange::isValidMonth(int month)
{
	if (month >= 1 && month <= 12)
		return (true);
	return (false);
}

bool BitcoinExchange::isValidDay(int day, int month, int year)
{
	bool isLeap = isLeapYear(year);
	int maxDay;

	if (month == 2)
	{
		if (isLeap)
			maxDay = 29;
		else
			maxDay = 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		maxDay = 30;
	else
		maxDay = 31;
	if (day >= 1 && day <= maxDay)
		return true;
	else
		return false;
	return false;
}

int	BitcoinExchange::defineValue(const std::string &dateStr, int startPos, int finalPos)
{
	std::string	valueStr;
	char    	*remainder;
	int			value;
	errno = 0;
	valueStr = dateStr.substr(startPos, finalPos);
	value = std::strtof(valueStr.c_str(), &remainder);
	if (remainder[0] != '\0' && remainder[0] != '-')
	{
		return (0);
	}
	if (errno == ERANGE)
		return (0);
	if (value < 0)
		return (0);
	return  atoi(valueStr.c_str());
}

bool BitcoinExchange::isValidPriceValue(const std::string &line)
{
	std::string	valueStr;
	char    	*remainder;

	errno = 0;
	valueStr = line.substr(13, line.size() - this->dayValue.size());
	this->priceValue = std::strtof(valueStr.c_str(), &remainder);
	if (remainder[0] != '\0')
	{
		std::cout << BAD_INPUT << line << std::endl;
		return (false);
	}
	if (errno == ERANGE)
	{
		std::cout << BAD_INPUT << line << std::endl;
		return (false);
	}
	if (this->priceValue < 0)
	{
		std::cout << NEGATIVE_NUMBER << std::endl;
		return (false);
	}
	if (this->priceValue > 1000)	
	{
		std::cout << LARGE_NUMBER << std::endl;
		return (false);
	}
	return(true);
}

bool BitcoinExchange::isValidDate(const std::string &line)
{
	int	year;
	int	month;
	int	day;

	this->dayValue = line.substr(0, 10);
	year = defineValue(this->dayValue, 0, 4);
	month = defineValue(this->dayValue, 5, 7);
	day = defineValue(this->dayValue, 8, 10);
	if (!isValidDateFormat(this->dayValue))
	{
		std::cout << BAD_INPUT << line << std::endl;
		return (false);
	}
	if ((year == 2009) && (month == 1) && (day == 1))
	{
		std::cout << OLD_DATE << std::endl;
		return (false);
	}
	if (!isValidYear(year) || !isValidMonth(month) || !isValidDay(day, month, year))
	{
		std::cout << BAD_INPUT << line << std::endl;
		return (false);
	}
	return true;
}

bool BitcoinExchange::isValidLine(const std::string &line)
{
	if (line.size() < 13 || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
	{
		std::cout << BAD_INPUT << line << std::endl;
		return false;
	}
	if (!isValidDate(line))
		return false;
	if (!isValidPriceValue(line))
		return false;
	return true;
}

bool	BitcoinExchange::printInputFileExchange(std::string file) 
{
	std::map<std::string, float>::iterator	it;
	std::string								key;
	float									result;
	std::string 							line;

	std::ifstream inputFile(file.c_str());
	if (!inputFile.is_open())
		return false;
	std::getline(inputFile, line, '\n');
	while (std::getline(inputFile, line, '\n'))
	{
		if (line.empty())
			std::cout << EMPTY_LINE << std::endl;
		else if (isValidLine(line))
		{
			it = this->priceMap.upper_bound(this->dayValue);
			it--;
			result = this->priceValue * (*it).second;
			std::cout << BLUE << this->dayValue << RES << " => " << this->priceValue << " = " << result << std::endl;
		}
	}
	inputFile.close();
	return true;
}

bool BitcoinExchange::getBitcoinPriceOverTime(void) 
{
	std::string		dayStr;
	std::string		valueStr;

	std::ifstream inputFile("data.csv");
	if (!inputFile.is_open())
		return false;
	while (std::getline(inputFile, dayStr, ',') && std::getline(inputFile, valueStr, '\n'))
		this->priceMap[dayStr] = atof(valueStr.c_str());
	inputFile.close();
	return true;
}

void			BitcoinExchange::exchange(char *file)
{
	if (!getBitcoinPriceOverTime())
	{
		std::cout << ERROR_FILE << std::endl;
		return ;
	}
	if (!printInputFileExchange(file))
	{
		std::cout << ERROR_FILE << std::endl;
		return ;
	}
	return ;
}
