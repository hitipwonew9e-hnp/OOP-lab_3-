#include <iostream>
#include "product.h"
#include "customer.h"
#include "store.h"

using namespace std;

int main() {
    Store myStore;
    myStore.addProduct(Product("Banana", 20, 45));
    myStore.addProduct(Product("Fish", 40, 25));
    myStore.addProduct(Product("Meat", 30));

    myStore.showProducts();

    Customer customer("John", 50);
    customer.buyProduct(Product("Banana", 20, 45));
    customer.buyProduct(Product("Meat", 30));
    customer.buyProduct(Product("Fish", 40, 25));


    return 0;
}
