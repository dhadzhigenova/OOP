#ifndef _MILKWITHRAISINS_H
#define _MILKWITHRAISINS_H
#include "MilkChocolate.h"
#include "WithRaisins.h"

class MilkWithRaisins : public MilkChocolate, public WithRaisins
{

public:
	MilkWithRaisins(unsigned id, unsigned numOfRaisins) : MilkChocolate(id), WithRaisins(numOfRaisins) {};

	Chocolate* clone() const override;

};

#endif