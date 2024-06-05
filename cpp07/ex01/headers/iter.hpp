#ifndef ITER_HPP
# define ITER_HPP

template<typename T, typename Operation>
void iter(T* array, size_t length, Operation op)
{
    for (size_t i = 0; i < length; ++i)
    {
        op(array[i]);
    }
}

template<typename T, typename Operation>
void iter(const T* array, size_t length, Operation op)
{
    for (size_t i = 0; i < length; ++i) {
        op(array[i]);
    }
}

#endif
