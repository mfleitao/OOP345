/**********************************************************
// Workshop 4: Containers
// Message.cpp
// Matheus Fernando Leitao
// 2019/02/07
**********************************************************/
#include <iostream>
#include <string>
#include "Message.h"
using namespace std;
using namespace sict;

namespace sict {

	// hint:
	// array of messages (pointer array) dynamic memory
	// Message** m = new Message*[N];
	// const Message** m = new const Message*[N];
	// class N {
	//		const Message** m_m;
	// }
	// Notifications(const Message** m, n) : m_m(new const Message*[N]) { ... }
	
	// class A {
	//		const int a;
	// public:
	//		A(const int x) : a(x) { ... }
	// };

	// no-arg constructor which leave the object in safe empty state
	Message::Message() : userWhoSent{""}, message{""}, reply{""}, isReply{false} { }

	// 1-arg constructor which parses the whole string received into three different members
	Message::Message(const std::string& str) {
		size_t start = 0;
		size_t end = str.find(' ');
		isReply = (str.find('@') != string::npos);
		userWhoSent = str.substr(start, end);

		if (userWhoSent.size() > 0 && userWhoSent.size() < str.size()) {
			if (isReply) {
				start = end + 1;
				size_t atSymbol = str.find('@');
				end = str.find(' ', start);
				reply = str.substr(atSymbol + 1, (end-1) - atSymbol);
			}
			start = end + 1;
			message = str.substr(start, str.size());
		}
		else {
			*this = Message();
		}
	}

	// returns true if the object is in safe empty state
	bool Message::empty() const {
		return (message.size() <= 0);
	}

	// inserts the members stored in the current object into the ostream object
	void Message::display(std::ostream& os) const {
		if (!this->empty()) {
			os << ">User  : " << userWhoSent << std::endl;
			if (isReply) os << " Reply : " << reply << std::endl;
			os << " Tweet : " << message << std::endl;
		}
	}

}
