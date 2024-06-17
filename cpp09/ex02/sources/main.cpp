#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#include <cerrno>
#include <cstdlib>
#include <limits>
#include "../headers/PmergeMe.hpp"

static int strToNumber(std::string str);

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << YELLOW << "Usage: " << argv[0] << " <positive integer sequence>" << RES << std::endl;
		return 1;
	}

	std::vector<int> sequence;
	for (int i = 1; i < argc; ++i)
	{
		std::string	numberStr;
		int			number;

		std::istringstream splitStream(argv[i]);
		if (!(splitStream >> numberStr))
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		number = strToNumber(numberStr);
		if (number < 0)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		sequence.push_back(number);
	}

	PmergeMe sorter;

	// Using vector
	std::vector<int> vectorSequence = sequence;
	clock_t start = clock();
	sorter.sort(vectorSequence);
	clock_t end = clock();
	double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	// Using deque
	std::deque<int> dequeSequence(sequence.begin(), sequence.end());
	start = clock();
	sorter.sort(dequeSequence);
	end = clock();
	double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	// Output results
	std::cout << BLUE "Before: " << RES;
	for (size_t i = 0; i < sequence.size(); ++i) {
		std::cout << sequence[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "\n---------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << BLUE << "Vector After: " << RES;
	for (size_t i = 0; i < vectorSequence.size(); ++i) {
		std::cout << vectorSequence[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "\n---------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << BLUE "Deque After: " << RES;
	for (size_t i = 0; i < dequeSequence.size(); ++i) {
		std::cout << dequeSequence[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "\n---------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << BLUE << "Time to process a range of " << RES << sequence.size() << " elements with vector: " << GREEN << vectorTime << " s" << RES << std::endl;
	std::cout << BLUE << "Time to process a range of " << RES << sequence.size() << " elements with deque: " << YELLOW << dequeTime << " s" << RES << std::endl;

	return 0;
}


static int strToNumber(std::string str)
{
    char *remainder;
    errno = 0;
    long value = std::strtol(str.c_str(), &remainder, 10);

    if (*remainder != '\0')
    {
        return -1;
    }
    if (errno == ERANGE || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
    {
        return -1;
    }
    if (str.find('.') != std::string::npos || str.find('e') != std::string::npos || str.find('E') != std::string::npos)
    {
        return -1;
    }
    return static_cast<int>(value);
}