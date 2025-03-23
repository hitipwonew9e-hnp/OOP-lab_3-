#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "product.h"

using namespace std;

class Customer {
private:
    string name;
    int balance;

public:
    Customer(string n, int b);
    void buyProduct(const Product& p);
};

#endif // CUSTOMER_H
