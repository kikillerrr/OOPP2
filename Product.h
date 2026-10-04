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
};