#ifndef ITER_HPP
#define ITER_HPP

// Function template to apply a function to each element of an array
template <typename T, typename Func>
void iter(T* array, size_t length, Func func) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

#endif