#ifndef _GEOGRAPHICALCOORDINATES_H
#define _GEOGRAPHICALCOORDINATES_H

class GeographicalCoordinates
{
	double x;
	double y;

public:

	double getX() const;
	double getY() const;

	void setX(double x);
	void setY(double y);
};

#endif