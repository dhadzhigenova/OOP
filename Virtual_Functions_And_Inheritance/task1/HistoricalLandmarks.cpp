#include "HistoricalLandmarks.h"
#include <iostream>
#include <cstring>

void HistoricalLandmarks::copyFrom(const HistoricalLandmarks& other)
{
	coordinates = other.coordinates;

	description = new char[strlen(other.description) + 1];
	strcpy(this->description, other.description);

	year = other.year;
}

void HistoricalLandmarks::move(HistoricalLandmarks&& other)
{
	coordinates = other.coordinates;
	description = other.description;
	year = other.year;

	other.description = nullptr;
}

void HistoricalLandmarks::free()
{
	delete[] description;
}

HistoricalLandmarks::HistoricalLandmarks()
{
	//
	description = nullptr;
	year = 0;
}

HistoricalLandmarks::HistoricalLandmarks(const HistoricalLandmarks& other)
{
	copyFrom(other);
}

HistoricalLandmarks& HistoricalLandmarks::operator=(const HistoricalLandmarks& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

HistoricalLandmarks::HistoricalLandmarks(HistoricalLandmarks&& other)
{
	move(std::move(other));
}

HistoricalLandmarks& HistoricalLandmarks::operator=(HistoricalLandmarks&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

HistoricalLandmarks::~HistoricalLandmarks()
{
	free();
}