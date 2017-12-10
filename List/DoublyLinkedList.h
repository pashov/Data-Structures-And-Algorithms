#pragma once
#include <iostream>
using namespace std;
//All of the code is in the header, since it's a template class.

template <typename T>
class DoublyLinkedList
{
private:
	struct Node
	{
		T data;
		Node* prev;
		Node* next;
		Node(const T data, Node* prev, Node* next)
		{
			this->data = data;
			this->prev = prev;
			this->next = next;
		}
	};

private:
	Node* first;
	Node* last;
	unsigned int size;

private:
	void init();
	void copy(const DoublyLinkedList<T>&);
	void destroy();

public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList<T>&);
	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&);
	~DoublyLinkedList();

public:
	void insertFirst(const T&);
	void removeFirst();
	void insertLast(const T&);
	void removeLast();
	void insertAfter(int, const T&);
	void remove(int);

public:
	void printForward()const;
	void printBackward()const;
	bool isEmpty()const;
	unsigned int getSize()const;
};

template <typename T>
void DoublyLinkedList<T>::init()
{
	first = last = nullptr;
	size = 0;
}

template <typename T>
void DoublyLinkedList<T>::copy(const DoublyLinkedList<T>& other)
{
	Node* toCopy = other.first;
	Node* copy = new Node(toCopy->data, nullptr, nullptr);
	Node* lastCopied = copy;
	first = lastCopied;

	while (toCopy->next)
	{
		toCopy = toCopy->next;
		copy = new Node(toCopy->data, lastCopied, nullptr);
		lastCopied->next = copy;
		lastCopied = copy;
	}
	last = lastCopied;
	size = other.size;
}

template <typename T>
void DoublyLinkedList<T>::destroy()
{
	while (!isEmpty())
	{
		Node* toDelete = first;
		first = first->next;
		delete toDelete;
		size--;
	}
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	init();
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other)
{
	init();
	copy(other);
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other)
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
DoublyLinkedList<T>::~DoublyLinkedList()
{
	destroy();
}

template <typename T>
void DoublyLinkedList<T>::insertFirst(const T& data)
{
	if (isEmpty())
	{
		first = last = new Node(data, nullptr, nullptr);
	}
	else
	{
		first->prev = new Node(data, nullptr, first);
		first = first->prev;
	}
	size++;
}

template <typename T>
void DoublyLinkedList<T>::removeFirst()
{
	if (isEmpty())
	{
		throw "EMPTY LIST";
	}
	else if (first == last)
	{
		delete first;
		first = last = nullptr;
	}
	else
	{
		Node* toDelete = first;
		first->next->prev = nullptr;
		first = first->next;
		delete toDelete;
	}
	size--;
}

template <typename T>
void DoublyLinkedList<T>::insertLast(const T& data)
{
	if (isEmpty())
	{
		first = last = new Node(data, nullptr, nullptr);
	}
	else
	{
		last->next = new Node(data, last, nullptr);
		last = last->next;
	}
	size++;
}

template <typename T>
void DoublyLinkedList<T>::removeLast()
{
	if (isEmpty())
	{
		throw "EMPTY LIST";
	}
	else if (first == last)
	{
		delete last;
		first = last = nullptr;
	}
	else
	{
		Node* toDelete = last;
		last->prev->next = nullptr;
		last = last->prev;
		delete toDelete;
	}
	size--;
}

template <typename T>
void DoublyLinkedList<T>::insertAfter(int index, const T& data)
{
	if (isEmpty())
	{
		throw "EMPTY LIST";
	}
	else if (index > size - 1 || index < 0)
	{
		throw "OFF BOUNDARIES";
	}
	else if (first == last || index == 0)
	{
		insertFirst(data);
	}
	else
	{
		Node* copy = first;
		while (index--)
		{
			copy = copy->next;
		}
		if (copy->next)
		{
			Node* toInsert = new Node(data, copy, copy->next);
			copy->next = copy->next->prev = toInsert;
		}
		else
		{
			insertLast();
		}
	}
	size++;
}

template <typename T>
void DoublyLinkedList<T>::remove(int index)
{
	if (isEmpty())
	{
		throw "EMPTY LIST";
	}
	else if (index > (size - 1) || index < 0)
	{
		throw "OFF BOUNDARIES";
	}
	else if (first == last || index == 0)
	{
		removeFirst();
	}
	else
	{
		Node* copy = first;
		while (index--)
		{
			copy = copy->next;
		}
		if (copy->next)
		{
			Node* toDelete = copy;
			copy->prev->next = copy->next;
			copy->next->prev = copy->prev;
			delete toDelete;
		}
		else
		{
			removeLast();
		}
	}
	size--;
}

template <typename T>
void DoublyLinkedList<T>::printForward()const
{
	if (isEmpty())
	{
		cout << "EMPTY" << endl;
	}
	else
	{
		Node* copy = first;
		while (copy)
		{
			cout << copy->data << " ";
			copy = copy->next;
		}
		cout << endl;
	}
}

template <typename T>
void DoublyLinkedList<T>::printBackward()const
{
	if (isEmpty())
	{
		cout << "EMPTY" << endl;
	}
	else
	{
		Node* copy = last;
		while (copy)
		{
			cout << copy->data << " ";
			copy = copy->prev;
		}
		cout << endl;
	}
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty()const
{
	return first == nullptr;
}

template <typename T>
unsigned int DoublyLinkedList<T>::getSize()const
{
	return size;
}