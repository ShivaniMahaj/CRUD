#pragma once
#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <string>
#include "Employee.hpp"

class Menu {
public:
	void show_menu();
	void create_Employee(Employee& employee);
	void update_Employee(Employee& employee);
	void delete_Employee(Employee& employee);
	void list_Employees(Employee& employee);
};

#endif  MENU_HPP