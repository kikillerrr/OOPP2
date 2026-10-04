#include <iostream>
#include "Product.h"

int main()
{
    Category electronics("Electronics");

    Product p1;

    Product p2(101, "Laptop", 800, 10, electronics);

    Product p3(p2);

    return 0;
}