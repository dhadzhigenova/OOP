#include "GeographicalCoordinates.h"

double GeographicalCoordinates::getX() const
{
	return x;
}

double GeographicalCoordinates::getY() const
{
	return y;
}

void GeographicalCoordinates::setX(double x)
{
	this->x = x;
}

void GeographicalCoordinates::setY(double y)
{
	this->y = y;
}