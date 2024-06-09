#include  "../headers/MutantStack.hpp"
#include  <deque>
#include  <list>

int main() {
    MutantStack<int> mstack;

    mstack.push(1);
    mstack.push(2);
    mstack.push(3);

    std::cout << "Elements on stack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    mstack.push(4);
    mstack.push(5);
    mstack.push(6);

    std::cout << "Elements on stack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Elements on stack: ";
    for (MutantStack<int>::iterator it = mstack.end(); it != mstack.begin(); --it)
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}
