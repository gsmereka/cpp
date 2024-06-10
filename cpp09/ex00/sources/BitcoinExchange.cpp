#include "../headers/BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Error: could not open bitcoin price file.");
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date;
		std::string priceStr;
		double price;

		if (std::getline(iss, date, ',') && std::getline(iss, priceStr))
		{
			std::istringstream priceStream(priceStr);
			if (!(priceStream >> price))
			{
				throw std::runtime_error("Error: invalid bitcoin price data.");
			}
			bitcoinPrices[date] = price;
		}
		else
			throw std::runtime_error("Error: invalid bitcoin price data.");
	}
}

double BitcoinExchange::getExchangeRate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = bitcoinPrices.lower_bound(date);
	if (it == bitcoinPrices.end() || it->first != date)
	{
		if (it == bitcoinPrices.begin())
		{
			throw std::runtime_error("Error: no valid date found.");
		}
		else
		{
			--it;
		}
	}
	return it->second;
}

bool BitcoinExchange::hasDate(const std::string& date) const
{
	return bitcoinPrices.find(date) != bitcoinPrices.end();
}
