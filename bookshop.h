#ifndef BOOKSHOP_H
#define BOOKSHOP_H
#include "book.h"
#include <string>
#include <vector>
#include <algorithm> 

class bookshop {

public:

    std::string  _name;
    std::vector <book> _books;

    bookshop(std::string const& name) : _name(name) {};

    std::string name() const {
        return _name;
    }

    bookshop& operator+= (book const& new_book)
    {
        _books.push_back(new_book);
        return *this;
    }

    int count_books() const
    {
        return _books.size();
    }

    void showTopByPrice() {
        std::cout << "TOP BY PRICE: \n";

        std::sort(_books.begin(), _books.end(), by_Price());

        showBooks();
    }

    void showTopBySales() {
        std::cout << "TOP BY SALES: \n";

        std::sort(_books.begin(), _books.end(), by_Sales());

        showBooks();
    }

    int findByTitle(std::string title) {
        std::cout << "Searching for a book with title " << title << "... \n";
        auto itr = std::find_if(_books.cbegin(), _books.cend(), compare(title));

        if (itr != _books.cend()) {
            const int bookIndex = std::distance(_books.cbegin(), itr);

            std::cout << "Book was found and currently has index: " << bookIndex << "; \n";
            std::cout << _books[bookIndex] << ' ' << '\n';

            return bookIndex;
        }
        else {
            std::cout << "Book was not found; \n";

            return 0;
        }
    }

    void removeByTitle(std::string title) {
        int bookIndex = findByTitle(title);

        if (bookIndex != 0) {
            _books.erase(_books.begin() + bookIndex);

            std::cout << "Book with title " << title << " has been removed; \n\n";
        }
        else {
            std::cout << "Book collection was not changed; \n";
        }
    }

    void showBooks() {
        for (size_t i = 0; i <_books.size(); i++)
            std::cout << _books[i] << ' ' << '\n';
    }

    struct by_Price {
        bool operator()(book const& a, book const& b) const {
            return a.price() > b.price();
        }
    };

    struct by_Sales {
        bool operator()(book const& a, book const& b) const {
            return a.sales() > b.sales();
        }
    };

    struct compare
    {
        std::string key;
        compare(std::string &title): key(title) {}

        bool operator()(book const &b) {
            return (b.title() == key);
        }
    };

    friend std::ostream& operator<< (std::ostream& os, bookshop const& c)
    {
        for (size_t i = 0; i < c._books.size(); i++)
            os << c._books[i] << ' ' << '\n';
        return os;
    }
};

#endif /*BOOKSHOP_H*/
