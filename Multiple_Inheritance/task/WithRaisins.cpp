#include "WithRaisins.h"

WithRaisins::WithRaisins(unsigned numOfRaisins)
{
	this->numOfRaisins = numOfRaisins;
}

Chocolate* WithRaisins::clone() const
{
	return new WithRaisins(*this);
}