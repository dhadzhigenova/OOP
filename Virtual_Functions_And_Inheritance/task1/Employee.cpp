#include "Employee.h"
#include <iostream>
#include <cstring>

void Employee::copyFrom(const Employee& other)
{
	username = new char[strlen(other.username) + 1];
	strcpy(this->username, other.username);

	password = new char[strlen(other.password) + 1];
	strcpy(this->password, other.password);

}

void Employee::move(Employee&& other)
{
	username = other.username;
	password = other.password;

	other.username = nullptr;
	other.password = nullptr;
}

void Employee::free()
{
	delete[] username;
	delete[] password;
}

Employee::Employee()
{
	username = nullptr;
	password = nullptr;
}

Employee::Employee(const Employee& other)
{
	copyFrom(other);
}

Employee& Employee::operator=(const Employee& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Employee::Employee(Employee&& other)
{
	move(std::move(other));
}

Employee& Employee::operator=(Employee&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}
}

Employee::~Employee()
{
	free();
}