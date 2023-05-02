#ifndef _GEOGRAPHICALLANDMARKS_H
#define _GEOGRAPHICALLANDMARKS_H

#include "GeographicalCoordinates.h"

class GeographicalLandmarks 
{
	GeographicalCoordinates coordinates;
	char* description;
	double period;

	void copyFrom(const GeographicalLandmarks& other);
	void move(GeographicalLandmarks&& other);
	void free();

public:

	GeographicalLandmarks();
	GeographicalLandmarks(const GeographicalLandmarks& other);
	GeographicalLandmarks& operator=(const GeographicalLandmarks& other);
	GeographicalLandmarks(GeographicalLandmarks&& other);
	GeographicalLandmarks& operator=(GeographicalLandmarks&& other);
	~GeographicalLandmarks();
};

#endif

