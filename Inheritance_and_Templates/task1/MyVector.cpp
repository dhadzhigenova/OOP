#include "MyVector.h"
#include<iostream>

const int INITIAL_CAPACITY = 4;

template<typename T>
void MyVector<T>::copyFrom(const MyVector& other)
{
	size = other.size;
	capacity = other.capacity;

	arr = new T[capacity];

	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}

template<typename T>
void MyVector<T>::move(MyVector&& other)
{
	size = other.size;
	capacity = other.capacity;
	arr = other.arr;
	other.arr = nullptr;
}

template<typename T>
void MyVector<T>::free()
{
	delete[] arr;
}

template<typename T>
MyVector<T>::MyVector()
{
	size = 0;
	capacity = INITIAL_CAPACITY;
	arr = new T[capacity];
}

template<typename T>
MyVector<T>::MyVector(const MyVector& other)
{
	copyFrom(other);
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
MyVector<T>::MyVector(MyVector&& other)
{
	move(std::move(other));
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

template<typename T>
MyVector<T>::~MyVector()
{
	free();
}

template<typename T>
int MyVector<T>::getSize() const
{
	return size;
}

template<typename T>
void MyVector<T>::resize(int capacity)
{
	if (size <= capacity)
	{
		this->capacity = capacity;
		T* newArr = new T[capacity];

		for (int i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}delete[] arr;
		arr = newArr;
	}
}

template<typename T>
void MyVector<T>::addElement(T element)
{
	if (size >= capacity)
	{
		resize(capacity * 2);
	}

	arr[size] = element;
	size++;
}

template<typename T>
T& MyVector<T>::operator[](int index)
{
	if (index <= 0 && index > size)
	{
		throw std::exception("Out of range index");
	}

	return arr[i];
}

template<typename T, typename R>
R& MyVector<T, R>::apply(T& t)
{

}

