#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using namespace std;

class Product {
private:
    string name;
    int price;
    int discount;

    static int productCount;

public:
    Product();
    Product(string n);
    Product(string n, int h, int x);
    Product(const Product& other);
    Product(Product&& other) noexcept;
    Product(string n, int h);
    ~Product();

    static int getProductCount();
    static void incrementProductCount();
    void showStatus() const;
    int getPrice() const;
    string getName() const { return name; }

    Product& operator++();
    Product& operator--();
    Product operator+(const Product& other) const;
    Product operator-(int amount) const;

    friend ostream& operator<<(ostream& os, const Product& p);
    friend istream& operator>>(istream& is, Product& p);
};

#endif // PRODUCT_H
