#include "DarkWithRaisins.h"

Chocolate* DarkWithRaisins::clone() const
{
	return new DarkWithRaisins(*this);
}