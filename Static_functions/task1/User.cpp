#include "User.h"
#include <iostream>
#include <cstring>



void User::copyFrom(const User& other)
{
	username = new char[strlen(other.username) + 1];
	strcpy(username, other.username);

	password = new char[strlen(other.password) + 1];
	strcpy(password, other.password);
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
	return *this;
}

User::~User()
{
	free();
}

bool User::isNumber(char el)
{
	if (int(el) >= 48 && int(el) <= 57)
	{
		return true;
	}
	return false;
}

char User::ifNumber(char el)
{
	int newEl;
	if (int(el) == 48)
	{
		el = '?';
	}
	else
	{
		el - 1;
	}
	return el;
}

bool User::isLetter(char el)
{
	if (int(el) >= 65 && int(el) <= 122)
	{
		return true;
	}
	return false;
}

char User::ifLetter(char el)
{
	if (int(el) != 90 && int(el) != 122)
	{
		el + 1;
	}
	else
	{
		el - 36;
	}

	return el;
}

void User::fixPassword(char* password)
{
	int length = strlen(password);
	for (int i = 0; i < length; i++)
	{
		if (isNumber(*password))
		{
			*password = ifNumber(*password);
		}
		else if (isLetter(*password))
		{
			*password = ifLetter(*password);
		}
	}
}