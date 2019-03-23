// ***********************************************************
// Assembly Line Project
// Utilities.cpp
// Matheus Fernando Leitao
// Date: 2019/03/02
// ***********************************************************
#include <iostream>
#include <string>
#include "Utilities.h"
using namespace std;

namespace sict {

	char Utilities::delimiter = { '\0' };
	size_t Utilities::fieldWidth = { 0 };

	// no-Arg Constructor
	Utilities::Utilities() {}

	// extracts the next token in the string starting at the position "nextPosition"
	const string Utilities::extractToken(const string& str, size_t& nextPosition) {

		size_t nextDelimiterPosition = str.find(delimiter, nextPosition + 1);
		size_t lengthOfWord = (nextDelimiterPosition - nextPosition) - 1;
		string token = str.substr(nextPosition + 1, lengthOfWord);
		nextPosition = nextDelimiterPosition;
		return token;
	}

	// returns a reference to member "delimiter"
	const char Utilities::getDelimiter() const {
		return delimiter;
	}

	// returns a reference to member "delimiter"
	size_t Utilities::getFieldWidth() const {
		return fieldWidth;
	}

	// sets "delimiter" member
	void Utilities::setDelimiter(const char delimitr) {
		delimiter = delimitr;
	}

	// sets "fieldWidth" member
	void Utilities::setFieldWidth(size_t fdWidth) {
		fieldWidth = fdWidth;
	}

}