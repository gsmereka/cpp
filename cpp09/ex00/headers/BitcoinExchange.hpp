#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string &filename);

		double getExchangeRate(const std::string &date) const;
		bool hasDate(const std::string &date) const;

	private:
		std::map<std::string, double> bitcoinPrices;
};

#endif
