#ifndef ELECTRONIC_H
#define ELECTRONIC_H

#include "product.h"

class Electronic : public Product {
    int warranty;

public:
    Electronic(const std::string& name, double price, int warranty);
    void display() const override;
    std::string getCategory() const override;
};

#endif // ELECTRONIC_H
