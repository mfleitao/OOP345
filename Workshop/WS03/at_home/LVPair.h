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
		// no-arg constructor also leaves the object in a safe empty state
		LVPair() : label{ }, value{ } { }

		// two-arg constructor which initializes the members "label" and "value"
		LVPair(const L& lbl, const V& vlu) : label(lbl), value(vlu) { }

		// return that returns the private member "label"
		const L& getLabel() const { return label; }

		// return that returns the private member "value"
		const V& getValue() const { return value; }

		// inserts the values of "label" and "value" into the std::ostream
		virtual void display(std::ostream& os) const {
			os << label << ": " << value << std::endl;
		}
	};

	// declaration for the operator "<<" which calls "display()" then returns std::ostream for cascading
	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}

	// template class which inherits "LVPair" class
	template<typename L, typename V> class SummableLVPair : public LVPair<L, V> {
		static V initial;
		static size_t field;
	public:
		// no-arg constructor
		SummableLVPair() { }

		// two-arg constructor which calls LVPair constructor and also increases the stored field
		SummableLVPair(const L& label, const V& v) : LVPair<L, V>(label, v) {
			if (field < label.size())
				field = label.size() + 1;
		}

		// returns the value of the class variable "initial"
		static const V& getInitialValue() {
			return initial;
		}

		// calls sum() function
		V append(const L& label, const V& value) const {
			sum(label, value);
		}

		// return the sum of the values of the current object and the accumulated sum in V object 
		V sum(const L& label, const V& sum) const {
			if (label == LVPair<L, V>::getLabel())
				return LVPair<L, V>::getValue() + sum;
			return 0;
		}

		// set the layout output for left then the width according to the "field" member
		// then calls display() function from LVPair class and then unseft the output left
		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(field);
			LVPair<L, V>::display(os);
			os.unsetf(std::ios::left);
		}
	};

	// initialization of the field as static
	template<typename L, typename V>
	size_t SummableLVPair<L, V>::field{ 0u };

	// specialization - LVList<std::string, std::string> 
	template<> 
	std::string SummableLVPair<std::string, std::string>::initial = "";

	// specialization - LVList<std::string, int>
	template<> 
	int SummableLVPair<std::string, int>::initial = 0;

	// specialization - sum() for LVList<std::string, std::string> 
	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& sum) const {
		return sum + " " + SummableLVPair<std::string, std::string>::getValue();
	};

}

#endif