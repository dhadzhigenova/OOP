#ifndef SET_H
#define SET_H

class Set {
private:
	int* elements;

	int numElements;
	int capacity;

	void resize();

	void copy(int const* elements, int const numElements, int const capacity);

public:
	Set();
	Set(Set const& other);
	Set& operator= (Set const& other);
	~Set();

	bool addElement(int const element);
	bool deleteElement(int const element);
	void setUnion(Set const& other);
	void setIntersection(Set const& other);
	void print();

	Set(Set&& other);
	Set& operator=(Set&& other);
	

};

#endif