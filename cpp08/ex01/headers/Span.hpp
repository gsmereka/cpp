#ifndef SPAN_H
#define SPAN_H

#include <vector>
#include <stdexcept>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span(unsigned int size);
    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;
    template<typename Iterator>
    void addRange(Iterator begin, Iterator end);
};

// Template implementation needs to be included in the header
template<typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
    if (_numbers.size() + std::distance(begin, end) > _maxSize) {
        throw std::out_of_range("Span cannot accommodate all elements");
    }

    _numbers.insert(_numbers.end(), begin, end);
}

#endif // SPAN_H
