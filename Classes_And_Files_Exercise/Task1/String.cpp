#include "String.h"
#include <iostream>
#include <cstring>

int const MAX = 257;

String::String(const char*) {
	this->string = nullptr;
}

String::String(String const& other) {
	if (this->string != nullptr) {
		delete[] this->string;
	}
	this->string = new char[MAX];
	for (int i = 0; i < strlen(string); i++)
	{
		this->string[i] = string[i];
	}
}

String& String::operator=(String const& other) {
	

	if (this != &other) {

		if (this->string != nullptr) {
			delete[] this->string;

			this->string = new char[MAX];
			for (int i = 0; i < strlen(string + 1); i++)
			{
				this->string[i] = string[i];
			}
		}
		
	}
	return *this;
	
}

String::~String() {
	delete[] this->string;
}

String::String(String&& other) {
	if (this->string != nullptr) {
		delete[] this->string;
	}
	this->string = other.string;

	other.string = nullptr;
}

String& String::operator=(String&& other) {
	if (this != &other) {
		if (this->string != nullptr) {
			delete[] this->string;

			this->string = new char[MAX];
			for (int i = 0; i < strlen(string + 1); i++)
			{
				this->string[i] = string[i];
			}
		}

	}
	return *this;
}

char String::operator[](const char symbol) const {
	for (int index = 0; index < strlen(string + 1); ++index)
	{
		if(this->string[index] == symbol)
		{
			return symbol;
		}
	}
}


