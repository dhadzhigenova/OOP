#include "Dog.h"
#include <iostream>



Dog::~Dog()
{
	Animal::~Animal();
}

void Dog::talk()
{
	std::cout << "Dog";
}