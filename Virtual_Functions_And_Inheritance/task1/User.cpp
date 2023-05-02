#include "User.h"
#include <iostream>
#include <cstring>

void User::copyFrom(const User& other)
{
	username = new char[strlen(other.username) + 1];
	strcpy(this->username, other.username);

	password = new char[strlen(other.password) + 1];
	strcpy(this->password, other.password);

}

void User::move(User&& other)
{
	username = other.username;
	password = other.password;

	other.username = nullptr;
	other.password = nullptr;
}

void User::free()
{
	delete[] username;
	delete[] password;
}

User::User()
{
	username = nullptr;
	password = nullptr;
}

User::User(const User& other)
{
	copyFrom(other);
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

User::User(User&& other)
{
	move(std::move(other));
}

User& User::operator=(User&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}
}

User::~User()
{
	free();
}
