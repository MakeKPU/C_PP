#include "pch.h"
#include "Database.h"
#include <stdexcpt.h>

using namespace std;

namespace Records {

	Database::Database()
	{
	}

	Employee & Records::Database::addEmployee(const std::string & firstName, const std::string & lastName)
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
		Employee theEmployee;
		theEmployee.setFirstName(firstName);
		theEmployee.setLastName(lastName);
		theEmployee.setEmployeeNumber(mNextEmployeeNumber);
		theEmployee.hire();
		mEmployees.push_back(theEmployee);
		return mEmployees[mEmployees.size() - 1];
	}

	Employee & Records::Database::getEmployee(int employeeNumber)
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
		for (auto& employee : mEmployees)
		{
			if (employee.getEmployeeNumber() == employeeNumber)
			{
				return employee;
			}
		}
		throw runtime_error("No employee found.");
	}

	Employee & Records::Database::getEmployee(const std::string & firstName, const std::string & lastName)
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
		for (auto& employee : mEmployees)
		{
			if (employee.getFirstName() == firstName && 
				employee.getLastName() == lastName)
			{
				return employee;
			}
		}
		throw runtime_error("No employee found.");
	}

	void Records::Database::displayAll() const
	{
		for (const auto& employee : mEmployees)
		{
			employee.display();
		}
	}

	void Records::Database::displayCurrent() const
	{
		for (const auto& employee : mEmployees)
		{
			if(employee.getIsHired())
				employee.display();
		}
	}

	void Records::Database::displayFormer() const
	{
	}


	Database::~Database()
	{
	}
}