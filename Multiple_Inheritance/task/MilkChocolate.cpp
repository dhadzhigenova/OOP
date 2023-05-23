#include "MilkChocolate.h"

MilkChocolate::MilkChocolate(unsigned id)
{
	this->id = id;
}

unsigned MilkChocolate::getId() const
{
	return this->id;
}

Chocolate* MilkChocolate::clone() const
{
	return new MilkChocolate(*this);
}