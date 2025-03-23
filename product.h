#ifndef PRODUCT_H
#define PRODUCT_H

#include "item.h"

class Product : public Item {
public:
    Product(const std::string& n, double p);
    virtual void display() const override;
};

class Electronic : public Product {
private:
    int warrantyMonths;
public:
    Electronic(const std::string& n, double p, int warranty);
    void display() const override;
};

class FoodProduct : public Product {
private:
    std::string expirationDate;
public:
    FoodProduct(const std::string& n, double p, const std::string& expDate);
    void display() const override;
};

#endif // PRODUCT_H


