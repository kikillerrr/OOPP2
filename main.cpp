#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <windows.h>
#include "Product.h"


/**
 * @brief Выводит заголовок таблицы товаров.
 */
void printHeader() {
    std::cout << "ID | Название             | Цена     | Количество | Категория\n";
    std::cout << "---|----------------------|----------|------------|----------\n";
}


/**
 * @brief Считывает целое число с клавиатуры.
 *
 * Повторяет ввод до тех пор, пока пользователь
 * не введёт корректное целое число.
 *
 * @param m Сообщение для пользователя.
 * @return Введённое целое число.
 */
int readInt(std::string m) {
    while (true) {
        std::cout << m;
        std::string s;
        std::getline(std::cin, s);
        std::stringstream ss(s);
        int x;
        char c;

        if (ss >> x && !(ss >> c))
            return x;

        std::cout << "Ошибка ввода.\n";
    }
}


/**
 * @brief Считывает вещественное число с клавиатуры.
 *
 * Поддерживает ввод как с точкой, так и с запятой
 * в качестве десятичного разделителя.
 *
 * @param m Сообщение для пользователя.
 * @return Введённое вещественное число.
 */
double readDouble(std::string m) {
    while (true) {
        std::cout << m;
        std::string s;
        std::getline(std::cin, s);

        for (char& c : s)
            if (c == ',')
                c = '.';

        std::stringstream ss(s);
        double x;
        char c;

        if (ss >> x && !(ss >> c))
            return x;

        std::cout << "Ошибка ввода.\n";
    }
}


/**
 * @brief Считывает непустую строку с клавиатуры.
 *
 * @param m Сообщение для пользователя.
 * @return Введённая строка.
 */
std::string readText(std::string m) {
    std::string s;

    do {
        std::cout << m;
        std::getline(std::cin, s);
    } while (s.empty());

    return s;
}


/**
 * @brief Ищет товар по идентификатору.
 *
 * @param p Список товаров.
 * @param id Идентификатор товара.
 * @return Указатель на найденный товар или nullptr,
 *         если товар не найден.
 */
Product* find(std::vector<Product>& p, int id) {
    for (auto& x : p)
        if (x.getId() == id)
            return &x;

    return nullptr;
}


/**
 * @brief Позволяет выбрать существующую категорию
 *        или создать новую.
 *
 * @param c Список категорий.
 * @return Выбранная или созданная категория.
 */
Category getCategory(std::vector<Category>& c) {
    while (true) {
        std::cout << "\nКатегории:\n";

        for (int i = 0; i < c.size(); i++)
            std::cout << i + 1 << ". "
                      << c[i].getName() << '\n';

        std::cout << "0. Новая категория\n";

        int n = readInt("Выбор: ");

        if (n == 0) {
            std::string name = readText("Название: ");
            bool exists = false;

            for (auto& x : c)
                if (x.getName() == name)
                    exists = true;

            if (!exists) {
                c.emplace_back(name);
                return c.back();
            }

            std::cout << "Такая категория уже есть.\n";
        }
        else if (n >= 1 && n <= c.size())
            return c[n - 1];
    }
}


/**
 * @brief Создаёт новый товар.
 *
 * Проверяет уникальность идентификатора, корректность
 * цены и количества товара.
 *
 * @param p Список существующих товаров.
 * @param c Список категорий.
 * @return Созданный объект Product.
 */
Product create(std::vector<Product>& p, std::vector<Category>& c) {
    int id;

    while (true) {
        id = readInt("ID: ");
        bool exists = false;

        for (auto& x : p)
            if (x.getId() == id)
                exists = true;

        if (id > 0 && !exists)
            break;

        std::cout << "ID неверный или уже существует.\n";
    }

    std::string name = readText("Название: ");

    double price;
    do
        price = readDouble("Цена: ");
    while (price <= 0);

    int q;
    do
        q = readInt("Количество: ");
    while (q < 0);

    return Product(id, name, price, q, getCategory(c));
}


/**
 * @brief Главная функция программы.
 *
 * Инициализирует категории и товары, демонстрирует
 * основные операции с классом Product и запускает
 * интерактивное меню управления товарами.
 *
 * @return 0 при успешном завершении программы.
 */
int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    std::vector<Category> c = {
        Category("Игрушки"),
        Category("Мебель")
    };

    std::vector<Product> p = {
        Product(1, "Мяч", 100, 5, c[0]),
        Product(2, "Стул", 300, 7, c[1])
    };

    Product defaultProduct;
    Product copiedProduct(p[0]);

    std::cout << "\nКоличество существующих объектов: "
              << Product::getObjectCount() << '\n';

    std::cout << "Начальное состояние:\n";
    printHeader();

    for (auto& x : p)
        x.printInfo();

    std::cout << "\nКорректные операции:\n";

    p[0].restock(2);
    p[0].removeStock(1);
    p[0].changePrice(120);

    printHeader();

    for (auto& x : p)
        x.printInfo();

    std::cout << "\nНекорректные операции:\n";

    std::cout << "Пополнение -5: "
              << (p[0].restock(-5) ? "успешно" : "отклонено")
              << '\n';

    p[0].removeStock(100);
    p[0].changePrice(-10);

    std::cout << "\nСостояние после операций:\n";
    printHeader();

    for (auto& x : p)
        x.printInfo();

    std::cout << "\nПроверка независимости объектов:\n";

    std::cout << "До изменения:\n";
    printHeader();

    for (auto& x : p)
        x.printInfo();

    p[0].restock(1);

    std::cout << "После изменения первого товара:\n";
    printHeader();

    for (auto& x : p)
        x.printInfo();

    while (true) {
        std::cout << "\n1. Добавить\n"
                  << "2. Пополнить\n"
                  << "3. Продать\n"
                  << "4. Удалить\n"
                  << "5. Цена\n"
                  << "6. Показать\n"
                  << "0. Выход\n";

        int n = readInt("Выбор: ");

        if (n == 0)
            break;

        if (n == 1) {
            p.push_back(create(p, c));
            std::cout << "Товар добавлен.\n";
            continue;
        }

        if (n == 6) {
            if (p.empty())
                std::cout << "Список пуст.\n";

            printHeader();

            for (auto& x : p)
                x.printInfo();

            continue;
        }

        if (n < 1 || n > 5) {
            std::cout << "Неверный пункт.\n";
            continue;
        }

        Product* x = find(p, readInt("ID товара: "));

        if (!x) {
            std::cout << "Товар не найден.\n";
            continue;
        }

        if (n == 2) {
            std::cout << (x->restock(readInt("Количество: "))
                ? "Склад пополнен.\n"
                : "Ошибка количества.\n");
        }
        else if (n == 3) {
            int q = readInt("Количество: ");

            if (q > x->getQuantity())
                std::cout << "Недостаточно товара.\n";
            else
                std::cout << (x->removeStock(q)
                    ? "Товар продан.\n"
                    : "Ошибка количества.\n");
        }
        else if (n == 4) {
            std::string name = x->getName();

            p.erase(p.begin() + (x - p.data()));

            std::cout << "Товар \""
                      << name
                      << "\" удалён.\n";
        }
        else if (n == 5) {
            std::cout << (x->changePrice(readDouble("Новая цена: "))
                ? "Цена изменена.\n"
                : "Ошибка цены.\n");
        }
    }

    std::cout << "Программа завершена.\n";
}
