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

    Product p1("Apple", 100, 10);
    Product p2 = p1;
    p2.showStatus();

    cout << "Products created after copy: " << Product::getProductCount() << endl;

    const Product r1("Apple", 100, 10);
    Product r2 = std::move(p1);
    r2.showStatus();
    r1.showStatus();

    Product p3("Grapes", 50, 5);
    cout << "Original: " << p3 << endl;
    ++p3;
    cout << "After ++: " << p3 << endl;
    --p3;
    cout << "After --: " << p3 << endl;

    Product p4 = p3 + p2;
    cout << "Combined: " << p4 << endl;

    return 0;
}
