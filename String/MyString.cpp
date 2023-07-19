#include<iostream>
#include<string>

#include "MyString.h"
using namespace std;

MyString::MyString(char c) {
	stringContent = new char[1];
	stringContent[0] = c;
	stringLength = 1;
}
MyString::MyString(const char* str) {
	stringLength = strlen(str);
	stringContent = new char[stringLength];
	for (int i = 0; i < stringLength; i++) {
		stringContent[i] = str[i];
	}
}
MyString::MyString(const MyString& str) {
	stringLength = str.stringLength;
	stringContent = new char[stringLength];
	for (int i = 0; i != stringLength; i++) {
		stringContent[i] = str.stringContent[i];
	}

}
MyString::~MyString() {
	delete[] stringContent;
}

MyString& MyString::assign(const MyString& str) {
	if (str.stringLength > memoryCapacity) {
		delete[] stringContent;
		stringContent = new char[str.stringLength];
		memoryCapacity = str.stringLength;
	}
	for (int i = 0; i < str.stringLength; i++) {
		stringContent[i] = str.stringContent[i];
	}
	stringLength = str.stringLength;
	return *this;
}

MyString& MyString::assign(const char* str) {
	int length = strlen(str);
	if (length > memoryCapacity) {
		delete[] stringContent;
		stringContent = new char[length];
		memoryCapacity = length;
	}
	for (int i = 0; i < length; i++) {
		stringContent[i] = str[i];
	}
	stringLength = length;
	return *this;
}


int MyString::length() const {
	return stringLength;
}

void MyString::print() const{
	for (int i = 0; i < stringLength; i++) {
		cout << stringContent[i];
	}
}

void MyString::println() const{
	for (int i = 0; i < stringLength; i++) {
		cout << stringContent[i];
	}
	cout << endl;
}