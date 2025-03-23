#include "product.h"
#include <iostream>

int Product::productCount = 0;

Product::Product() : Item(), discount(0) {
    incrementProductCount();
}

Product::Product(std::string n, int h, int x) : Item(n, h), discount(x) {
    incrementProductCount();
}

Product::Product(std::string n, int h) : Item(n, h), discount(0) {
    incrementProductCount();
}

Product::Product(const Product& other) : Item(other), discount(other.discount) {
    incrementProductCount();
}

Product::Product(Product&& other) noexcept : Item(std::move(other)), discount(other.discount) {
    other.discount = 0;
    incrementProductCount();
}

Product::~Product() {
    --productCount;
}

void Product::incrementProductCount() {
    ++productCount;
}

int Product::getProductCount() {
    return productCount;
}

void Product::showStatus() const {
    Item::showStatus();
    std::cout << "Discount: " << discount << "%\n";
}

Product Product::operator+(const Product& other) const {
    return Product(this->name + " & " + other.name, this->price + other.price, this->discount + other.discount);
}