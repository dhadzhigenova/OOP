#ifndef _WITHRAISINS_H
#define _WITHRAISINS_H

#include "Chocolate.h"

class WithRaisins : virtual public Chocolate
{
protected:
	unsigned numOfRaisins;

public:
	WithRaisins(unsigned numOfRaisins);
	Chocolate* clone() const override;
};

#endif