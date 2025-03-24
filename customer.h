#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "product.h"
#include <vector>
#include <memory>

class Cart {
private:
    std::vector<std::shared_ptr<Product>> items;

public:
    Cart& operator=(const Cart& other);
    void addProduct(std::shared_ptr<Product> p);
    void showCart() const;
    void clearCart();
    double getTotal() const;
    void removeProduct(const std::string& name);
};

class Customer {
private:
    std::string name;
    double balance;
    Cart cart;
public:
    Customer& operator=(const Customer& other);
    Customer(const std::string& n, double b);
    void addToCart(std::shared_ptr<Product> p);
    void checkout();
    void addBalance(double amount);
    void refund(const std::string& name);
};




#endif // CUSTOMER_H



