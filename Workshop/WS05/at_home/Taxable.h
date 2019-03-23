/**********************************************************
// Workshop 5: Functions
// Taxable.h
// Matheus Fernando Leitao
// 2019/02/014
**********************************************************/
#ifndef SICT_TAXABLE_H
#define SICT_TAXABLE_H

#include <iostream>

namespace sict {
	class Taxable {
		float taxRate;
	public:
		// one-arg constructor which leaves the object in safe empty state
		Taxable(const float tax) : taxRate(tax) { }

		// returns the sum of price and the tax
		float operator()(float price) const {
			return price * (taxRate + 1);
		}
	};
}

#endif
