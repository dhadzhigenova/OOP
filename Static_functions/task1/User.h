#ifndef _USER_H
#define _USER_H
#include <cstring>

class User
{
protected:
	int id;
	char* username;
	static char* password;

	void copyFrom(const User& other);
	void move(User&& other);
	void free();

public:

	User(const User& other);
	User& operator =(const User& other);
	User(User&& other);
	User& operator=(User&& other);
	~User();

	bool isNumber(char el);
	char ifNumber(char el);
	bool isLetter(char el);
	char ifLetter(char el);

	void fixPassword(char* password);

	static int compare(const User& other)
	{

	}
};

#endif