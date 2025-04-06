#ifndef FOODPRODUCT_H
#define FOODPRODUCT_H

#include "product.h"

class FoodProduct final : public Product {
    std::string expirationDate;

public:
    FoodProduct(const std::string& name, double price, const std::string& expirationDate);
    void display() const override;
    std::string getCategory() const override;

    std::string getExpirationDate() const { return expirationDate; }
};

#endif // FOODPRODUCT_H
