#ifndef SPAN_H
# define SPAN_H
# include <vector>
# include <stdexcept>

class Span
{
	public:

		Span();
		Span(Span const & src);
		Span (int n);
		~Span();

		Span &	operator=(Span const &rhs);

		void	addNumber(int element);
		int	    shortestSpan(void);
		int		longestSpan(void);

		// EXTRA
		void	addNumbers(const std::vector<int>& newNumbers);
	private:
		int		            maxSize;
		std::vector<int>	numbers;
};

#endif
