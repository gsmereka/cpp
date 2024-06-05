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

#endif // SPAN_H
