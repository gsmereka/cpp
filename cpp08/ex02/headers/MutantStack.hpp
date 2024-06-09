#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iomanip>


#define MAGENTA "\033[35m"
#define RED "\x1b[38;5;88m"
#define GREEN "\x1b[38;5;40m"
#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define ORANGE	"\033[0;38;5;166m"
#define LIGHT_PURPLE "\033[1;35m"
#define CYAN "\001\e[0;36m\002"
#define RES "\x1b[0m"

#include <deque>
#include <stack>

#include <deque>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() {}

    // Updated copy constructor
    MutantStack(MutantStack const &other) : std::stack<T>(other) {}

    // Assignment operator using the "copy-and-swap" idiom
    MutantStack &operator=(MutantStack other) {
        std::swap(this->c, other.c);
        return *this;
    }

    virtual ~MutantStack() {}

    typedef typename std::deque<T>::iterator iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};


#endif
