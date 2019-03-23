// ***********************************************************
// Assembly Line Project
// CustomerOrder.cpp
// Matheus Fernando Leitao
// Date: 2019/03/20
// ***********************************************************
#include <vector>
#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"
#include "ItemSet.h"
#include "Utilities.h"
using namespace std;

namespace sict {

	size_t CustomerOrder::fieldWidth = 0;

	// default constructor for safe empty state.
	CustomerOrder::CustomerOrder() : itemInfo{ nullptr }, customerName{ "" }, productName{ "" }, numberItems{ 0 } { }

	// one-argument constructor that receives a reference to an unmodifiable string.
	CustomerOrder::CustomerOrder(const string& record) {
		size_t delimiter_pos = record.find(util.getDelimiter());
		customerName = record.substr(0, delimiter_pos);
		if (fieldWidth < util.getFieldWidth())
			fieldWidth = util.getFieldWidth();

		productName = util.extractToken(record, delimiter_pos);
		numberItems = count(record.begin(), record.end(), util.getDelimiter()) - 1;
		itemInfo = new ItemInfo[numberItems];
		if (numberItems > 0) {
			for (size_t i = 0; i < numberItems; i++)
				itemInfo[i].name = util.extractToken(record, delimiter_pos);
		}
		else {
			throw "Error: There are no items found";
		}
	}

	// move constructor
	CustomerOrder::CustomerOrder(CustomerOrder&& other) {
		*this = move(other);
	}

	// move assignment operator
	CustomerOrder & CustomerOrder::operator=(CustomerOrder&& other) {
		if (this != &other) {
			customerName = other.customerName;
			productName = other.productName;
			numberItems = other.numberItems;
			itemInfo = other.itemInfo;
			other.itemInfo = nullptr;
		}
		return *this;
	}

	// destructor
	CustomerOrder::~CustomerOrder() {
		delete[] itemInfo;
		itemInfo = nullptr;
	}

	// checks each item request, fills it if the requested item is available and the request has not been filled, 
	// reports the filling in the format shown below and decrements the item stock by one
	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {
		for (size_t i = 0; i < numberItems; ++i) {
			if (item.getName() == itemInfo[i].name) {
				if (item.getQuantity() == 0) {
					os << " Unable to fill ";
					os << getNameProduct() << "[" << itemInfo[i].name << "][" << itemInfo[i].serialNumer << "]";
					os << " out of stock" << endl;
				}
				else {
					if (itemInfo[i].filledStatus) {
						os << " Unable to fill ";
						os << getNameProduct() << "[" << itemInfo[i].name << "][" << itemInfo[i].serialNumer << "]";
						os << " already filled" << endl;
					}
					else {
						itemInfo[i].filledStatus = true;
						itemInfo[i].serialNumer = item.getSerialNumber();
						item.operator--();
						os << " Filled ";
						os << getNameProduct() << "[" << itemInfo[i].name << "][" << itemInfo[i].serialNumer << "]" << endl;
					}
				}

			}
		}
	}

	// searches the list of items requested and returns true if all have been filled
	bool CustomerOrder::isFilled() const {
		for (size_t i = 0; i < numberItems; ++i)
			if (!itemInfo[i].filledStatus)
				return false;
		return true;
	}

	// search the item request list for that item and returns true if all requests for that item have been filled
	bool CustomerOrder::isItemFilled(const string& itemName) const {
		for (size_t i = 0; i < numberItems; ++i) {
			if (itemInfo[i].name == itemName) {
				if (!itemInfo->filledStatus)
					return false;
			}
		}
		return true;
	}

	// returns the name of the customer and their product
	string CustomerOrder::getNameProduct() const {
		return customerName + " [" + productName + "]";
	}

	// inserts the data for the current object into stream object
	void CustomerOrder::display(ostream & os, bool showDetail) const {
		os << left << setw(fieldWidth) << customerName << " [" << productName << "]" << endl;
		if (!showDetail) {
			for (size_t i = 0; i < numberItems; i++)
				os << setfill(' ') << setw(fieldWidth + 1) << "    " << right << itemInfo[i].name << endl;
		}
	}

}