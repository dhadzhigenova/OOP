#include "Animal.h"

#include <cstring>
#include <iostream>

void Animal::copyFrom(const Animal& other)
{
	this->name = new char[strlen(name + 1)];
	strcpy(this->name, name);

	this->type = new char[strlen(type + 1)];
	strcpy(this->type, type);
}

void Animal::move(Animal&& other)
{
	name = other.name;
	type = other.type;

	name = nullptr;
	type = nullptr;
}

void Animal::free()
{
	delete[] name;
	delete[] type;
}

Animal::Animal()
{
	name = nullptr;
	type = nullptr;
}

Animal::Animal(const Animal& other)
{
	copyFrom(other);
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Animal::Animal(Animal&& other)
{
	move(std::move(other));
}

Animal& Animal::operator=(Animal&& other)
{
	if (this != &other)
	{
		move(std::move(other));
	}

	return *this;
}

Animal::~Animal()
{
	free();
}