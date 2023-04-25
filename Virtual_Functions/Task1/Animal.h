#ifndef _ANIMAL_H
#define _ANIMAL_H


class Animal
{
protected:
	char* name;
	char* type;

	void copyFrom(const Animal& other);
	void move(Animal&& other);
	void free();

public:

	Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	Animal(Animal&& other);
	Animal& operator=(Animal&& other);
	~Animal();

	virtual void talk()=0;
};

#endif