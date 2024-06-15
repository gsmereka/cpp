#include "../headers/PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other)
    {
        return *this;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sort(std::vector<int> &sequence) {
    mergeInsertSort(sequence, 0, sequence.size() - 1);
}

void PmergeMe::sort(std::deque<int> &sequence) {
    mergeInsertSort(sequence, 0, sequence.size() - 1);
}

void PmergeMe::mergeInsertSort(std::vector<int> &sequence, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeInsertSort(sequence, left, mid);
        mergeInsertSort(sequence, mid + 1, right);
        merge(sequence, left, mid, right);
    }
}

void PmergeMe::mergeInsertSort(std::deque<int> &sequence, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeInsertSort(sequence, left, mid);
        mergeInsertSort(sequence, mid + 1, right);
        merge(sequence, left, mid, right);
    }
}

void PmergeMe::merge(std::vector<int> &sequence, int left, int mid, int right) {
    std::vector<int> leftPart(sequence.begin() + left, sequence.begin() + mid + 1);
    std::vector<int> rightPart(sequence.begin() + mid + 1, sequence.begin() + right + 1);

    std::vector<int>::size_type i = 0, j = 0, k = left;
    while (i < leftPart.size() && j < rightPart.size()) {
        if (leftPart[i] <= rightPart[j]) {
            sequence[k] = leftPart[i];
            i++;
        } else {
            sequence[k] = rightPart[j];
            j++;
        }
        k++;
    }

    while (i < leftPart.size()) {
        sequence[k] = leftPart[i];
        i++;
        k++;
    }

    while (j < rightPart.size()) {
        sequence[k] = rightPart[j];
        j++;
        k++;
    }
}

void PmergeMe::merge(std::deque<int> &sequence, int left, int mid, int right) {
    std::deque<int> leftPart(sequence.begin() + left, sequence.begin() + mid + 1);
    std::deque<int> rightPart(sequence.begin() + mid + 1, sequence.begin() + right + 1);

    std::deque<int>::size_type i = 0, j = 0, k = left;
    while (i < leftPart.size() && j < rightPart.size()) {
        if (leftPart[i] <= rightPart[j]) {
            sequence[k] = leftPart[i];
            i++;
        } else {
            sequence[k] = rightPart[j];
            j++;
        }
        k++;
    }

    while (i < leftPart.size()) {
        sequence[k] = leftPart[i];
        i++;
        k++;
    }

    while (j < rightPart.size()) {
        sequence[k] = rightPart[j];
        j++;
        k++;
    }
}
