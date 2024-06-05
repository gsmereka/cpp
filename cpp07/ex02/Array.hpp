#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <cstdlib>

template <typename T>
class Array
{
	private:
		T				*elements;
		unsigned int	_n;

	public:
		Array() : elements(NULL), _n(0)
		{
			std::cout << "\033[1;34mDefault constructor called\033[0m" << std::endl;
		}

		Array(unsigned int n) : _n(n)
		{
			elements = new T[n];
			std::cout << "\033[1;34mN constructor called\033[0m" << std::endl;
		}

		Array(const Array& src) : _n(src._n)
		{
			elements = new T[_n];
			for (unsigned int i = 0; i < _n; i++)
				elements[i] = src.elements[i];
			std::cout << "\033[1;34mCopy constructor called\033[0m" << std::endl;
		}

		~Array()
		{
			delete[] elements;
			std::cout << "\033[1;34mDefault destructor called\033[0m" << std::endl;
		}

		Array&	operator=(const Array& src) 
		{
			if (this != &src)
			{
				_n = src.size();
				delete[] elements;
				elements = new T[_n]();
				for (unsigned int i = 0; i < _n; i++)
					elements[i] = src.elements[i];
				std::cout << "\033[1;34mCopy assignment operator called\033[0m" << std::endl;
			}
			return (*this);
		}

		T	&operator[](size_t index)
		{
			if (index >= _n)
			{
				throw RangeException();
			}
			return elements[index];
		}

		size_t	size() const
		{
			return _n;
		}

		class	RangeException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw()
				{
					return ("Index out of range! ");
				}
		};
};

#endif