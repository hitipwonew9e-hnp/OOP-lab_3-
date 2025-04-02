#include "electronic.h"

Electronic::Electronic(const std::string& name, double price, int warranty)
    : Product(name, price), warranty(warranty) {}

void Electronic::display() const {
    std::cout << "Electronic: " << name << ", Price: $" << price << ", Warranty: " << warranty << " years" << std::endl;
}

std::string Electronic::getCategory() const {
    return "Electronic";
}
