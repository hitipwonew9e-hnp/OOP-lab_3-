#include "store.h"
#include "customer.h"

int main() {
    Store myStore;
    myStore.addProduct(std::make_shared<Electronic>("Laptop", 1200, 24));
    myStore.addProduct(std::make_shared<FoodProduct>("Apple", 2, "2025-01-01"));

    myStore.showProducts();

    Customer customer("John", 1000);
    customer.addToCart(myStore.findProduct("Laptop"));
    customer.addToCart(myStore.findProduct("Apple"));

    customer.checkout();
    customer.addBalance(500);
    customer.checkout();
    customer.refund("Apple");

    return 0;
}



