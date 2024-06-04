#ifndef SWAP_MIN_MAX_HPP
# define SWAP_MIN_MAX_HPP

// Function template to swap the values of two arguments
template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Function template to return the minimum of two arguments
template <typename T>
T min(const T &a, const T &b) {
    return (a < b) ? a : b;
}

// Function template to return the maximum of two arguments
template <typename T>
T max(const T &a, const T &b) {
    return (a > b) ? a : b;
}

#endif // SWAP_MIN_MAX_HPPs