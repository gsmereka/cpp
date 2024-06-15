#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#include "../headers/PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <positive integer sequence>" << std::endl;
		return 1;
	}

	std::vector<int> sequence;
	for (int i = 1; i < argc; ++i)
	{
		int number;
		std::istringstream splitStream(argv[i]);
		if (!(splitStream >> number) || number < 0)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		sequence.push_back(number);
	}

	PmergeMe sorter;

	// Using std::vector
	std::vector<int> vectorSequence = sequence;
	clock_t start = clock();
	sorter.sort(vectorSequence);
	clock_t end = clock();
	double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	// Using std::deque
	std::deque<int> dequeSequence(sequence.begin(), sequence.end());
	start = clock();
	sorter.sort(dequeSequence);
	end = clock();
	double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	// Output results
	std::cout << "Before: ";
	for (size_t i = 0; i < sequence.size(); ++i) {
		std::cout << sequence[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "After: ";
	for (size_t i = 0; i < vectorSequence.size(); ++i) {
		std::cout << vectorSequence[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << sequence.size() << " elements with std::vector: " << vectorTime << " s" << std::endl;
	std::cout << "Time to process a range of " << sequence.size() << " elements with std::deque: " << dequeTime << " s" << std::endl;

	return 0;
}
