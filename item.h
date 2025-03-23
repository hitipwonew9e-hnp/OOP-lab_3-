#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
protected:
    std::string name;
    int price;

public:
    Item();
    Item(std::string n, int p);
    virtual ~Item();
    virtual void showStatus() const;
};

#endif // ITEM_H
