// ***********************************************************
// Workshop 6 - STL Containers
// Sale.h
// Matheus Fernando Leitao
// Date: 2019/03/12
// ***********************************************************
#include <vector>
#include "Product.h"

#ifndef SICT_SALE_H
#define SICT_SALE_H

namespace sict {

	class Sale {
		std::vector<iProduct*> products;
	
	public:
		Sale(const char*);
		void display(std::ostream& os) const;
	};

}

#endif

