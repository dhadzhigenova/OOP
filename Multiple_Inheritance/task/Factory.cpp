#include "Factory.h"

void Factory::copyFrom(const Factory& other)
{
	size = other.size;
	capacity = other.capacity;
	
	chocolate = new Chocolate * [capacity];
	for (size_t i = 0; i < size; i++)
	{
		chocolate[i] = other.chocolate[i]->clone();
	}
}

void Factory::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete chocolate[i];
	}
	delete[] chocolate;
}

void Factory::resize()
{
	capacity *= 2;

	Chocolate** newChocolate = new Chocolate * [capacity];

	for (int i = 0; i < size; i++)
	{
		newChocolate[i] = chocolate[i];
	}

	delete[] chocolate;
	chocolate = newChocolate;
}

/////////////////
////////////////