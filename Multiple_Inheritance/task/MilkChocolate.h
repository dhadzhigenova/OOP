#ifndef _MILKCHOCOLATE_H
#define _MILKCHOCOLATE_H

#include "Chocolate.h"

class MilkChocolate : virtual public Chocolate
{
protected:
	unsigned id;

public:
	MilkChocolate(unsigned id);

	unsigned getId() const;

	Chocolate* clone() const override;
	
};

#endif