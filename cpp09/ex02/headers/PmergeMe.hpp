#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>

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
		void mergeInsertSort(std::vector<int> &sequence, int left, int right);
		void mergeInsertSort(std::deque<int> &sequence, int left, int right);

		void merge(std::vector<int> &sequence, int left, int mid, int right);
		void merge(std::deque<int> &sequence, int left, int mid, int right);
};

#endif // PMERGEME_HPP
