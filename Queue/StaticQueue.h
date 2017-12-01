#pragma once
//All of the code is in the header, since it's a template class.
const int MAX_SIZE = 500;

template <typename T>
class StaticQueue
{
private:
	T data[MAX_SIZE];
	unsigned int size;

public:
	StaticQueue();

public:
	void enqueue(const T&);
	void dequeue();
	T first()const;
	bool isEmpty()const;

public:
	bool isFull()const;
	unsigned int getSize()const;
};

template <typename T>
StaticQueue<T>::StaticQueue()
{
	size = 0;
}

template <typename T>
void StaticQueue<T>::enqueue(const T& element)
{
	if (isFull())
	{
		throw "FULL QUEUE";
	}
		data[size++] = element;
}

template <typename T>
void StaticQueue<T>::dequeue()
{
	if (isEmpty())
	{
		throw "EMPTY QUEUE";
	}
	for (int i = 0; i < indexLast - 2; i++)
	{
		data[i] = data[i + 1];
	}
	size--;
}

template <typename T>
T StaticQueue<T>::first()const
{
	if (isEmpty())
	{
		throw "EMPTY QUEUE";
	}
	return data[0];
}

template <typename T>
bool StaticQueue<T>::isEmpty()const
{
	return size == 0;
}

template <typename T>
bool StaticQueue<T>::isFull()const
{
	return size == MAX_SIZE;
}

template <typename T>
unsigned int StaticQueue<T>::getSize()const
{
	return size;
}