/**********************************************************
// Workshop 2: Move and Copy Semantics
// Text.h
// Matheus Fernando Leitao
// 2019/01/22
**********************************************************/
#ifndef SICT_TEXT_H_
#define SICT_TEXT_H_

#include <iostream>
#include <cstring>

namespace sict {

	class Text {
		std::string* records;
		int numRecords;

	public:
		Text();
		Text(char* fileName);
		Text(const Text& t);
		Text& operator=(const Text& t);
		void init(const Text& source);
		~Text();
		size_t size() const;

	};

}

#endif