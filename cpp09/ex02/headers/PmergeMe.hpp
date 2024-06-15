#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

# define RED "\x1b[38;5;88m"
# define GREEN "\x1b[38;5;40m"
# define BLUE "\x1b[38;5;25m"
# define YELLOW "\x1b[38;5;220m"
# define ORANGE	"\033[0;38;5;166m"
# define RES "\x1b[0m"

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void sort(std::vector<int> &sequence);
    void sort(std::deque<int> &sequence);

private:
    // Helper function to insert an element in a sorted list
    template <typename Container>
    void insertSorted(Container &sortedList, typename Container::value_type value);

    // Main Ford-Johnson sort function
    template <typename Container>
    void fordJohnsonSort(Container &sequence);
};

#endif // PMERGEME_HPP
