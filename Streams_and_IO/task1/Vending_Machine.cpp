#include <iostream>
#include "Vending_Machine.h"
#include <cstring>

Inventory::Inventory() {
	this->salty = 0;
	this->sweet = 0;
	this->drinks = 0;
}

VendingMachine::VendingMachine() {
	this->id = 0;
	this->address = nullptr;
	this->warningMessages = new char* [capacity];
	this->numWarningMsgs = 0;
	this->capacity = 10;
	

}

VendingMachine::VendingMachine(VendingMachine const& other) {
	this->id = id;
	this->numWarningMsgs = numWarningMsgs;
	this->address = new char[this->capacity];

}

VendingMachine& VendingMachine::operator=(VendingMachine const& other) {
	if (this != &other) {
		this->id = id;
		this->numWarningMsgs = numWarningMsgs;
		this->capacity = capacity;
	}

	return *this;
}

VendingMachine::~VendingMachine() {
	delete[] this->address;

}
