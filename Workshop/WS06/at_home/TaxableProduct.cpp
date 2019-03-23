// ***********************************************************
// Workshop 6 - STL Containers
// TaxableProduct.h
// Matheus Fernando Leitao
// Date: 2019/03/12
// ***********************************************************  
#include <iostream>
 #include <string>
 #include "TaxableProduct.h"

 extern int FW;

 namespace sict {

	 // non-arg constructor: safe empty state
	 TaxableProduct::TaxableProduct() {}

 	// 3-argument constructor that creates the object - TaxableProduct contains a Product
 	TaxableProduct::TaxableProduct(int productNumber, double price, char status) : Product(productNumber, price) {
		taxRate = (status == 'H') ? 0.13 : 0.08;
	}

 	// Returns the price with tax (net price) of the product
 	double TaxableProduct::price() const {
 		return Product::price() * (1 + taxRate);
 	}

 	// Displays the information about the product with tax status
 	void TaxableProduct::display(std::ostream& os) const {
 		Product::display(os);
		std::string tax = (taxRate == 0.13) ? " HST" : " PST";
		os << tax;
 	}

 }
