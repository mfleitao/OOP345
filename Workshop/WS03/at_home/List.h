/**********************************************************
// Workshop 3: Templates
// List.h
// Matheus Fernando Leitao
// 2019/02/01
**********************************************************/
#ifndef SICT_LIST_H_
#define SICT_LIST_H_

#include <iostream>

namespace sict {

	// class template which a ("T") type for an array and its number of elements
	template<typename T, int N> class List {
		T arrayList[N];
		size_t numElements;

	public:
		// no-arg constructor which also initializes the "numElements"
		List() : numElements{ 0u } { }

		// returns the current number of elements stored
		size_t size() const {
			return numElements;
		}

		// operator which get the element according the its index in the "arrayList"
		const T& operator[](size_t i) const {
			const T& t = arrayList[i];
			return t;
		}

		// operator which stores the next element into the "arrayList" according to its limit declared by "N"
		void operator+=(const T& t) {
			if (numElements < N) {
				arrayList[numElements] = t;
				numElements++;
			}
		}
	};

	// template class which inherits "List" class and also has a new type "V"
	template<typename T, typename L, typename V, int N> class LVList : public List<T, N> {
	public:
		// returns the sum of all elements in the current object throughtout a local variable typed "V"
		V accumulate(const L& label) const {
			SummableLVPair<L, V> summable;
			V sumAllElements = summable.getInitialValue();
			for (size_t i = 0; i < ((List<T, N>&)*this).size(); i++) {
				if (label == ((List<T, N>&)*this)[i].getLabel())
					sumAllElements = ((List<T, N>&)*this)[i].sum(label, sumAllElements);
			}
			return sumAllElements;
		}
	};

}

#endif