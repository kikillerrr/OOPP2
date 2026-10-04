#include <iostream>
#include "Product.h"

int main()
{
    Category electronics("Electronics");

    Product p1;

    Product p2(101, "Laptop", 800, 10, electronics);

    Product p3(p2);


    p1.restock(20);

    std::cout << "P1 quantity: " << p1.getQuantity() << '\n';
    std::cout << "P2 quantity: " << p2.getQuantity() << '\n';

    return 0;
}