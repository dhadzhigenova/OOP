#ifndef _SORTED_H
#define _SORTED_H
#include<iostream>

template <typename T>

class Sorted
{
	T* elements;
	int size;
	int capacity;

	void copyFrom(const Sorted& other);
	void move(Sorted&& other);
	void free();

public:

	Sorted();
	Sorted(const Sorted& other);
	Sorted& operator=(const Sorted<T>& other);
	Sorted(Sorted&& other);
	Sorted& operator=(Sorted<T>&& other);
	~Sorted();

	void resize(int capacity);
	void sort();
	int find(T& elem) const;

	void add(T& elem);
	void remove(T& elem);
	void print();
};

const int INITIAL_SIZE = 4;

template <typename T>
void Sorted<T>::copyFrom(const Sorted& other) {
	size = other.size;
	capacity = other.capacity;

	elements = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		elements[i] = other.elements[i];
	}
}

template <typename T>
void Sorted<T>::move(Sorted&& other) {
	size = other.size;
	capacity = other.capacity;
	elements = other.elements;
	other.elements = nullptr;
}

template <typename T>
void Sorted<T>::free() {
	delete[] elements;
}

template <typename T>
Sorted<T>::Sorted() {
	size = 0;
	capacity = INITIAL_SIZE;
	elements = new T[capacity];
}

template <typename T>
Sorted<T>::Sorted(const Sorted& other) {
	copyFrom(other);
}

template <typename T>
Sorted<T>& Sorted<T>::operator=(const Sorted<T>& other) {
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
Sorted<T>::Sorted(Sorted&& other) {
	move(std::move(other));
}

template <typename T>
Sorted<T>& Sorted<T>::operator=(Sorted<T>&& other) {
	if (this != &other)
	{
		free();
		move(std::move(other));
	}
	return *this;
}

template <typename T>
Sorted<T>::~Sorted() {
	free();
}

template <typename T>
void Sorted<T>::resize(int capacity) {
	if (size <= capacity)
	{
		this->capacity = capacity;
		T* newElem = new T[capacity];

		for (int i = 0; i < size; i++)
		{
			newElem[i] = elements[i];
		}
		delete[] elements;
		elements = newElem;
	}
}

template <typename T>
void Sorted<T>::sort() {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (elements[i] > elements[j])
			{
				std::swap(elements[i], elements[j]);
			}
		}
	}
}

template <typename T>
int Sorted<T>::find(T& elem) const {

	for (int i = 0; i < size; i++)
	{
		if (elements[i] == elem)
		{
			return i;
		}
	}
	return -1;
}

template <typename T>
void Sorted<T>::add(T& elem) {

	if (size >= capacity)
	{
		resize(capacity * 2);
	}

	elements[size] = elem;
	size++;

	sort();
}

template <typename T>
void Sorted<T>::remove(T& elem) {

	int index = find(elem);

	if (index != -1)
	{
		for (int i = index; i < size - 1; i++)
		{
			elements[i] = elements[i + 1];
		}
		size--;
	}

	else
	{
		throw std::exception("Out of range index");
	}

	sort();
}

template <typename T>
void Sorted<T>::print() {
	for (int i = 0; i < size; i++)
	{
		std::cout << elements[i] << " ";
	}
	std::cout << std::endl;
}


#endif