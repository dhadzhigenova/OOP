#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

class Employee
{
	char* username;
	char* password;

	void copyFrom(const Employee& other);
	void move(Employee&& other);
	void free();

public:

	Employee();
	Employee(const Employee& other);
	Employee& operator=(const Employee& other);
	Employee(Employee&& other);
	Employee& operator=(Employee&& other);
	~Employee();
};

#endif