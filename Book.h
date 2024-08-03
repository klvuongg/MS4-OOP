#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iostream>
#include "Publication.h"
namespace seneca {
    class Book : public Publication {
        char* author_name;
    public:
        Book();
        Book(const Book& b);
        Book& operator=(const Book& b);
        ~Book();
        char type() const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& istr);
        void set(int member_id);
        operator bool() const;
    };
}
#endif // !SENECA_BOOK_H