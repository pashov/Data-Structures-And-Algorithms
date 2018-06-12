#pragma once
#include <iostream>
using namespace std;

class String
{
private:
	char* data;
	unsigned int size; //counting the '\0'

private:
	void init();
	void copy(const String&);
	void destroy();
	int myStrLen(const char*)const; //counting the '\0'

public:
	String();
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

	bool operator==(const String&)const;
	friend String operator+(const String&, const String&);
	friend ostream& operator<<(ostream&, const String&);
	friend istream& operator>>(istream&, String&);

public:
	char getAt(const unsigned int)const;
	void setAt(const unsigned int, const char);
	char* getData()const;
	unsigned int getSize()const;  //counting the '\0'

};
