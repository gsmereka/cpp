#include "../headers/PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		return *this;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sort(std::vector<int> &sequence) {
	fordJohnsonSort(sequence);
}

void PmergeMe::sort(std::deque<int> &sequence) {
	fordJohnsonSort(sequence);
}

template <typename Container>
void PmergeMe::fordJohnsonSort(Container &sequence)
{
	if (sequence.size() < 2)
		return;
	Container listA;
	Container listB;

	for (typename Container::size_type i = 0; i < sequence.size(); i += 2)
	{
		if (i + 1 < sequence.size())
		{
			if (sequence[i] < sequence[i + 1])
			{
				listA.push_back(sequence[i]);
				listB.push_back(sequence[i + 1]);
			}
			else
			{
				listA.push_back(sequence[i + 1]);
				listB.push_back(sequence[i]);
			}
		}
		else
		{
			listA.push_back(sequence[i]);
		}
	}

	fordJohnsonSort(listA);

	insertSorted(listA, listB);

	std::copy(listA.begin(), listA.end(), sequence.begin());
}

template <typename Container>
void PmergeMe::insertSorted(Container &listA, Container &listB)
{
	for (typename Container::iterator it = listB.begin(); it != listB.end(); ++it)
	{
		typename Container::iterator insertPos = binarySearch(listA, *it);
		listA.insert(insertPos, *it);
	}
}

template <typename Container>
typename Container::iterator binarySearch(Container &listA, const typename Container::value_type &value)
{
    typename Container::iterator first = listA.begin();
    typename Container::iterator last = listA.end();
    typename Container::iterator middle;

    while (first < last)
    {
        middle = first + std::distance(first, last) / 2;
        if (*middle < value)
            first = middle + 1;
        else
            last = middle;
    }
    return first;
}