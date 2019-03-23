/**********************************************************
// Workshop 5: Functions
// KVPair.h
// Matheus Fernando Leitao
// 2019/02/014
**********************************************************/

#ifndef SICT_KVPAIR_H
#define SICT_KVPAIR_H

#include <iostream>
#include <iomanip>
using namespace std;

extern int fieldWidth;

namespace sict {
	template<class K, class V> class KVPair {
		K key;
		V value;
	public:
		// no-arg constructor which leaves the object in a safe empty state
		KVPair() : key{}, value{} { }

		// two-arg constructor which initializes the members key and value
		KVPair(const K& k, const V& v) : key{ k }, value{ v } { }

		// inserts the object into a ostream object according to required format
		template<typename F> void display(std::ostream& os, F f) {
			os << left << setw(fieldWidth) << key << " " << ":" << " ";
			os << right << setw(fieldWidth) << value << setw(fieldWidth) << f(value) << endl;
		}
	};
}

#endif
