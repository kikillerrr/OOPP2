#include "Product.h"

Product::Product()
    : id(0),
      name("No name"),
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

Product::Product(const Product& other)
    : id(other.id),
      name(other.name),
      price(other.price),
      quantity(other.quantity),
      category(other.category)
{
}

int Product::getId() const
{
    return id;
}

std::string Product::getName() const
{
    return name;
}

double Product::getPrice() const
{
    return price;
}

int Product::getQuantity() const
{
    return quantity;
}

Category Product::getCategory() const
{
    return category;
}