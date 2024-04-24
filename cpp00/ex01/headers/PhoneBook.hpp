#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        Contact getContact(unsigned int index) const;
        void add(void);
        unsigned int getbookIndex(void) const;
        static void search(PhoneBook const &book);
    private:
        Contact book[8];
        unsigned int bookIndex;
        unsigned int bookLimit;
};

#endif
