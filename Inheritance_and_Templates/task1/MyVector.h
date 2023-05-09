#ifndef _MYVECTOR_H
#define _MYVECTOR_H

template<typename T, typename R>
class MyVector
{
	T* arr;
	int size;
	int capacity;

	void copyFrom(const MyVector& other);
	void move(MyVector&& other);
	void free();

public:

	MyVector();
	MyVector(const MyVector& other);
	MyVector& operator=(const MyVector& other);
	MyVector(MyVector&& other);
	MyVector& operator=(MyVector&& other);
	~MyVector();

	int getSize() const;
	void resize(int capacity);
	void addElement(T element);
	T& operator[](int index);

	R& apply(T& t);
	


};

#endif