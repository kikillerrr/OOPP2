#include "Product.h"

Product::Product()
    : id(0),
      name("Unknown"),
      price(1),
      quantity(0),
      category()
{
}

Product::Product(int id, std::string name, double price,
                 int quantity, Category category)
    : id(id),
      name(name),
      price(price),
      quantity(quantity),
      category(category)
{
}