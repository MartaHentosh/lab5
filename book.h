#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>

class book
{
    std::string _title;
    std::string _author;
    double _price;
    int _numberOfSales;

public:
    book(std::string const& title, std::string const& author, double const& price, int numberOfSales) :_title(title), _author(author), _price(price), _numberOfSales(numberOfSales) {};

    std::string title() const
    {
        return _title;
    }

    std::string author() const
    {
        return _author;
    }

    double price() const
    {
        return _price;
    }

    double sales() const
    {
        return _numberOfSales;
    }

};

inline std::ostream& operator <<(std::ostream& os, book const& b) {
    return os << "Title: " << b.title() << "; Author: " << b.author() << "; Price: " << b.price() << "; Sales: " << b.sales() << ";" << std::endl;
    return os;
}

#endif /*BOOK_H*/