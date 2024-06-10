#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "../headers/BitcoinExchange.hpp"

void processInput(const std::string& inputFilename, BitcoinExchange& exchange)
{
	std::ifstream file(inputFilename.c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Error: could not open input file.");
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date;
		double value;
		char separator;

		if (!(iss >> date >> separator >> value) || separator != '|' || value <= 0)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		try
		{
			double exchangeRate = exchange.getExchangeRate(date);
			std::cout << date << " => " << value << " = " << (value * exchangeRate) << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input_filename>" << std::endl;
		return 1;
	}

	std::string inputFilename(argv[1]);

	try
	{
		BitcoinExchange exchange("data.csv");
		processInput(inputFilename, exchange);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
