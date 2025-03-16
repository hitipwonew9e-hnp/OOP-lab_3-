#include "store.h"
#include <iostream>

void Store::addProduct(const Product& p) {
    products.push_back(p);
}

void Store::showProducts() const {
    cout << "Store inventory:\n";
    for (const auto& p : products) {
        cout << p << endl;
    }
}
