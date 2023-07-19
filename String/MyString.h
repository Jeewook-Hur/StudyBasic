#ifndef _MYSTRING_H
#define _MYSTRING_H

class MyString {
public:
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);
	~MyString();
	int length() const;
	void print() const;
	void println() const;

private:
	char* stringContent;
	int stringLength;
};

#endif // !_MYSTRING_H