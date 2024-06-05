#include "../headers/Span.hpp"
#include <algorithm>

Span::Span(unsigned int size) : _maxSize(size) {
    _numbers.reserve(size);
}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::out_of_range("Span is full");
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::out_of_range("Cannot find span with less than 2 numbers");
    }

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minSpan = sortedNumbers[1] - sortedNumbers[0];
    for (size_t i = 2; i < sortedNumbers.size(); ++i) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }

    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::out_of_range("Cannot find span with less than 2 numbers");
    }

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return max - min;
}
