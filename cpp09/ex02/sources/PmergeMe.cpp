#include "../headers/PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        // Implement copying of data members if there are any
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

// Helper function to insert an element in a sorted list
template <typename Container>
void PmergeMe::insertSorted(Container &sortedList, typename Container::value_type value)
{
    typename Container::iterator it = std::lower_bound(sortedList.begin(), sortedList.end(), value);
    sortedList.insert(it, value);
}

// Main Ford-Johnson sort function
template <typename Container>
void PmergeMe::fordJohnsonSort(Container &sequence)
{
    if (sequence.size() < 2)
		return;
    Container listA;
    Container listB;

    // Step 1: Divide the list into pairs and sort each pair
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

    // Step 2: Sort list A
    std::sort(listA.begin(), listA.end());

    // Step 3: Insert elements from list B into list A
    for (typename Container::const_iterator it = listB.begin(); it != listB.end(); ++it)
	{
        insertSorted(listA, *it);
    }

    // Copy sorted elements back to the original sequence
    std::copy(listA.begin(), listA.end(), sequence.begin());
}
