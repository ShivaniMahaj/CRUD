#include "Menu.hpp"

void Menu::show_menu() {
    std::cout << "\n Enter Employee Details ---\n";
    std::cout << "1. Create Employee\n";
    std::cout << "2. Update Employee\n";
    std::cout << "3. Delete Employee\n";
    std::cout << "4. List of All Employees\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}


void Menu::create_Employee(Employee& employee) {
    std::string name;
    std::cout << "Enter employee name: ";
    std::getline(std::cin, name);

    if (employee.add_employee(name)) {
        std::cout << "Employee '" << name << "' added successfully.\n";
    }
    else {
        std::cout << "Failed to add employee details.\n";
    }
}


void Menu::update_Employee(Employee& employee) {
    int id;
    std::string new_name;
    std::cout << "Enter employee ID to update: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter new name for employee ID " << id << ": ";
    std::getline(std::cin, new_name);

    if (employee.update_employee_name(id, new_name)) {
        std::cout << "Employee ID : " << id << " updated to '" << new_name << "'.\n";
    }
    else {
        std::cout << "Failed to update employee new name.\n";
    }
}


void Menu::delete_Employee(Employee& employee) {
    int id;
    std::cout << "Enter employee ID to delete: ";
    std::cin >> id;

    if (employee.delete_employee(id)) {
        std::cout << "Employee ID " << id << " deleted successfully.\n";
    }
    else {
        std::cout << "Failed to delete employee Id.\n";
    }

}


void Menu::list_Employees(Employee& employee) {
    std::cout << "\nAll Employees Name: \n";
    employee.list_all_employees();
}

