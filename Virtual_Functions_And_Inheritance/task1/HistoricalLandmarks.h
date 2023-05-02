#ifndef _HISTORICALLANDMARKS_H
#define _HISTORICALLANDMARKS_H

#include "GeographicalCoordinates.h"

class HistoricalLandmarks
{
	GeographicalCoordinates coordinates;
	char* description;
	int year;

	void copyFrom(const HistoricalLandmarks& other);
	void move(HistoricalLandmarks&& other);
	void free();

public:

	HistoricalLandmarks();
	HistoricalLandmarks(const HistoricalLandmarks& other);
	HistoricalLandmarks& operator=(const HistoricalLandmarks& other);
	HistoricalLandmarks(HistoricalLandmarks&& other);
	HistoricalLandmarks& operator=(HistoricalLandmarks&& other);
	~HistoricalLandmarks();
};

#endif