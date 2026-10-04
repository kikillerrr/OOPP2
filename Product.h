#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Category
{
private:
    std::string name;
};

class Product
{
private:
    int id;
    std::string name;
    double price;
    int quantity;
    Category category;

public:
    Product();

    Product(int id, std::string name, double price,
            int quantity, Category category);

    int getId() const;
    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;
    Category getCategory() const;
};

#endif