// Workshop 5 - Functions
// w5.cpp
// Chris Szalwinski
// 2019/02/10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "KVPair.h"
#include "KVList.h"
#include "Taxable.h"
using namespace sict;

float HST = 0.13f;
int fieldWidth = 10;

std::string getGradeLetter(float grade);

template <typename L, typename T, typename K, typename V>
L createList(char* filename) {
	std::ifstream file(filename);
	if (!file) {
		L list(0);
		return std::move(list);
	}
	int no_records = 0;
	do {
		char c = file.get();
		if (file.good() && c == '\n') no_records++;
	} while (!file.eof());
	file.clear();
	file.seekg(std::ios::beg);
	L list(no_records);
	do {
		K key;
		V value;
		file >> key;
		if (file) {
			file >> value;
			file.ignore();
			list.push_back(T(key, value));
		}
	} while (file);

	return std::move(list);
}

int main(int argc, char* argv[]) {

	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	// Processing PriceList File ------------------------------------------------------------------------------------
	try {
		// check for command line errors
		// now it waits for 3 parameters instead of 2 
		if (argc != 3) exit(1); // 1 first exit (the number of parameters is different than expected)
			
		// set for fixed, 2-decimal point output
		std::cout << std::fixed << std::setprecision(2);

		// process price list file
		KVList<KVPair<std::string, float>> priceList =
			createList<KVList<KVPair<std::string, float>>, KVPair<std::string, float>, std::string, float>(argv[1]);

		std::cout << "\nPrice List with G+S Taxes Included\n==================================\n";
		std::cout << "Description:      Price Price+Tax\n";
		priceList.display(std::cout, Taxable(HST));
	}
	catch (const std::exception& e) {
		std::cerr << "ERROR: Process of PriceList File [" << e.what() << "]" << std::endl;
		exit(2); // 2 second exit (error processing PriceList file)
	}

	// Processing Student File --------------------------------------------------------------------------------------
	try {
		// process the student file to get the grades
		KVList<KVPair<int, float>> studentsGrades = 
			createList<KVList<KVPair<int, float>>, KVPair<int, float>, int, float>(argv[2]);

		std::cout << "\nStudent List Letter Grades Included\n===================================\n";
		std::cout << "Student No :      Grade    Letter\n";
		// lambda expression used for conversion instead of functor
		studentsGrades.display(std::cout, [](float grade) -> std::string {
			return getGradeLetter(grade);
		});
	}
	catch (const std::exception& e) {
		std::cerr << "ERROR: Process of Student File [" << e.what() << "]" << std::endl;
		exit(3); // 3 third exit (error processing Student file)
	}

}

// function used to get the grade letter based on the grade number
std::string getGradeLetter(float grade) {
	if (grade >= 90 && grade <= 100) 
		return "A+";
	else if (grade >= 80 && grade <= 89.9) 
		return "A ";
	else if (grade >= 75 && grade <= 79.9) 
		return "B+";
	else if (grade >= 70 && grade <= 74.9) 
		return "B ";
	else if (grade >= 65 && grade <= 69.9) 
		return "C+";
	else if (grade >= 60 && grade <= 64.9) 
		return "C ";
	else if (grade >= 55 && grade <= 59.9) 
		return "D+";
	else if (grade >= 50 && grade <= 54.9) 
		return "D ";
	else								   
		return "F ";
}