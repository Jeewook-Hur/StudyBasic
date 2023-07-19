#include<iostream>
#include<string>
#include "MyString.h"
using namespace std;


int main(int argc, char* argv) {
	MyString str("Hello World!");

	str.print();
	str.print();
	str.println();
	str.print();
	cout << endl << str.length() << endl;

	return 0;
}