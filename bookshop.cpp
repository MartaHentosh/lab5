#include "bookshop.h"
#include "book.h"

inline std::ostream& operator<< (std::ostream& os, bookshop const c)
{
    for (int i = 0; i < c._books.size(); i++)
        std::cout << c._books[i] << " " << std::endl;
    return os;

}