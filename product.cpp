#include "product.h"

Product::Product(const std::string& n, double p) : Item(n, p) {}

void Product::display() const {
    std::cout << "Product: " << name << ", Price: " << price << "$" << std::endl;
}

Electronic::Electronic(const std::string& n, double p, int warranty)
    : Product(n, p), warrantyMonths(warranty) {}

void Electronic::display() const {
    std::cout << "Electronic: " << name << ", Price: " << price << "$"
              << ", Warranty: " << warrantyMonths << " months" << std::endl;
}

FoodProduct::FoodProduct(const std::string& n, double p, const std::string& expDate)
    : Product(n, p), expirationDate(expDate) {}

void FoodProduct::display() const {
    std::cout << "Food: " << name << ", Price: " << price << "$"
              << ", Expiration Date: " << expirationDate << std::endl;
}

