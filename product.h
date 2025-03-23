#ifndef PRODUCT_H
#define PRODUCT_H

#include "item.h"

class Product : public Item {
private:
    int discount;
    static int productCount;
    void incrementProductCount();

public:
    Product();
    Product(std::string n, int h, int x);
    Product(std::string n, int h);
    Product(const Product& other);
    Product(Product&& other) noexcept;
    ~Product();

    static int getProductCount();
    void showStatus() const override; // Позначаємо метод як const
    Product operator+(const Product& other) const;
};

#endif // PRODUCT_H
