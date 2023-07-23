#ifndef _MYSTRING_H
#define _MYSTRING_H

class MyString {
public:
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);
	~MyString();

	MyString& assign(const MyString& str);
	MyString& assign(const char* str);
	int capacity();
	void reserve(int size);

	int length() const;
	void print() const;
	void println() const;

private:
	char* stringContent;
	int stringLength;
	int memoryCapacity;
};

#endif // !_MYSTRING_H