#ifndef _FACTORY_H
#define _FACTORY_H
#include "Chocolate.h"

class Factory
{
	Chocolate** chocolate;
	int size;
	int capacity;

	void copyFrom(const Factory& other);
	void free();

	void resize();

public:
	Factory();
	Factory(const Factory& other);
	Factory& operator= (const Factory& other);
	~Factory();
};

#endif