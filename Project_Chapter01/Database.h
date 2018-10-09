#pragma once
#include <iostream>
#include <vector>
#include "Employee.h"

namespace Records {

	class Database
	{
	public:
		Database();
		Employee& addEmployee(const std::string& firstName,
							  const std::string& lastName);
		Employee& getEmployee(int employeeNumber);
		Employee& getEmployee(const std::string& firstName,
							  const std::string& lastName);

		void displayAll() const;
		void displayCurrent() const;
		void displayFormer() const;

		~Database();

	private:
		std::vector<Employee> mEmployees;
		int mNextEmployeeNumber;

	};

}