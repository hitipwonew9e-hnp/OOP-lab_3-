#include "item.h"
#include <iostream>

Item::Item() : name("Unknown"), price(0) {}

Item::Item(std::string n, int p) : name(n), price(p) {}

Item::~Item() {}

void Item::showStatus() const {
    std::cout << "Item: " << name << ", Price: " << price << "\n";
}
