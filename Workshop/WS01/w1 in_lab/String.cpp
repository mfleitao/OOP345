
#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;

extern int INITIAL;

namespace sict {

	String::String(const char* strInput) {
		if (strInput != nullptr && strInput[0] != '\0') {
			strncpy(str, strInput, MAX);
			str[MAX] = '\0';
		}
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