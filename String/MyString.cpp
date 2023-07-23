#include<iostream>
#include<string>

#include "MyString.h"
using namespace std;

MyString::MyString(char c) {
	stringContent = new char[1];
	stringContent[0] = c;
	stringLength = 1;
	memoryCapacity = 1;
}
MyString::MyString(const char* str) {
	stringLength = strlen(str);
	stringContent = new char[stringLength];
	memoryCapacity = stringLength;
	for (int i = 0; i < stringLength; i++) {
		stringContent[i] = str[i];
	}
}
MyString::MyString(const MyString& str) {
	stringLength = str.stringLength;
	stringContent = new char[stringLength];
	memoryCapacity = stringLength;
	for (int i = 0; i != stringLength; i++) {
		stringContent[i] = str.stringContent[i];
	}

}
MyString::~MyString() {
	delete[] stringContent;
}

/*
* 함수명칭:assin
* 기능:입력받은 문자열로 대입한다. 
*/
MyString& MyString::assign(const MyString& str) {
	if (str.stringLength > memoryCapacity) { //입력하는 문자열의 길이가 현재 할당량보다 높으면
		//기존 할당을 제거하고 새로 할당한다.
		delete[] stringContent;
		stringContent = new char[str.stringLength];
		memoryCapacity = str.stringLength;
	}
	//입력받은 문자열 할당된 위치에 덮어쓴다. 
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

int MyString::capacity() {
	return memoryCapacity;
}

/*
* 함수명칭:reserve
* 기능:입력받은 크기가 현재할당크기보다 크면 그만큼 확장한다. 
*/
void MyString::reserve(int size) {
	if (size > memoryCapacity) { //입력받은 크기가 현재 할당크기보다 크면
		char* prevStirngContent = stringContent;
		stringContent = new char[size];
		memoryCapacity = size;
		for (int i = 1; i < stringLength; i++) {
			stringContent[i] = prevStirngContent[i];
		}
		delete[] prevStirngContent;
	}
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