#include "../headers/BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input_filename>" << std::endl;
		return (std::cout << ERROR_ARGC << std::endl, false);
	}
	BitcoinExchange	btc;

	btc.exchange(argv[1]);
	return 0;
}