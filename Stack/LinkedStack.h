#pragma once
//All of the code is in the header, since it's a template class.

template <typename T>
class LinkedStack
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
	Node* top;
	unsigned int size;

private:
	void init();
	void copy(const LinkedStack<T>&);
	void destroy();

public:
	LinkedStack();
	LinkedStack(const LinkedStack<T>&);
	LinkedStack<T>& operator=(const LinkedStack<T>&);
	~LinkedStack();

public:
	void push(const T&);
	void pop();
	bool isEmpty()const;

public:
	T& peek()const;
	unsigned int getSize()const;
};

template <typename T>
void LinkedStack<T>::init()
{
	top = nullptr;
	size = 0;
}

template <typename T>
void LinkedStack<T>::copy(const LinkedStack<T>& other)
{
	if (other)
	{
		Node* toCopy = other.top;
		Node* copy = new Node(toCopy->data, nullptr);
		Node* lastCopied = copy;
		top = copy;
		while (toCopy->next)
		{
			toCopy = toCopy->next;
			copy = new Node(toCopy->data, nullptr);
			lastCopied->next = copy;
			lastCopied = copy;
		}
		size = other.size;
	}
}

template <typename T>
void LinkedStack<T>::destroy()
{
	while (top)
	{
		Node* toDelete = top;
		top = top->next;
		delete toDelete;
	}
	size = 0;
}

template <typename T>
LinkedStack<T>::LinkedStack()
{
	init();
}

template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& other)
{
	init();
	copy(other);
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& other)
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
LinkedStack<T>::~LinkedStack()
{
	destroy();
}

template <typename T>
void LinkedStack<T>::push(const T& data)
{
	top = new Node(data, top);
	size++;
}

template <typename T>
void LinkedStack<T>::pop()
{
	if (isEmpty())
	{
		throw "EMPTY STACK";
	}
	Node* toDelete = top;
	top = top->next;
	delete toDelete;
	size--;
}

template <typename T>
bool LinkedStack<T>::isEmpty()const
{
	return top == nullptr;
}

template <typename T>
T& LinkedStack<T>::peek()const
{
	if (isEmpty())
	{
		throw "EMPTY STACK";
	}
	return top->data;
}

template <typename T>
unsigned int LinkedStack<T>::getSize()const
{
	return size;
}