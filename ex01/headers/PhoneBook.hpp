#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

// #include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        Contact getContact(unsigned int index) const;
        void add(void);
        unsigned int getBookSize(void);
        static void search(PhoneBook const &book);
    private:
        Contact book[8];
        unsigned int bookSize;
};

#endif // !PHONEBOOK_HPP
