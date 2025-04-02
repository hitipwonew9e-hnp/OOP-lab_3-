#include "product.h"
#include "electronic.h"
#include "foodproduct.h"

void printProductInfo(const Product& ref) {
    ref.display();
}

int main() {

    Product::staticMethod();


    Product* ptr1 = new Electronic("Laptop", 1200, 2);
    Product* ptr2 = new FoodProduct("Milk", 2.5, "2025-06-01");

    ptr1->display(); // Electronic
    ptr2->display(); // FoodProduct

    delete ptr1;
    delete ptr2;


    Electronic phone("Smartphone", 999, 1);
    FoodProduct apple("Apple", 1.2, "2025-04-10");

    printProductInfo(phone);
    printProductInfo(apple);

    return 0;
}
