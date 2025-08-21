#include "Employee.hpp"

Employee::Employee(MongoDB& dbManager) : database(dbManager) {}

bool Employee::create_table() {
    return database.create_table();
}

bool Employee::add_employee(const std::string& name) {
    return database.insert_name(name);
}

bool Employee::update_employee_name(int id, const std::string& newName) {
    return database.update_name(id, newName);
}

bool Employee::delete_employee(int id) {
    return database.delete_name(id);
}

void Employee::list_all_employees() {
    database.list_all();
}
