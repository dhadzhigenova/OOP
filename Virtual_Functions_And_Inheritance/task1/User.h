#pragma once
class User
{
	char* username;
	char* password;

	void copyFrom(const User& other);
	void move(User&& other);
	void free();

public:

	User();
	User(const User& other);
	User& operator=(const User& other);
	User(User&& other);
	User& operator=(User&& other);
	~User();
};

