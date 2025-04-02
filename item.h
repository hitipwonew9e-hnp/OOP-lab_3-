#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <memory>

class Item {
protected:
    std::string name;
    double price;
public:
    Item(const std::string& n, double p);
    virtual ~Item();
    virtual void display() const = 0; // Чисто віртуальна функція
    double getPrice() const;
    std::string getName() const;
    friend std::ostream& operator<<(std::ostream& os, const Item& item);
};

#endif // ITEM_H