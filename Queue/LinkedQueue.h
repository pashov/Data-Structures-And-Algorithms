#pragma once
//All of the code is in the header, since it's a template class.

template <typename T>
class LinkedQueue
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node(const T data, Node* next)
		{
			this->data = data;
			this->next = next;
		}
	};

private:
	Node* first;
	Node* last;
	unsigned int size;

private:
	void init();
	void copy(const LinkedQueue<T>&);
	void destroy();

public:
	LinkedQueue();
	LinkedQueue(const LinkedQueue<T>&);
	LinkedQueue<T>& operator=(const LinkedQueue<T>&);
	~LinkedQueue();

public:
	void enqueue(const T&);
	void dequeue();
	T first()const;
	bool isEmpty()const;

public:
	unsigned int getSize()const;
};

template <typename T>
void LinkedQueue<T>::init()
{
	first = last = nullptr;
	size = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue& other)
{
	Node* toCopy = other.first;
	Node* copy = new Node(toCopy->data, nullptr);
	Node* lastCopied = toCopy;
	first = toCopy;
	while (toCopy->next)
	{
		toCopy = toCopy->next;
		copy = new Node(toCopy->data, nullptr);
		lastCopied->next = copy;
		lastCopied = copy;
	}
	last = lastCopied;
	size = other.size;
}

template <typename T>
void LinkedQueue<T>::destroy()
{
	while (!isEmpty())
	{
		Node* toDelete = first;
		first = first->next;
		delete toDelete;
	}
	size = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue()
{
	init();
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& other)
{
	init();
	copy(other);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& other)
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
LinkedQueue<T>::~LinkedQueue()
{
	destroy();
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& data)
{
	if (isEmpty())
	{
		first = last = new Node(data, nullptr);
	}
	else
	{
		last->next = new Node(data, nullptr);
		last = last->next;
	}
	size++;
}

template <typename T>
void LinkedQueue<T>::dequeue()
{
	if (isEmpty())
	{
		throw "EMPTY QUEUE";
	}
	if (size == 1)
	{
		Node* toDelete = first;
		first = last = nullptr;
		delete toDelete;
	}
	else
	{
		Node* toDelete = first;
		first = first->next;
		delete toDelete;
	}
	size--;
}

template <typename T>
T LinkedQueue<T>::first()const
{
	if (isEmpty())
	{
		throw "EMPTY QUEUE";
	}
	return first->data;
}

template <typename T>
bool LinkedQueue<T>::isEmpty()const
{
	return first == nullptr;
}

template <typename T>
unsigned int LinkedQueue<T>::getSize()const
{
	return size;
}