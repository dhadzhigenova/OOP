#include "DarkChocolate.h"
#include <iostream>
#include <cstring>

void DarkChocolate::copyFrom(const DarkChocolate& other)
{
	id = new char[strlen(other.id) + 1];
	strcpy(id, other.id);

}

void DarkChocolate::free()
{
	delete[] id;
}

DarkChocolate::DarkChocolate(char* id)
{
	this->id = id;
}

DarkChocolate::DarkChocolate(const DarkChocolate& other)
{
	copyFrom(other);
}

DarkChocolate& DarkChocolate::operator=(const DarkChocolate& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
}

DarkChocolate::~DarkChocolate()
{
	free();
}




Chocolate* DarkChocolate::clone() const
{
	return new DarkChocolate(*this);
}