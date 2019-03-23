/**********************************************************
// Workshop 2: Move and Copy Semantics
// Text.cpp
// Matheus Fernando Leitao
// 2019/01/22
**********************************************************/
#include <fstream>
#include <string>
#include <utility>
#include "Text.h"
using namespace std;

namespace sict {

	// no-argument default constructor
	Text::Text() {
		numRecords = 0;
		records = nullptr;
	}

	// one-argument constructor
	Text::Text(char* fileName) {
		string line;
		ifstream file(fileName);

		// counts the number of records present in the file
		numRecords = 0;
		while (!file.eof()) {
			getline(file, line);
			numRecords++;
		}
		file.clear();
		file.seekg(0);

		// allocates memory for that number of pointers to std::string object and copies the records into the objects
		records = nullptr;
		records = new string[numRecords];
		for (int i = 0; i < numRecords; i++) {
			getline(file, line);
			records[i] = line;
		}
		file.clear();
		file.close();
	}

	// copy constructor
	Text::Text(const Text& source) {
		init(source);
	}

	// copy assignment operator
	Text& Text::operator=(const Text& source) {
		if (this != &source) {
			delete[] records;
			init(source);
		}
		return *this;
	}

	// initializes the object for copy constructor and assignement operator
	void Text::init(const Text& source) {
		numRecords = source.numRecords;
		if (source.records != nullptr) {
			records = nullptr;
			records = new string[numRecords];
			for (int i = 0; i < numRecords; i++) {
				records[i] = source.records[i];
			}
		}
	}

	// move constructor
	Text::Text(Text&& source) {
		*this = std::move(source);
	}

	// move assignment operator
	Text& Text::operator=(Text&& source) {
		if (this != &source) {
			numRecords = source.numRecords;
			records = source.records;
			source.numRecords = 0u;
			source.records = nullptr;
		}
		return *this;
	}

	// destructor
	Text::~Text() {
		delete[] records;
		records = nullptr;
	}

	// returns the number of records stored in the current object
	size_t Text::size() const {
		return (numRecords > 0) ? numRecords - 1 : 0;
	}

}