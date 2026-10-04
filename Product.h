#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Category
{
private:
    std::string name;

public:
    Category();
    Category(std::string name);
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

    Product(const Product& other);
    ~Product();

    int getId() const;
    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;
    Category getCategory() const;

    bool restock(int amount);
    bool removeStock(int amount);
    bool changePrice(double newPrice);

    void printInfo() const;
     
 
    

    
};

#endif