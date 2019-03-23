// ***********************************************************
// Assembly Line Project
// Utilities.h
// Matheus Fernando Leitao
// Date: 2019/03/02
// ***********************************************************
#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H

#include <iostream>
#include <string>

namespace sict {

	class Utilities {
		static char delimiter;
		static size_t fieldWidth;

	public:
		Utilities();
		const std::string extractToken(const std::string& str, size_t& next_pos);
		const char getDelimiter() const;
		size_t getFieldWidth() const;
		static void setDelimiter(const char d);
		void setFieldWidth(size_t);
	};

}

#endif