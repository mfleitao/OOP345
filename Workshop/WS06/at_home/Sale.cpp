// ***********************************************************
// Workshop 6 - STL Containers
// Sale.cpp
// Matheus Fernando Leitao
// Date: 2019/03/12
// ***********************************************************
#include <fstream>
#include <string>
#include <iomanip>
#include "Sale.h"
#include "Product.h"
using namespace std;

extern int FW;

namespace sict {

	// single-arg constructor: also opens the file, read it then moves to a container 
	Sale::Sale(const char* file) { 
		if (file != nullptr && file[0] != '\0') {
			int count = 0;
			string bfr;
			ifstream fs;
			fs.open(file);
			if (!fs.is_open()) {
				throw "The file could not be opened";
			}
			else {
				while (getline(fs, bfr)) count++;
				fs.clear();
				fs.seekg(0, ios::beg);
				for (int i = 0; i < count; i++)
					products.push_back(readRecord(fs));
				fs.close();
			}
		}
		else {
			throw "The file does not exist or its name is incorrect";
		}
	}

	// inserts the current object into a ostream object
	void Sale::display(ostream& os) const {
		os << endl << "Product No" << setw(FW) << "Cost" << " " << "Taxable" << endl;
		double totalCost = 0.0;
		for (auto& product : products) {
			os << *product << fixed << setprecision(2) << endl;
			totalCost += product->price();
		}
		os << setw(FW) << "Total" << setw(FW) << totalCost << endl;
	}

}

