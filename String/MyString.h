#ifndef _MYSTRING_H
#define _MYSTRING_H

class MyString {
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);
	~MyString();

	char* stringContent;
	int stringLength;
};

#endif // !_MYSTRING_H