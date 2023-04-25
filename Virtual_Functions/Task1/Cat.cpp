#include "Cat.h"
#include <iostream>



Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
		
	return *this;
}

Cat::~Cat()
{
	Animal::~Animal();
}

void Cat::talk()
{
	std::cout << "Cat";
}

