#include "../headers/Span.hpp"
#include <algorithm>

Span::Span(int size) : maxSize(size)
{
	numbers.reserve(size);
}

Span::~Span() {}


void Span::addNumbers(const std::vector<int>& newNumbers)
{
    if (static_cast<int>(numbers.size() + newNumbers.size()) > maxSize)
    {
        throw std::out_of_range("Adding these numbers would exceed the span's capacity");
    }

    numbers.insert(numbers.end(), newNumbers.begin(), newNumbers.end());
}

void Span::addNumber(int number)
{
	if (static_cast<int>(numbers.size()) >= maxSize)
	{
		throw std::out_of_range("Adding this number would exceed the span's capacity");
	}
	numbers.push_back(number);
}

int	Span::shortestSpan(void)
{
	if (numbers.size() < 2)
	{
		throw std::out_of_range("Cannot find span with less than 2 numbers");
	}

	std::vector<int> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int minSpan = sortedNumbers[1] - sortedNumbers[0];
	for (size_t i = 2; i < sortedNumbers.size(); ++i)
	{
		int temp_span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (temp_span < minSpan)
		{
			minSpan = temp_span;
		}
	}

	return minSpan;
}

int Span::longestSpan()
{
	if (numbers.size() < 2)
	{
		throw std::out_of_range("Cannot find span with less than 2 numbers");
	}

	int minNumber = *std::min_element(numbers.begin(), numbers.end());
	int maxNumber = *std::max_element(numbers.begin(), numbers.end());

	return maxNumber - minNumber;
}
