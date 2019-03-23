/**********************************************************
// Workshop 1: Across Translation Units
// 2019/01/20
// Matheus Fernando Leitao
// ID: 148 300 171
// Description: at_home
**********************************************************/

#include <iostream>
#include "String.h"

namespace sict {
	void process(const char* str) {
		String a = String(str);
		std::cout << a << std::endl;
	}
}
