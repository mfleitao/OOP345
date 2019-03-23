/**********************************************************
// Workshop 4: Containers
// MessagePack.cpp
// Matheus Fernando Leitao
// 2019/02/07
**********************************************************/
#include <iostream>
#include <utility>
#include "Message.h"
#include "MessagePack.h"
using namespace sict;

namespace sict {

	MessagePack::MessagePack() : messages{ nullptr }, numElements{ 0u } { }

	MessagePack::MessagePack(Message* msn, size_t num) {
		if (msn != nullptr && num > 0) {
			numElements = num;
			messages = new Message[numElements];
			for (int i = 0; i < numElements; i++)
				messages[i] = msn[i];
		}
	}

	MessagePack::MessagePack(const MessagePack& src) {
		*this = src;
	}

	MessagePack& MessagePack::operator=(const MessagePack& src) {
		if (this != &src) {
			numElements = src.numElements;
			delete[] messages;
			messages = new Message[src.numElements];
			for (int i = 0; i < numElements; i++) {
				messages[i] = src.messages[i];
			}
		}
		return *this;
	}

	MessagePack::MessagePack(MessagePack&& src) {
		*this = std::move(src);
	}

	MessagePack& MessagePack::operator=(MessagePack&& src) {
		if (this != &src) {
			messages = src.messages;
			numElements = src.numElements;
			src.messages = nullptr;
			src.numElements = 0;
		}
		return *this;
	}

	MessagePack::~MessagePack() {
		delete[] messages;
		messages = nullptr;
	}

	void MessagePack::display(std::ostream& os) const {
		for (int i = 0; i < numElements; i++) {
			if (!messages[i].empty())
				messages[i].display(os);
		}
	}

	size_t MessagePack::size() const {
		return numElements;
	}

	std::ostream& operator<<(std::ostream& os, const MessagePack& messagePack) {
		messagePack.display(os);
		return os;
	}

}
