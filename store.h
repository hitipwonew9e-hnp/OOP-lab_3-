#ifndef STORE_H
#define STORE_H

#include "product.h"
#include <vector>

class Store {
private:
    vector<Product> products;

public:
    void addProduct(const Product& p);
    void showProducts() const;
};

#endif // STORE_H
