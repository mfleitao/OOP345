/**********************************************************
// Workshop 2: Move and Copy Semantics
// Timekeeper.cpp
// Matheus Fernando Leitao
// 2019/01/22
**********************************************************/
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstring>
#include "Timekeeper.h"
using namespace std;

namespace sict {

	// no-argument constructor which initializes the "recordIndex" with zero '0'
	Timekeeper::Timekeeper() : recordIndex{ 0u } { }

	// starts the time for the current event 
	void Timekeeper::start() {
		startTime = chrono::steady_clock::now();
	}

	// stops the time for the current event 
	void Timekeeper::stop() {
		endTime = chrono::steady_clock::now();
	}

	// stores the current record into the object list
	void Timekeeper::recordEvent(const char* eventDesc) {
		// eventDesc to1 next time record
		records[recordIndex].message = nullptr;
		records[recordIndex].message = new char[strlen(eventDesc) + 1];
		strcpy(records[recordIndex].message, eventDesc);
		records[recordIndex].message[strlen(eventDesc)] = '\0';

		// calculates the duration of the event then copies it into the next time record
		records[recordIndex].duration = chrono::duration_cast<chrono::seconds>(endTime - startTime);

		// copies the address of the literal string containing a description of the units of time into the next time records
		records[recordIndex].units = nullptr;
		records[recordIndex].units = new char[strlen(UNITS.c_str()) + 1];
		strcpy(records[recordIndex].units, UNITS.c_str());
		records[recordIndex].units[strlen(UNITS.c_str())] = '\0';

		// increments the instance variable that identifies the next empty time record
		recordIndex++;
	}

	// displays all records whithin the object list
	void Timekeeper::report(std::ostream& os) {
		os << "\nExecution Times:" << endl;
		// inserts each of the time records stored in the Timekeeper object.
		for (int i = 0; i < recordIndex; i++) {
			os << records[i].message << " ";
			os << records[i].duration.count() << " ";
			os << records[i].units << endl;
		}
	}

}