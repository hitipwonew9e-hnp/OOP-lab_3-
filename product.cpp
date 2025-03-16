#include "product.h"

Product::Product(const Product& other) {
    name = other.name;
    price = other.price;
    discount = other.discount;
    cout << "Copy constructor called for product: " << name << endl;
}

Product::Product(Product&& other) noexcept
    : name(std::move(other.name)), price(other.price), discount(other.discount) {
    other.price = 0;
    other.discount = 0;
    cout << "Move constructor called for product: " << name << endl;
}

Product::Product() : name("None"), price(0), discount(0) {}

Product::Product(string n, int h, int x)
    : name(n), price(h - (h * x / 100)), discount(x) {
    incrementProductCount();
}

Product::Product(string n, int h) : Product(n, h, 0) {}

Product::~Product() {
    cout << "Deleting product: " << name << endl;
}

void Product::showStatus() const {
    cout << "Product: " << name << " | Price: $" << price
         << " | Discount: " << discount << "%" << endl;
    cout << "This object address: " << this << endl;
}

int Product::getPrice() const {
    return price;
}

int Product::productCount = 0;

int Product::getProductCount() {
    return productCount;
}

void Product::incrementProductCount() {
    ++productCount;
}

Product& Product::operator++() {
    price += 10;
    return *this;
}

Product& Product::operator--() {
    if (price >= 10) price -= 10;
    return *this;
}

Product Product::operator+(const Product& other) const {
    return Product(name + " & " + other.name, price + other.price);
}

Product Product::operator-(int amount) const {
    return Product(name, price - amount);
}

ostream& operator<<(ostream& os, const Product& p) {
    os << "Product: " << p.name << ", Price: " << p.price << ", Discount: " << p.discount << "%";
    return os;
}

istream& operator>>(istream& is, Product& p) {
    cout << "Enter product name: ";
    is >> p.name;
    cout << "Enter price: ";
    is >> p.price;
    cout << "Enter discount: ";
    is >> p.discount;
    return is;
}

