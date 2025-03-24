#include "customer.h"
#include <iostream>
#include <algorithm>

void Cart::addProduct(std::shared_ptr<Product> p) {
    items.push_back(p);
}

void Cart::showCart() const {
    std::cout << "Cart contains:\n";
    for (const auto& item : items) {
        item->display();
    }
}

double Cart::getTotal() const {
    double total = 0;
    for (const auto& item : items) {
        total += item->getPrice();
    }
    return total;
}

void Cart::clearCart() {
    items.clear();
}

void Cart::removeProduct(const std::string& name) {
    auto it = std::remove_if(items.begin(), items.end(),
        [&](const std::shared_ptr<Product>& product) {
            return product->getName() == name;
        });

    items.erase(it, items.end());
}

Customer::Customer(const std::string& n, double b) : name(n), balance(b) {}

void Customer::addToCart(std::shared_ptr<Product> p) {
    if (p) {
        cart.addProduct(p);
        std::cout << name << " added " << p->getName() << " to cart.\n";
    }
}

void Customer::checkout() {
    double total = cart.getTotal();
    if (balance >= total) {
        balance -= total;
        std::cout << name << " bought all items for $" << total << "\n";
        cart.clearCart();
    } else {
        std::cout << name << " does not have enough money!\n";
    }
}

void Customer::addBalance(double amount) {
    balance += amount;
    std::cout << name << " add to balans " << amount << "$"  << ". New balans: " << balance << "$"  << std::endl;
}

void Customer::refund(const std::string& name) {
    cart.removeProduct(name);
    std::cout << name << " return item.\n";
}
Cart& Cart::operator=(const Cart& other) {
    if (this == &other) return *this;
    items = other.items;
    return *this;
}

Customer& Customer::operator=(const Customer& other) {
    if (this == &other) return *this;
    name = other.name;
    balance = other.balance;
    cart = other.cart;
    return *this;
}
