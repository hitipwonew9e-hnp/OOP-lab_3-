#include "foodproduct.h"

FoodProduct::FoodProduct(const std::string& name, double price, const std::string& expirationDate)
    : Product(name, price), expirationDate(expirationDate) {}

void FoodProduct::display() const {
    std::cout << "Food Product: " << name << ", Price: $" << price
              << ", Expiration Date: " << expirationDate << std::endl;
}

std::string FoodProduct::getCategory() const {
    return "Food";
}