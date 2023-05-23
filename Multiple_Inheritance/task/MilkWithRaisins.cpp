#include "MilkWithRaisins.h"

Chocolate* MilkWithRaisins::clone() const
{
	return new MilkWithRaisins(*this);
}