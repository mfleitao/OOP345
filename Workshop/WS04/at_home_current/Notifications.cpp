/**********************************************************
// Workshop 4: Containers
// Notifications.cpp
// Matheus Fernando Leitao
// 2019/02/07
**********************************************************/
#include <iostream>
#include <utility>
#include "Notifications.h"

namespace sict {

	Notifications::Notifications() : messageObjects{ nullptr }, maxAddrs{ 0 }, numAddrs{ 0 } { }

	Notifications::Notifications(size_t maxNumElements) {
		if (maxNumElements > 0) {
			messageObjects = new const Message*[maxNumElements];
			maxAddrs = maxNumElements;
			numAddrs = 0;
		}
		else {
			*this = Notifications();
		}
	}

	Notifications::Notifications(const Notifications& notification) {
		*this = notification;
	}

	Notifications& Notifications::operator=(const Notifications& notification) {
		if (this != &notification) {
			maxAddrs = notification.maxAddrs;
			numAddrs = notification.numAddrs;
			messageObjects = new const Message*[maxAddrs];
			for (int i = 0; i < numAddrs; i++)
				messageObjects[i] = notification.messageObjects[i];
		}
		return *this;
	}

	Notifications::Notifications(Notifications&& notification) {
		*this = std::move(notification);
	}

	Notifications& Notifications::operator=(Notifications&& notification) {
		if (this != &notification) {
			messageObjects = notification.messageObjects;
			maxAddrs = notification.maxAddrs;
			numAddrs = notification.numAddrs;
			
			notification.messageObjects = nullptr;
			notification.maxAddrs = 0;
			notification.numAddrs = 0;
		}
		return *this;
	}

	Notifications::~Notifications() {
		delete[] messageObjects;
		messageObjects = nullptr;
	}

	Notifications& Notifications::operator+=(const Message& msg) {
		if (numAddrs < maxAddrs) {
			if (!msg.empty()) {
				messageObjects[numAddrs] = &msg;
				numAddrs++;
			}
		}
		return *this;
	}

	Notifications& Notifications::operator-=(const Message& msg) {
		for (int i = 0; i < numAddrs; i++) {
			if (messageObjects[i] == &msg) {
				messageObjects[i] = nullptr;
				for (int j = 0; j < numAddrs; j++) {
					messageObjects[j] = messageObjects[j + 1];
				}
				messageObjects[numAddrs - 1] = nullptr;
			}
		}
		numAddrs--;
		return *this;
	}

	void Notifications::display(std::ostream& os) const {
		for (int i = 0; i < numAddrs; i++)
			messageObjects[i]->display(os);
	}

	size_t Notifications::size() const {
		return numAddrs;
	}

	std::ostream & operator<<(std::ostream & os, Notifications & notification) {
		notification.display(os);
		return os;
	}

}
