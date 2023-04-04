#ifndef PERSON_H
#define PERSON_H

class Person {

	char* username;
	char* password;

	void copyFrom(const Person& other);
	void move(Person&& other);

public:

	Person();
	Person(char* username, char* password);
	Person(const Person& other);
	Person& operator=(const Person& other);
	~Person();

	Person(Person&& other);
	Person& operator=(Person&& other);

};

#endif
