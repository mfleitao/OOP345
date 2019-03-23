
#ifndef SICT_STRING_H_
#define SICT_STRING_H_

#include <iostream>

namespace sict {

	const int MAX = 3;

	class String {
		char str[MAX + 1];

	public:
		String(const char* str);
		void display(std::ostream& os) const;

	};

	std::ostream& operator<<(std::ostream& os, const String& str);

}

#endif