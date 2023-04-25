#ifndef _CAT_H
#define _CAT_H

#include "Animal.h"

class Cat : public Animal
{

public:

	Cat();
	Cat& operator=(const Cat& other);
	
	~Cat();

	void talk();
};

#endif

