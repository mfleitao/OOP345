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

	template<typename T, int N> class List {
		T array[N];
		unsigned numElements;

	public:
		List() : numElements{ 0u } { }

		size_t size() const {
			return numElements;
		}

		const T& operator[](size_t i) const {
			return array[i];
		}

		void operator+=(const T& t) {
			if (numElements < N) {
				array[numElements] = t;
				numElements++;
			}
		}

	};

}

#endif