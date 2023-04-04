#include<iostream>
#include"Person.h"
#include<cstring>



void Person::copyFrom(const Person& other) {

	if (this->username != nullptr) {

		delete[] this->username;
	}
	this->username = new char[strlen(username)+1];
	strcpy(this->username, username);

	if (this->password != nullptr) {

		delete[] this->password;
	}
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);

}

void Person::move(Person&& other) {

	username = other.username;
	password = other.password;
	other.username = nullptr;
	other.password = nullptr;
}

Person::Person() {

	username = nullptr;
	password = nullptr;
}

Person::Person(char* username, char* password) {

	if (this->username != nullptr) {

		delete[] this->username;
	}
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);

	if (this->password != nullptr) {

		delete[] this->password;
	}
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);

}

Person::Person(const Person& other) {

	copyFrom(other);
}

Person& Person::operator=(const Person& other) {

	if (this != &other) {
		delete[] this->username;
		delete[] this->password;
		username = nullptr;
		password = nullptr;

		copyFrom(other);
	}

	return *this;
}

Person::~Person() {

	delete[] this->username;
	delete[] this->password;
	username = nullptr;
	password = nullptr;
}

Person::Person(Person&& other) {

	move(std::move(other));
}

Person& Person::operator=(Person&& other) {

	if (this != &other) {
		delete[] this->username;
		delete[] this->password;
		username = nullptr;
		password = nullptr;

		move(std::move(other));
	}

	return *this;
}

