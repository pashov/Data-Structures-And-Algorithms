#pragma once
//All of the code is in the header, since it's a template class.

#include <iostream>
using namespace std;
const int DEF_CAP = 8;

template <typename T>
class Vector
{
private:
	T* data;
	unsigned int size;
	unsigned int capacity;

private:
	void init();
	void copy(const Vector<T>&);
	void destroy();
	void resize();

public:
	Vector();
	Vector(const Vector<T>&);
	Vector<T>& operator=(const Vector<T>&);
	~Vector();

public:
	T& operator[](const unsigned int)const;
	void add(const T);
	T getAt(const unsigned int)const;
	void setAt(const unsigned int, const T);
	unsigned int getSize()const;
	unsigned int getCapacity()const;
	void print()const;
};

template <typename T>
void Vector<T>::init()
{
	data = new T[DEF_CAP];
	size = 0;
	capacity = DEF_CAP;
}

template <typename T>
void Vector<T>::copy(const Vector<T>& other)
{
	capacity = other.capacity;
	data = new T[capacity];
	size = other.size;
	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template <typename T>
void Vector<T>::destroy()
{
	delete[] data;
}

template <typename T>
void Vector<T>::resize()
{
	capacity *= 2;
	T* temp = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}
	data = temp;
}

template <typename T>
Vector<T>::Vector()
{
	init();
}

template <typename T>
Vector<T>::Vector(const Vector& other)
{
	init();
	copy(other);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}
	return *this;
}

template <typename T>
Vector<T>::~Vector()
{
	destroy();
}

template <typename T>
T& Vector<T>::operator[](const unsigned int index)const
{
	if (index > size - 1)
	{
		throw "OFF BOUNDARIES";
	}
	return data[index];
}

template <typename T>
void Vector<T>::add(const T element)
{
	if (size == capacity)
	{
		resize();
	}

	data[size++] = element;
}

template <typename T>
T Vector<T>::getAt(const unsigned int index)const
{
	if (index > size - 1)
	{
		throw "OFF BOUNDARIES";
	}
	return data[index];
}

template <typename T>
void Vector<T>::setAt(const unsigned int index, const T element)
{
	if (index > size - 1)
	{
		throw "OFF BOUNDARIES";
	}
	data[index] = element;
}

template <typename T>
unsigned int Vector<T>::getSize()const
{
	return size;
}

template <typename T>
unsigned int Vector<T>::getCapacity()const
{
	return capacity;
}

template <typename T>
void Vector<T>::print()const
{
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << endl;
	}
}