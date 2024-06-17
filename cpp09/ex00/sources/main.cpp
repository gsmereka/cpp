#include "../headers/BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << YELLOW << "Usage: " << argv[0] << " input.csv" << RES << std::endl;
		return (1);
	}
	BitcoinExchange	btc;

	btc.exchange(argv[1]);
	return 0;
}