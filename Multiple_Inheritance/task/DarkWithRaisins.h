#ifndef _DARKWITHRAISINS_H
#define _DARKWITHRAISINS_H
#include "DarkChocolate.h"
#include "WithRaisins.h"

class DarkWithRaisins : public DarkChocolate, public WithRaisins
{

public:
	DarkWithRaisins(char* id, unsigned numOfRaisins) : DarkChocolate(id), WithRaisins(numOfRaisins) {};

	Chocolate* clone() const override;

};

#endif

