#include "set.h"
#include <cstring>

void Set::resize() {

}

Set::Set() {
	this->copy(nullptr, 0, 0);
}


Set::Set(Set const& other_set) {
	this->copy(other_set.elements, other_set.numElements, other_set.capacity);
}

Set& Set::operator=(Set const& other_set) {
	if (this != &other_set) {
		this->copy(other_set.elements, other_set.numElements, other_set.capacity);
	}

	return *this;
}

Set::~Set() {
	delete[] this->elements;
}

void Set::copy(int const* elements, int numElements, int capacity) {


	this->numElements = numElements;
	this->capacity = capacity;
}
