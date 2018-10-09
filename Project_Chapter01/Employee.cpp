#include "pch.h"
#include "Employee.h"
#include <iostream>
using namespace std;

namespace Records {

	Employee::Employee()
		:mFirestName("")
		,mLastName("")
		,mEmployeeNumber(-1)
		,mSalary(kDefaultStartingSalary)
		,mHired(false)
	{
	}

	void Records::Employee::promote(int raiseAmount)
	{
		setSalary(getSalary() + raiseAmount);
	}

	void Records::Employee::demote(int demeritAmount)
	{
		setSalary(getSalary() - demeritAmount);
	}

	void Records::Employee::hire()
	{
		mHired = true;
	}

	void Records::Employee::fire()
	{
		mHired = false;
	}

	void Records::Employee::display() const
	{
		cout << "Employee : " << getLastName() << ", " << getFirstName() << endl;
		cout << "-----------------------------------" << endl;
		cout << (mHired ? "Current Employee" : "Former Employee") << endl;
		cout << "Salary : $" << getSalary() << endl;
		cout << endl;
	}

	void Records::Employee::setFirstName(const std::string & firstName)
	{
		mFirestName = firstName;
	}

	const std::string & Records::Employee::getFirstName() const
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
		return mFirestName;
	}

	void Records::Employee::setLastName(const std::string & lastName)
	{
		mLastName = lastName;
	}

	const std::string & Records::Employee::getLastName() const
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
		return mLastName;
	}

	void Records::Employee::setEmployeeNumber(int employeeNumber)
	{
		mEmployeeNumber = employeeNumber;
	}

	int Records::Employee::getEmployeeNumber() const
	{
		return mEmployeeNumber;
	}

	void Records::Employee::setSalary(int newSalary)
	{
		mSalary = newSalary;
	}

	int Records::Employee::getSalary() const
	{
		return mSalary;
	}


	bool Records::Employee::getIsHired() const
	{
		return mHired;
	}

	Employee::~Employee()
	{
	}

}