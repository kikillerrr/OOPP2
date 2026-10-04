#include "Product.h"
#include <iostream>

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
    : id(id >= 0 ? id : 0),
      name(name.empty() ? "No name" : name),
      price(price > 0 ? price : 1),
      quantity(quantity >= 0 ? quantity : 0),
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

Product::~Product()
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

bool Product::restock(int amount)
{
    if (amount <= 0)
        return false;

    quantity += amount;
    return true;
}

bool Product::removeStock(int amount)
{
    if (amount <= 0 || amount > quantity)
        return false;

    quantity -= amount;
    return true;
}

bool Product::changePrice(double newPrice)
{
    if (newPrice <= 0)
        return false;

    price = newPrice;
    return true;
}

void Product::printInfo() const
{
    std::cout << "ID: " << id
              << ", Name: " << name
              << ", Price: " << price
              << ", Quantity: " << quantity
              << '\n';
}