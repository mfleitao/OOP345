/**********************************************************
// Workshop 3: Templates
// LVPair.h
// Matheus Fernando Leitao
// 2019/02/01
**********************************************************/
#ifndef SICT_LVPAIR_H_
#define SICT_LVPAIR_H_

#include <iostream>

namespace sict {

	template<typename L, typename V> class LVPair {
		L label;
		V value;

	public:
		LVPair() : label{ 0u }, value{ 0u }  { }
		LVPair(const L& lbl, const V& vlu) : label{ lbl }, value{ vlu } { }

		void display(std::ostream& os) const {
			os << label << " : " << value << std::endl;
		}

	};

	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L,V>& pair) {
		pair.display(os);
		return os;
	}

}

#endif