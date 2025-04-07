#ifndef MENU_H
#define MENU_H

#include "store.h"
#include <iostream>
#include <fstream>

const std::string ADMIN_PASSWORD = "123";

void adminMenu() {
    int choice;
    std::cout << "\n== Admin Menu ==\n"
              << "1. Add Electronic\n"
              << "2. Add Food Product\n"
              << "3. View Products\n"
              << "4. Exit\nChoice: ";
    std::cin >> choice;

    if (choice == 1) {
        std::string name;
        double price;
        int warranty;
        std::cout << "Enter name, price, warranty: ";
        std::cin >> name >> price >> warranty;
        products.push_back(std::make_shared<Electronic>(name, price, warranty));
        saveProductsToFile();
    } else if (choice == 2) {
        std::string name, date;
        double price;
        std::cout << "Enter name, price, expiration date (yyyy-mm-dd): ";
        std::cin >> name >> price >> date;
        products.push_back(std::make_shared<FoodProduct>(name, price, date));
        saveProductsToFile();
    } else if (choice == 3) {
        for (size_t i = 0; i < products.size(); ++i) {
            std::cout << i + 1 << ". ";
            products[i]->display();
        }
    }
}

void userMenu() {
    std::cout << "\n== User Menu ==\nAvailable Products:\n";
    for (size_t i = 0; i < products.size(); ++i) {
        std::cout << i + 1 << ". ";
        products[i]->display();
    }

    std::cout << "\nSelect product number to 'buy' (0 to exit): ";
    int choice;
    std::cin >> choice;

    if (choice > 0 && choice <= products.size()) {
        std::ofstream history("user_history.txt", std::ios::app);
        history << "User bought: " << products[choice]<< std::endl;
        products[choice - 1]->print();
        history << "\n";
        std::cout << "Purchase recorded.\n";
    }
}

void mainMenu() {
    int mode;
    std::cout << "\n== Main Menu ==\n1. Admin\n2. User\nChoice: ";
    std::cin >> mode;

    if (mode == 1) {
        std::string password;
        std::cout << "Enter admin password: ";
        std::cin >> password;
        if (password == ADMIN_PASSWORD) {
            adminMenu();
        } else {
            std::cout << "Wrong password!\n";
        }
    } else if (mode == 2) {
        userMenu();
    } else {
        std::cout << "Invalid option!\n";
    }
}
#endif // MENU_H
