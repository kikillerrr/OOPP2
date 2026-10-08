#include "Product.h"
#include <iostream>
#include <iomanip>

int Product::objectCount = 0;

Category::Category()
    : id(0), name("Other") {}

Category::Category(std::string name)
    : id(0),
      name(name.empty() ? "Other" : name) {}

Category::Category(int id, std::string name)
    : id(id > 0 ? id : 0),
      name(name.empty() ? "Other" : name) {}

int Category::getId() const {
    return id;
}

std::string Category::getName() const {
    return name;
}

Product::Product()
    : id(0), name("Без названия"), price(1), quantity(0), category() {
    objectCount++;
}

Product::Product(int id, std::string name, double price,
                 int quantity, Category category)
    : id(id > 0 ? id : 1),
      name(name.empty() ? "Без названия" : name),
      price(price > 0 ? price : 1),
      quantity(quantity >= 0 ? quantity : 0),
      category(category) {
    objectCount++;
}

Product::Product(const Product& other)
    : id(other.id), name(other.name), price(other.price),
      quantity(other.quantity), category(other.category) {
    objectCount++;
}

Product::~Product() { objectCount--; }

int Product::getId() const { return id; }
std::string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }
Category Product::getCategory() const { return category; }

bool Product::restock(int amount) {
    if (amount <= 0) return false;
    quantity += amount;
    return true;
}

bool Product::removeStock(int amount) {
    if (amount <= 0 || amount > quantity) return false;
    quantity -= amount;
    return true;
}

bool Product::changePrice(double newPrice) {
    if (newPrice <= 0) return false;
    price = newPrice;
    return true;
}

void Product::printInfo() const {
    std::cout << std::left
              << std::setw(3) << id
              << "| " << std::setw(20) << name
              << "| " << std::right << std::setw(8)
              << std::fixed << std::setprecision(2) << price
              << " | " << std::left << std::setw(10) << quantity
              << " | " << category.getName()
              << '\n';
}

int Product::getObjectCount() { return objectCount; }