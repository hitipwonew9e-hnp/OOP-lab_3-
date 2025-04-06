#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class IPrintable {
public:
    virtual void print() const = 0;
};

class Product : public IPrintable {
protected:
    std::string name;
    double price;

public:
    Product(const std::string& name, double price);
    virtual ~Product();

    virtual void display() const;
    virtual std::string getCategory() const = 0;

    static void staticMethod();
    void print() const override { display(); }
    void nonVirtualMethod() const;

    std::string getName() const { return name; }
    double getPrice() const { return price; }
};

#endif // PRODUCT_H
