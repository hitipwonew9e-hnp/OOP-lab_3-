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

public:
    Product();
    Product(string n);
    Product(string n, int h, int x);
    Product(const Product& other); //constructor copy
    Product(Product&& other) noexcept; // constructor move
    Product(string n, int h);
    ~Product();

    void showStatus() const;
    int getPrice() const;
    string getName() const;
};

#endif // PRODUCT_H

