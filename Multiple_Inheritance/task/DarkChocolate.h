#ifndef _DARKCHOCOLATE_H
#define _DARKCHOCOLATE_H

#include "Chocolate.h"


class DarkChocolate : virtual public Chocolate
{
protected:
	char* id;
	

	void copyFrom(const DarkChocolate& other);
	void free();

public:
	DarkChocolate(char* id);
	DarkChocolate(const DarkChocolate& other);
	DarkChocolate& operator=(const DarkChocolate& other);
	~DarkChocolate();

	bool isId();

	Chocolate* clone() const override;
};

#endif