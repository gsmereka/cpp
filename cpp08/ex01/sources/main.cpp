#include "../headers/Span.hpp" // Adjust the path accordingly
#include <iostream>
#include <vector>
#include <set>

// int main() {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);

//     std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
//     std::cout << "Longest span: " << sp.longestSpan() << std::endl;

//     std::vector<int> testVec;
//     testVec.push_back(2);
//     testVec.push_back(4);
//     testVec.push_back(6);
//     testVec.push_back(8);
//     testVec.push_back(10);
//     try {
//         sp.addRange(testVec.begin(), testVec.end());
//         std::cout << "Shortest span after range addition: " << sp.shortestSpan() << std::endl;
//         std::cout << "Longest span after range addition: " << sp.longestSpan() << std::endl;
//     } catch (const std::out_of_range& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

//     return 0;
// }


void printHeader(std::string str, char marker)
{
	std::cout << std::string(58, marker) << std::endl
                << str
			  << std::endl
			  << std::string(58, marker) << std::endl;
}

void printSeparator(void)
{
	std::cout << std::string(58, '-') << std::endl;
}

int main()
{
	printHeader("TEST - PDF", '~');
	try {
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}
	printHeader("TEST - REPEATED NUMBERS", '~');
	try {
		Span	sp = Span(8);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(100);
		sp.addNumber(3);
		sp.addNumber(1);
		sp.addNumber(9);
		sp.addNumber(9);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}
	printHeader("TEST - NEGATIVE VALUE", '~');
	try {
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(-17);
		sp.addNumber(9);
		sp.addNumber(10);
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}
	printHeader("TEST - MANY NUMBERS", '~');
	try {
		std::multiset<int> manySp;
		for (int i = 0; i < 10001; i++)
			manySp.insert(i);

		Span sp = Span(10001);
		sp.addRange(manySp.begin(), manySp.end());
		std::cout << sp.longestSpan() << "\n";
		std::cout << sp.shortestSpan() << "\n";
	}
	catch (const std::out_of_range& e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}
	printHeader("TEST - EXCEEDED QUANTITY", '~');
	try {
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(10);
		sp.addNumber(11);
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}
	printSeparator();
	try {
		std::multiset<int> manySp;
		for (int i = 0; i < 1001; i++)
			manySp.insert(i + 2);

		Span sp = Span(1000);
		sp.addRange(manySp.begin(), manySp.end());
		std::cout << sp.longestSpan() << "\n";
		std::cout << sp.shortestSpan() << "\n";
	}
	catch (const std::out_of_range& e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}
	return 0;
}






