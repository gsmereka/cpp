#ifndef SWAPMINMAX_HPP
# define SWAPMINMAX_HPP

template <typename T>
void    swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T   min(const T &a, const T &b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T>
T   max(const T &a, const T &b)
{
	if (b > a)
		return b;
	return a;
}

#endif