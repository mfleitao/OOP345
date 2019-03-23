/**********************************************************
// Workshop 1: Across Translation Units
// 2019/01/20
// Matheus Fernando Leitao
// ID: 148 300 171
// Description: at_home
**********************************************************/
#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;

extern int INITIAL;

namespace sict {

	String::String(const char* strInput) {
		if (strInput != nullptr && strInput[0] != '\0') {
			size = strlen(strInput);
			str = nullptr;
			str = new char[size + 1];
			strncpy(str, strInput, size);
			str[size] = '\0';
		}
	}

	String::~String() {
		delete[] str;
		str = nullptr;
	}

	void String::display(std::ostream& os) const {
		os << str;
	}

	std::ostream& operator<<(std::ostream& os, const String& str) {
		static int item = INITIAL;
		cout << item << ": ";
		str.display(os);
		item++;
		return cout;
	}


}