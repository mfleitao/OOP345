/**********************************************************
// Workshop 1: Across Translation Units
// 2019/01/20
// Matheus Fernando Leitao
// ID: 148 300 171
// Description: at_home
**********************************************************/
#ifndef SICT_STRING_H_
#define SICT_STRING_H_

#include <iostream>

namespace sict {

	class String {
		char* str;
		int size;

	public:
		String(const char* str);
		void display(std::ostream& os) const;
		~String();
	};

	std::ostream& operator<<(std::ostream& os, const String& str);
}

#endif