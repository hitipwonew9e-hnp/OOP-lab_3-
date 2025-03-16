#include "customer.h"

Customer::Customer(string n, int b) : name(n), balance(b) {}

void Customer::buyProduct(const Product& p) {
    if (balance >= p.getPrice()) {
        balance -= p.getPrice();
        cout << name << " bought " << p.getName() << " for $" << p.getPrice()
             << ". Remaining balance: $" << balance << endl;
    } else {
        cout << name << " doesn't have enough money." << endl;
    }
}
