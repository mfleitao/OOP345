// ***********************************************************
// Workshop 6 - STL Containers
// Product.cpp
// Matheus Fernando Leitao
// Date: 2019/03/12
// ***********************************************************
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Product.h"
using namespace std;

extern int FW;

namespace sict {

	// non-arg constructor: leave object in safe empty state
	Product::Product() : productNumber{ 0 }, cost{ 0.0 } {}

	// two-arg constructor: initializes members of product
	Product::Product(int productNumber, double cost) : productNumber{ productNumber }, cost{ cost } { }

	// returns the price of product
	double Product::price() const {
		return cost;
	}

	// inserts the output of current object into a ostream object
	void Product::display(ostream & os) const {
		os << setw(FW) << productNumber << setw(FW) << cost << endl;
	}

	// helper which inserts data into a ostream object
	ostream& operator<<(ostream& os, const iProduct& product) {
		product.display(os);
		return os;
	}

	// reads a single record from file object file and then allocates memory for a product in the hierarchy
	iProduct* readRecord(ifstream& file) {
		iProduct* product = nullptr;
		double cost = 0;
		int productNumber = 0;
		file >> productNumber >> cost;
		product = new Product(productNumber, cost);
		return product;
	}

}