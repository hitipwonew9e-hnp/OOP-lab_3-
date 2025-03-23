#include "store.h"
#include <iostream>

int main() {
    Store myStore;
    Product p1("Laptop", 1000, 10);
    Product p2("Phone", 500, 5);

    myStore.addProduct(p1);
    myStore.addProduct(p2);

    myStore.showProducts();

    std::cout << "Total Products: " << Product::getProductCount() << "\n";
    return 0;
}

