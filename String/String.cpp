#include "stdafx.h"
#include "String.h"


void String::init()
{
	data = nullptr;
	size = 0;
}

void String::copy(const String& other)
{
	data = new char[other.size];
	for (int i = 0; i < other.size; i++)
	{
		data[i] = other.data[i];
	}
	size = other.size;
}

void String::destroy()
{
	delete[] data;
}

int String::myStrLen(const char* str)const
{
	int counter = 0;
	do
	{
	} while (str[counter++] != '\0');
	return counter;
}

String::String()
{
	init();
}

String::String(const char* str)
{
	int strSize = myStrLen(str);
	data = new char[strSize];
	for (int i = 0; i < strSize; i++)
	{
		data[i] = str[i];
	}
	size = strSize;
}

String::String(const String& other)
{
	init();
	copy(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		destroy();
		init();
		copy(other);
	}
	return *this;
}

String::~String()
{
	destroy();
}


bool String::operator==(const String& str) const
{
	if (size != str.size)
	{
		return false;
	}
	for (unsigned int i = 0; i < size; i++)
	{
		if (data[i] != str.data[i])
		{
			return false;
		}
	}
	return true;
}

String operator+(const String& lst, const String& rst)
{
	if (lst.size != 0 && rst.size == 0)
	{
		return lst;
	}
	if (lst.size == 0 && rst.size != 0)
	{
		return rst;
	}
	int newSize = lst.size + rst.size;
	char* temp = new char[newSize];
	for (int i = 0; i < lst.size; i++)
	{
		temp[i] = lst.data[i];
	}
	for (int i = lst.size - 1; i < newSize; i++)
	{
		temp[i] = rst.data[i - (lst.size - 1)];

	}
	return (String)temp;
}

char String::getAt(const unsigned int index)const
{
	if (index > size - 1)
	{
		throw "OFF BOUNDARIES";
	}
	return data[index];
}

void String::setAt(const unsigned int index, const char toSet)
{
	if (index > size - 1)
	{
		throw "OFF BOUNDARIES";
	}
	data[index] = toSet;
}

char* String::getData()const
{
	return data;
}

unsigned int String::getSize()const
{
	return size;
}