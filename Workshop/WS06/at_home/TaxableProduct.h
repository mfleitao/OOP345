// ***********************************************************
// Workshop 6 - STL Containers
// TaxableProduct.h
// Matheus Fernando Leitao
// Date: 2019/03/12
// *********************************************************** 
#include <iostream>
#include <fstream>
#include "Product.h"

#ifndef SICT_TAXABLE_PRODUCT_H
#define SICT_TAXABLE_PRODUCT_H

namespace sict {
	 
	class TaxableProduct : public Product {
 		double taxRate;

 	public:
 		enum class TaxEnum { HST, PST };
		TaxableProduct();
 		TaxableProduct(int, double, char);
 		double price() const;
 		void display(std::ostream&) const;
 	};
	
 }

 #endif

