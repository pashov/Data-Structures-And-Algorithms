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