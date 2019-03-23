// Workshop 8 - Smart Pointers
// Utilities.cpp
// Chris Szalwinski from Cornel Barna
// 2019/03/17

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sict {

	// compares the elements in the two received lists for common product codes and 
	// builds the user-friendly list from the matching pairs.
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		for (size_t i = 0; i < desc.size(); ++i) {
			for (size_t x = 0; x < price.size(); ++x) {
				if (desc[i].code == price[x].code) {
					Product* p = new Product(desc[i].desc, price[x].price);
					p->validate();
					priceList += p;
					delete p;
				}
			}
		}
		return priceList;
	}

}