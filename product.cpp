#include "product.h"

Product::Product(const std::string& name, double price) : name(name), price(price) {}

Product::~Product() {
    std::cout << "Destroying Product: " << name << std::endl;
}

void Product::display() const {
    std::cout << "Product: " << name << ", Price: $" << price << std::endl;
}

void Product::staticMethod() {
    std::cout << "This is a static method from Product class" << std::endl;
}
