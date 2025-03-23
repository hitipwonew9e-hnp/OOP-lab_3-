#ifndef STORE_H
#define STORE_H

#include <vector>
#include <memory>
#include "product.h"

class Store {
private:
    std::vector<std::shared_ptr<Product>> inventory;
public:
    Store();
    void addProduct(std::shared_ptr<Product> p);
    void showProducts() const;
    std::shared_ptr<Product> findProduct(const std::string& name) const;
    void removeProduct(const std::string& name);
};

#endif // STORE_H

