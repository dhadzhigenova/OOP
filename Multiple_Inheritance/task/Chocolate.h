#ifndef _CHOCOLATE_H
#define _CHOCOLATE_H
#define _CRT_SECURE_NO_WARNINGS


class Chocolate
{

public:
	
	virtual ~Chocolate() {};
	virtual Chocolate* clone() const = 0;
};

#endif