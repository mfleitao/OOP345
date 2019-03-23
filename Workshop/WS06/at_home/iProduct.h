// ***********************************************************
// Workshop 6 - STL Containers
// iProduct.h
// Matheus Fernando Leitao
// Date: 2019/03/12
// ***********************************************************
#include <iostream>

#ifndef SICT_IPRODUCT_H
#define SICT_IPRODUCT_H

namespace sict {

	class iProduct {
	public:
		virtual double price() const = 0;
		virtual void display(std::ostream& os) const = 0;
		iProduct* readRecord(std::ifstream& file);
	};

	std::ostream& operator<<(std::ostream& os, const iProduct& p);
}

#endif 

