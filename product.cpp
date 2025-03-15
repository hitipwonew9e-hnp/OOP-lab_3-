#include "product.h"

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
}

int Product::getPrice() const {
    return price;
}

