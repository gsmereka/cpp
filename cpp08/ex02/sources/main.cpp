#include  "../headers/MutantStack.hpp"
#include  <deque>
#include <vector>
#include <list>

int main(void)
{
	// DEQUE
    std::cout << "Testing with default container (deque)" << std::endl;
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);

    std::cout << "Elements in MutantStack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    mstack.pop();
    std::cout << "After pop, elements in MutantStack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------------\n" << std::endl;



	// LIST
    std::cout << "Testing with std::list as container" << std::endl;
    MutantStack<int, std::list<int> > mstack_list;
    mstack_list.push(10);
    mstack_list.push(20);
    mstack_list.push(30);

    std::cout << "Elements in MutantStack (list): ";
    for (MutantStack<int, std::list<int> >::iterator it = mstack_list.begin(); it != mstack_list.end(); ++it)
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    mstack_list.pop();
    std::cout << "After pop, elements in MutantStack (list): ";
    for (MutantStack<int, std::list<int> >::iterator it = mstack_list.begin(); it != mstack_list.end(); ++it)
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------------\n" << std::endl;



	// VECTOR
    std::cout << "Testing with std::vector as container" << std::endl;
    MutantStack<int, std::vector<int> > mstack_vector;
    mstack_vector.push(100);
    mstack_vector.push(200);
    mstack_vector.push(300);

    std::cout << "Elements in MutantStack (vector): ";
    for (MutantStack<int, std::vector<int> >::iterator it = mstack_vector.begin(); it != mstack_vector.end(); ++it)
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    mstack_vector.pop();
    std::cout << "After pop, elements in MutantStack (vector): ";
    for (MutantStack<int, std::vector<int> >::iterator it = mstack_vector.begin(); it != mstack_vector.end(); ++it)
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "------------------------------------------------\n" << std::endl;
    return 0;
}