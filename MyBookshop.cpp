#include "book.h"
#include "bookshop.h"
#include <stdexcept>

int main()
{
    book b1 = book("Title 1", "Author 1", 10, 1);
    book b2 = book("Title 2", "Author 2", 20, 15);
    book b3 = book("Title 3", "Author 3", 30, 8);

    bookshop myBookShop = bookshop("My Bookshop");
    myBookShop += b1;
    myBookShop += b2;
    myBookShop += b3;

    std::cout << "BOOKS IN SHOP: \n";
    std::cout << myBookShop;
    myBookShop.showTopByPrice();
    myBookShop.showTopBySales();

    std::cout << "\n------------------------------- \n";

    myBookShop.findByTitle("Title 1");
    myBookShop.findByTitle("Random");

    std::cout << "\n------------------------------- \n";

    myBookShop.removeByTitle("Title 1");
    myBookShop.removeByTitle("Random");

    std::cout << "\n------------------------------- \n";

    std::cout << "BOOKS IN SHOP: \n";
    std::cout << myBookShop;

    return 0;
}
