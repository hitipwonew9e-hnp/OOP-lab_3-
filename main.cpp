#include "menu.h"

int main() {
    try {
        loadProductsFromFile();

        while (true) {
            mainMenu();
            std::cout << "\nContinue? (1 - yes, 0 - no): ";
            int cont;
            std::cin >> cont;
            if (!cont) break;
        }

        saveProductsToFile();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
