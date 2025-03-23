#include "store.h"
#include <iostream>

void Store::addProduct(const Product& p) {
    products.push_back(p);
}

void Store::showProducts() const {
    for (const auto& product : products) {
        product.showStatus();
    }
}

