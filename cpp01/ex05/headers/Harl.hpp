#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl
{
	public:
		Harl(void);
		~Harl(void);
		void complain(std::string const level);
	private:
		std::string const str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif
