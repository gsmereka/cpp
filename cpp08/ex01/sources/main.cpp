#include  "../headers/Span.hpp"
#include <iostream>

void printHeader(std::string str)
{
	std::cout << std::endl << std::string(42, '=') << std::endl
			<< str
			<< std::endl
			<< std::string(42, '=') << std::endl;
}

int main(void)
{
	printHeader("TEST: PDF");
	try
	{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	printHeader("TEST: REPEATED NUMBERS");
	try
	{
		Span	sp = Span(8);

		sp.addNumber(0);
		sp.addNumber(42);
		sp.addNumber(42);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	printHeader("TEST: NEGATIVE VALUE");
	try
	{
		Span sp = Span(5);

		sp.addNumber(0);
		sp.addNumber(-42);
		sp.addNumber(42);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	printHeader("TEST: MANY NUMBERS");
	try
	{
		Span sp = Span(42000);
		std::vector<int> newNumbers;
		for (int i = 0; i < 42000; i++)
			newNumbers.push_back(i);
		sp.addNumbers(newNumbers);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	printHeader("TEST: EXCEEDED MAX NUMBERS");
	try
	{
		Span sp = Span(5);

		sp.addNumber(30);
		sp.addNumber(10);
		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(40);
		sp.addNumber(12);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	printHeader("TEST: EXCEEDED MAX NUMBERS");
	try
	{
		Span sp = Span(1000);
		std::vector<int> newNumbers;
		for (int i = 0; i < 42000; i++)
			newNumbers.push_back(i);
		sp.addNumbers(newNumbers);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
