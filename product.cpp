#include "product.h"

Product::Product(const Product& other)  { //constructor copy
    name = other.name;
    price = other.price;
    discount = other.discount;

    cout << "Copy constructor called for product: " << name << endl;
}

Product::Product(Product&& other) noexcept  //constructor peremishenna
    : name(std::move(other.name)), price(other.price), discount(other.discount) {
    other.price = 0;
    other.discount = 0;
    cout << "Move constructor called for product: " << name << endl;
}

Product::Product() : name("None"), price(0), discount(0) {}

Product::Product(string n, int h, int x)
    : name(n), price(h - (h * x / 100)), discount(x) {}

Product::Product(string n, int h) : Product(n, h, 0) {}

Product::~Product() {
    cout << "Deleting product: " << name << endl;
}

void Product::showStatus() const {
    cout << "Product: " << name << " | Price: $" << price
         << " | Discount: " << discount << "%" << endl;
    cout << "This object address: " << this << endl;  // Using this
}

int Product::getPrice() const {
    return price;
}

