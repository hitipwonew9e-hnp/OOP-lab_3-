#include "store.h"
#include <fstream>
#include <sstream>

std::vector<std::shared_ptr<Product>> products;

void loadProductsFromFile() {
    std::ifstream file("products.txt");
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string category, name, priceStr, extra;

        std::getline(ss, category, '|');
        std::getline(ss, name, '|');
        std::getline(ss, priceStr, '|');
        std::getline(ss, extra);

        double price = std::stod(priceStr);

        if (category == "Electronic") {
            int warranty = std::stoi(extra);
            products.push_back(std::make_shared<Electronic>(name, price, warranty));
        } else if (category == "Food") {
            products.push_back(std::make_shared<FoodProduct>(name, price, extra));
        }
    }
}

void saveProductsToFile() {
    std::ofstream file("products.txt");

    for (const auto& product : products) {
        if (product->getCategory() == "Electronic") {
            const Electronic* e = dynamic_cast<const Electronic*>(product.get());
            file << "Electronic|" << e->getName() << "|" << e->getPrice() << "|" << e->getWarranty() << "\n";
        } else if (product->getCategory() == "Food") {
            const FoodProduct* f = dynamic_cast<const FoodProduct*>(product.get());
            file << "Food|" << f->getName() << "|" << f->getPrice() << "|" << f->getExpirationDate() << "\n";
        }
    }
}
