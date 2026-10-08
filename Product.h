#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

/**
 * @brief Представляет категорию товара.
 *
 * Класс хранит идентификатор и название категории,
 * к которой может относиться товар.
 */
class Category
{
private:
    /// Идентификатор категории.
    int id;

    /// Название категории.
    std::string name;

public:
    /**
     * @brief Конструктор по умолчанию.
     *
     * Создаёт категорию с идентификатором 0
     * и названием "Other".
     */
    Category();

    /**
     * @brief Создаёт категорию с заданным названием.
     *
     * Идентификатор устанавливается в 0.
     *
     * @param name Название категории.
     */
    Category(std::string name);

    /**
     * @brief Создаёт категорию с заданным идентификатором и названием.
     *
     * @param id Идентификатор категории.
     * @param name Название категории.
     */
    Category(int id, std::string name);

    /**
     * @brief Возвращает идентификатор категории.
     *
     * @return Идентификатор категории.
     */
    int getId() const;

    /**
     * @brief Возвращает название категории.
     *
     * @return Название категории.
     */
    std::string getName() const;
};


/**
 * @brief Представляет товар на складе.
 *
 * Класс хранит основные характеристики товара:
 * идентификатор, название, цену, количество и категорию.
 *
 * Также класс предоставляет операции для управления остатком
 * товара и его ценой.
 */
class Product
{
private:
    /// Уникальный идентификатор товара.
    int id;

    /// Название товара.
    std::string name;

    /// Цена товара.
    double price;

    /// Количество товара на складе.
    int quantity;

    /// Категория товара.
    Category category;

    /// Общее количество существующих объектов Product.
    static int objectCount;

public:
    /**
     * @brief Конструктор по умолчанию.
     *
     * Создаёт товар со значениями по умолчанию.
     */
    Product();

    /**
     * @brief Создаёт товар с заданными параметрами.
     *
     * @param id Уникальный идентификатор товара.
     * @param name Название товара.
     * @param price Цена товара.
     * @param quantity Количество товара.
     * @param category Категория товара.
     */
    Product(int id, std::string name, double price,
            int quantity, Category category);

    /**
     * @brief Конструктор копирования.
     *
     * Создаёт новый объект Product как копию существующего.
     *
     * @param other Объект Product, который необходимо скопировать.
     */
    Product(const Product& other);

    /**
     * @brief Деструктор товара.
     */
    ~Product();

    /**
     * @brief Возвращает идентификатор товара.
     *
     * @return ID товара.
     */
    int getId() const;

    /**
     * @brief Возвращает название товара.
     *
     * @return Название товара.
     */
    std::string getName() const;

    /**
     * @brief Возвращает цену товара.
     *
     * @return Цена товара.
     */
    double getPrice() const;

    /**
     * @brief Возвращает количество товара на складе.
     *
     * @return Текущее количество товара.
     */
    int getQuantity() const;

    /**
     * @brief Возвращает категорию товара.
     *
     * @return Категория товара.
     */
    Category getCategory() const;

    /**
     * @brief Пополняет запас товара.
     *
     * Если переданное количество допустимо, оно добавляется
     * к текущему остатку.
     *
     * @param amount Количество добавляемого товара.
     * @return true, если операция выполнена успешно,
     *         иначе false.
     */
    bool restock(int amount);

    /**
     * @brief Уменьшает количество товара на складе.
     *
     * @param amount Количество товара для списания.
     * @return true, если операция выполнена успешно,
     *         иначе false.
     */
    bool removeStock(int amount);

    /**
     * @brief Изменяет цену товара.
     *
     * @param newPrice Новая цена товара.
     * @return true, если цена успешно изменена,
     *         иначе false.
     */
    bool changePrice(double newPrice);

    /**
     * @brief Выводит информацию о товаре.
     *
     * Выводит ID, название, цену, количество и категорию товара.
     */
    void printInfo() const;

    /**
     * @brief Возвращает количество существующих объектов Product.
     *
     * @return Количество существующих объектов Product.
     */
    static int getObjectCount();
};

#endif