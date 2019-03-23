/**********************************************************
// Workshop 4: Containers
// MessagePack.cpp
// Matheus Fernando Leitao
// 2019/02/07
**********************************************************/
#include <iostream>
#include "Message.h"
#include "MessagePack.h"
using namespace sict;

namespace sict {

	MessagePack::MessagePack() : message{ nullptr }, numElements{ 0u } { }

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

	MessagePack::MessagePack(const Message* msn, size_t num) {
		if (msn != nullptr && num > 0) {
			numElements = num;
			message = nullptr;
			message = new const Message*[num];
			for (int i = 0; i < numElements; i++)
				message[i] = msn[i];
		}
	}

	MessagePack::MessagePack(const MessagePack& src) {
		numElements = src.numElements;
		if (src.message != nullptr) {
			message = nullptr;
			message = new Message*[numElements];
			for (int i = 0; i < numElements; i++)
				message[i] = src.message[i];
		}
	}

	MessagePack::MessagePack(MessagePack&& src) {}

	MessagePack& MessagePack::operator=(const MessagePack& src) {}
	
	MessagePack& MessagePack::operator=(MessagePack&& src) {}

	MessagePack::~MessagePack() {}

	void MessagePack::display(std::ostream& os) const {}
	
	size_t MessagePack::size() const {}

	std::ostream& operator<<(std::ostream& os, const MessagePack& m) {}
}
