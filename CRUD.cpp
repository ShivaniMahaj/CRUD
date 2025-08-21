#include <iostream>
#include <mongocxx/instance.hpp>
#include "MongoDB.hxx"
#include "Employee.hpp"
#include "Menu.hpp"

int main() {
    mongocxx::instance inst{};

    MongoDB dbManager("mongodb://localhost:27017", "company", "employees");
    Employee employee(dbManager);
    Menu menu;

    employee.create_table();

    int choice;
    bool running = true;

    while (running) {
        menu.show_menu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: menu.create_Employee(employee); break;
        case 2: menu.update_Employee(employee); break;
        case 3: menu.delete_Employee(employee); break;
        case 4: menu.list_Employees(employee); break;
        case 5: running = false; break;
        default: std::cout << "Invalid choice. Please try again.\n"; break;
        }
    }

    return 0;
}
