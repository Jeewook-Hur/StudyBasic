#include<iostream>
#include<string>

#include "MyString.h"
using namespace std;

MyString::MyString(char c) {
	this->stringContent = new char[1];
	this->stringContent[0] = c;
	this->stringLength = 1;
}
MyString::MyString(const char* str) {
	this->stringLength = strlen(str);
	this->stringContent = new char[this->stringLength];
	for (int i = 0; i < this->stringLength; i++) {
		this->stringContent[i] = str[i];
	}
}
MyString::MyString(const MyString& str) {
	this->stringLength = str.stringLength;
	this->stringContent = new char[this->stringLength];
	for (int i = 0; i != this->stringLength; i++) {
		this->stringContent[i] = str.stringContent[i];
	}

}
MyString::~MyString() {
	delete[] this->stringContent;
}

void MyString::print() const{
	for (int i = 0; i < this->stringLength; i++) {
		cout << this->stringContent[i];
	}
}

void MyString::println() const{
	for (int i = 0; i < this->stringLength; i++) {
		cout << this->stringContent[i];
	}
	cout << endl;
}