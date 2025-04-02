#include "item.h"

Item::Item(const std::string& n, double p) : name(n), price(p) {}

Item::~Item() {}

double Item::getPrice() const { return price; }
std::string Item::getName() const { return name; }

std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << "Item: " << item.name << ", Price: $" << item.price;
    return os;
}