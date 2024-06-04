#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
public:
    // Default constructor
    Array();

    // Constructor with size parameter
    Array(unsigned int n);

    // Copy constructor
    Array(const Array<T>& other);

    // Assignment operator
    Array<T>& operator=(const Array<T>& other);

    // Destructor
    ~Array();

    // Subscript operator
    T& operator[](unsigned int index);

    // Const subscript operator
    const T& operator[](unsigned int index) const;

    // Size function
    unsigned int size() const;

private:
    T* data;
    unsigned int length;
};

// Implementations
template <typename T>
Array<T>::Array() : data(NULL), length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), length(n) {}

template <typename T>
Array<T>::Array(const Array<T>& other) : data(new T[other.length]()), length(other.length) {
    for (unsigned int i = 0; i < length; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new T[length]();
        for (unsigned int i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= length) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= length) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return length;
}

#endif // ARRAY_HPP
