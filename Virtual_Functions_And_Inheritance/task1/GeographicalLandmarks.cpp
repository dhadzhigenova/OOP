#include "GeographicalLandmarks.h"
#include <iostream>
#include <cstring>

void GeographicalLandmarks::copyFrom(const GeographicalLandmarks& other)
{
	coordinates = other.coordinates;

	description = new char[strlen(other.description) + 1];
	strcpy(this->description, other.description);

	period = other.period;
}

void GeographicalLandmarks::move(GeographicalLandmarks&& other)
{
	coordinates = other.coordinates;
	description = other.description;
	period = other.period;

	other.description = nullptr;
}

void GeographicalLandmarks::free()
{
	delete[] description;
}

GeographicalLandmarks::GeographicalLandmarks()
{
	//
	description = nullptr;
	period = 0;
}

GeographicalLandmarks::GeographicalLandmarks(const GeographicalLandmarks& other)
{
	copyFrom(other);
}

GeographicalLandmarks& GeographicalLandmarks::operator=(const GeographicalLandmarks& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

GeographicalLandmarks::GeographicalLandmarks(GeographicalLandmarks&& other)
{
	move(std::move(other));
}

GeographicalLandmarks& GeographicalLandmarks::operator=(GeographicalLandmarks&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

GeographicalLandmarks::~GeographicalLandmarks()
{
	free();
}