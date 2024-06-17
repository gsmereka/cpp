#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <unistd.h>
# include <map>
# include <stdlib.h>

# define RED "\x1b[38;5;88m"
# define GREEN "\x1b[38;5;40m"
# define BLUE "\x1b[38;5;25m"
# define YELLOW "\x1b[38;5;220m"
# define ORANGE	"\033[0;38;5;166m"
# define RES "\x1b[0m"
# define BAD_INPUT RED "Error: bad input => " RES
# define FUTURE_DATE RED "Error: the date is in the future." RES
# define ERROR_FILE RED "Error: could not open file." RES
# define NEGATIVE_NUMBER RED "Error: not a positive number." RES
# define LARGE_NUMBER RED "Error: too large a number." RES
# define EMPTY_LINE RED "Error: empty line." RES

class BitcoinExchange
{

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();
		BitcoinExchange		&operator=(BitcoinExchange const &rhs);

		// main function
		void				exchange(char *file);

		// aux funtions
		bool				getBitcoinPriceOverTime(void);
		bool				printInputFileExchange(std::string file);

		bool				isValidLine(const std::string &line);
		int					defineValue(const std::string &dateStr, int startPos, int finalPos);
		
		bool				isValidPriceValue(const std::string &valueStr);
		bool				isValidDate(const std::string &dateStr);
		bool				isLeapYear(int year);
		bool				isValidDateFormat(const std::string &dateStr);
		bool				isValidYear(int year);
		bool				isValidMonth(int month);
		bool				isValidDay(int day, int month, int year);	

	private:
		std::map<std::string, float>	priceMap;
		float							priceValue;
		std::string						dayValue;
};


#endif