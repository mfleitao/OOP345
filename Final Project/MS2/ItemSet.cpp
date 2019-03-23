// ***********************************************************
// Assembly Line Project
// ItemSet.cpp
// Matheus Fernando Leitao
// Date: 2019/03/02
// ***********************************************************
#include <string>
#include <iomanip>
#include "Utilities.h"
#include "ItemSet.h"
using namespace std;

namespace sict {

	// contructor: extracts 4 tokens from the string then populates the object with those
	ItemSet::ItemSet(const string& record) {

		size_t nextPosition = record.find(util.getDelimiter());
		name = record.substr(0, nextPosition);
		serialNumber = stoul(util.extractToken(record, nextPosition));
		quantity = stoi(util.extractToken(record, nextPosition));
		description = util.extractToken(record, nextPosition);

		if (util.getFieldWidth() < name.length())
			util.setFieldWidth(name.length());
	}

	// move constructor
	ItemSet::ItemSet(ItemSet&& src) {
		if (this != &src) {
			name = src.name;
			description = src.description;
			serialNumber = src.serialNumber;
			quantity = src.quantity;

			src.name = "";
			src.description = "";
			src.serialNumber = 0;
			src.quantity = 0;
		}
	}

	// returns a reference to member "name"
	const string& ItemSet::getName() const {
		return name;
	}

	// returns a reference to member "serialNumber"
	const unsigned int ItemSet::getSerialNumber() const {
		return serialNumber;
	}

	// returns a reference to member "quantity"
	const unsigned int ItemSet::getQuantity() const {
		return quantity;
	}

	// reduces the number of items in stock and increase serialNumber 
	ItemSet& ItemSet::operator--() {
		quantity--;
		serialNumber++;
		return *this;
	}

	// inserts the current object into a ostream object
	void ItemSet::display(ostream& os, bool full) const {
		if (full) {
			os << left << setw(util.getFieldWidth()) << name;
			os << " [" << setw(5) << serialNumber << "]";
			os << " Quantity " << setw(3) << quantity << right;
			os << " Description: " << description << endl;
		}
	}

}

