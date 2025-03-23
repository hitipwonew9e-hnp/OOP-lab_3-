#include "store.h"
#include <iostream>
#include <algorithm>

Store::Store() = default;

void Store::addProduct(std::shared_ptr<Product> p) {
    inventory.push_back(p);
}

void Store::showProducts() const {
    std::cout << "Store Inventory:\n";
    for (const auto& product : inventory) {
        product->display();
    }
}

std::shared_ptr<Product> Store::findProduct(const std::string& name) const {
    for (const auto& product : inventory) {
        if (product->getName() == name) {
            return product;
        }
    }
    return nullptr;
}

void Store::removeProduct(const std::string& name) {
    auto it = std::remove_if(inventory.begin(), inventory.end(),
        [&](const std::shared_ptr<Product>& product) {
            return product->getName() == name;
        });

    inventory.erase(it, inventory.end()); // Тепер коректно видаляємо елементи
}

