#pragma once
//All of the code is in the header, since it's a template class.

#include <iostream>
using namespace std;

template <typename T>
class BSTree
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
		Node(const T data, Node* left, Node* right)
		{
			this->data = data;
			this->left = left;
			this->right = right;
		}
	};

private:
	Node* root;
	unsigned int size;

private:
	void init();
	Node* copy(Node* n)
	{
		if (!n)
		{
			return nullptr;
		}
		return new Node(n->data, copy(n->left), copy(n->right));
	}
	void destroy(Node*);

private:
	bool findHelp(T,  Node*)const;
	void insertHelp(T, Node*&);
	void removeHelp(T, Node*&);
	void printHelp(Node*)const;

public:
	BSTree();
	BSTree(const BSTree<T>&);
	BSTree<T>& operator=(const BSTree<T>&);
	~BSTree();

public:
	bool find(T)const;
	void insert(T);
	void remove(T);
	void print()const;
};

template <typename T>
void BSTree<T>::init()
{
	root = nullptr;
	size = 0;
}

template <typename T>
void BSTree<T>::destroy(Node* root)
{
	if (root)
	{
		destroy(root->left);
		destroy(root->right);
		delete root;
	}
}


template <typename T>
BSTree<T>::BSTree()
{
	init();
}

template <typename T>
BSTree<T>::BSTree(const BSTree& other)
{
	init();
	root = copy(other.root);
}

template <typename T>
BSTree<T>& BSTree<T>::operator=(const BSTree& other)
{
	if (this != *other)
	{
		destroy(root);
		init();
		root = copy(other.root);
	}
	return *this;
}

template <typename T>
BSTree<T>::~BSTree()
{
	destroy(root);
}

template <typename T>
bool BSTree<T>::findHelp(T toFind, Node* root)const
{
	if (!root)
	{
		return false;
	}
	else if (toFind == root->data)
	{
		return true;
	}
	else if (toFind < root->data)
	{
		return findHelp(toFind, root->left);
	}
	else
	{
		return findHelp(toFind, root->right);
	}
}

template <typename T>
void BSTree<T>::insertHelp(T toInsert, Node*& root)
{
	if (!root)
	{
		root = new Node(toInsert, nullptr, nullptr);
		size++;
	}
	else if (toInsert > root->data)
	{
		insertHelp(toInsert, root->right);
	}
	else if (toInsert < root->data)
	{
		insertHelp(toInsert, root->left);
	}
	else if (toInsert == root->data)
	{
		return;
	}
}

template <typename T>
void BSTree<T>::removeHelp(T toRemove, Node*& root)
{
	if (!root)
	{
		throw "NO SUCH ELEMENT";
	}
	if (toRemove == root->data)
	{
		if (root->left && root->right)
		{
			Node* copy = root->left;
			while (copy->right)
			{
				copy = copy->right;
			}
			root->data = copy->data;
			delete copy;
		}
		else if (root->left)
		{
			Node* toDelete = root;
			root = root->left;
			delete toDelete;
		}
		else
		{
			Node* toDelete = root;
			root = root->right;
			delete toDelete;
		}
	}
	else if (toRemove < root->data)
	{
		return removeHelp(toRemove, root->left);
	}
	else
	{
		return removeHelp(toRemove, root->right);
	}
}

template <typename T>
void BSTree<T>::printHelp(Node* root)const
{
	if (root)
	{
		printHelp(root->left);
		cout << root->data << " ";
		printHelp(root->right);
	}
}


template <typename T>
bool BSTree<T>::find(T data)const
{
	return findHelp(data, root);
}

template <typename T>
void BSTree<T>::insert(T data)
{
	insertHelp(data, root);
}

template <typename T>
void BSTree<T>::remove(T data)
{
	removeHelp(data, root);
}

template <typename T>
void BSTree<T>::print()const
{
	printHelp(root);
}