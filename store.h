#ifndef STORE_H
#define STORE_H

#include "product.h"
#include "electronic.h"
#include "foodproduct.h"
#include <vector>
#include <memory>
#include <string>

extern std::vector<std::shared_ptr<Product>> products;

void loadProductsFromFile();
void saveProductsToFile();

#endif // STORE_H
