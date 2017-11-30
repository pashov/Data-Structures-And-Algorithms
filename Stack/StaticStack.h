#pragma once
//All of the code is in the header, since it's a template class.

const unsigned int MAX_SIZE = 1000;
template <typename T>
class StaticStack
{
private:
	T data[MAX_SIZE];
	unsigned int size;

public:
	StaticStack();

public:
	void push(const T&);
	void pop();
	bool isEmpty()const;

public:
	T top()const;
	bool isFull()const;
	unsigned int getSize()const;
	unsigned int getMaxSize()const;
};

template <typename T>
StaticStack<T>::StaticStack()
{
	size = 0;
}

template <typename T>
void StaticStack<T>::push(const T& element)
{
	if (isFull())
	{
		throw "FULL STACK"
	}
		data[size++] = element;
}

template <typename T>
void StaticStack<T>::pop()
{
	if (isEmpty())
	{
		throw "EMPTY STACK";
	}
	size--;
}

template <typename T>
bool StaticStack<T>::isEmpty()const
{
	return size == 0;
}

template <typename T>
T StaticStack<T>::top()const
{
	if (isEmpty())
	{
		throw "EMPTY STACK";
	}
	return data[size - 1];
}

template <typename T>
bool StaticStack<T>::isFull()const
{
	return size == MAX_SIZE;
}

template <typename T>
unsigned int StaticStack<T>::getSize()const
{
	return size;
}

template <typename T>
unsigned int StaticStack<T>::getMaxSize()const
{
	return MAX_SIZE;
}

