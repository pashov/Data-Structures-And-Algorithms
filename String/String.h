#pragma once

class String
{
private:
	char* data;
	unsigned int size;

private:
	void init();
	void copy(const String&);
	void destroy();
	int myStrLen(const char*)const;

public:
	String();
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

public:
	char getAt(const unsigned int)const;
	void setAt(const unsigned int, const char);
	char* getData()const;
	unsigned int getSize()const;

};
