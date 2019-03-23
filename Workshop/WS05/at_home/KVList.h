/**********************************************************
// Workshop 5: Functions
// KVList.h
// Matheus Fernando Leitao
// 2019/02/014
**********************************************************/

#ifndef SICT_KVLIST_H
#define SICT_KVLIST_H

#include <iostream>

namespace sict {
	template<class T> class KVList {
		T* list;
		int numElements;
		int numCurrentElements;
	public:
		// no-arg constructor which leaves the object in a safe empty state
		KVList() : list{ nullptr }, numElements{ 0 }, numCurrentElements{ 0 } { }

		// one-arg constructor which initializes the members of class
		KVList(int size) {
			list = nullptr;
			numElements = 0;
			numCurrentElements = 0;
			if (size > 0) {
				list = new T[size];
				numElements = size;
			}
			else {
				// number of elements (SIZE) is 0 (Zero) or a negative number
				throw "ERROR: The number of elements received in the constructor is not positive-valued";
			}
		}

		// move contructor
		KVList(KVList&& src) {
			if (this != &src) {
				list = src.list;
				numElements = src.numElements;
				numCurrentElements = src.numCurrentElements;
				src.list = nullptr;
				src.numElements = 0;
				src.numCurrentElements = 0;
			}
		}

		// destructor
		~KVList() {
			delete[] list;
			list = nullptr;
		}

		// operator which returns a reference to a list element
		const T& operator[](size_t i) const {
			// first check if the value of "i" is out of bound (does not exist)
			if (numElements > 0) {
				throw "ERROR: The index passed to the subscripting operator is out-of-bounds";
			}
			return list[i];
		}

		// inserts each list object into an ostream object through a display function
		template<typename F> void display(std::ostream& os, F f) {
			for (int i = 0; i < numElements; i++) {
				list[i].display(os, f);
			}
		}

		// checks if there is room to add a new element
		void push_back(const T& t) {
			if (numCurrentElements + 1 <= numElements) {
				list[numCurrentElements] = t;
			}
			numCurrentElements++;
		}

		// functions which are disable (copy and move assignment operators and copy constructor)
		KVList(const KVList& src) = delete;
		KVList& operator=(const KVList& src) = delete;
		KVList& operator=(KVList&& src) = delete;
	};
}

#endif
