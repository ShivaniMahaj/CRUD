#pragma once
#include <string>
#include "MongoDB.hxx"

class Employee {
private:
    MongoDB& database;

public:
    explicit Employee(MongoDB& dbManager);

    bool create_table();
    bool add_employee(const std::string& name);
    bool update_employee_name(int id, const std::string& newName);
    bool delete_employee(int id);
    void list_all_employees();
};
