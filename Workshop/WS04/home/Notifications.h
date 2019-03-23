/**********************************************************
// Workshop 4: Containers
// Notifications.h
// Matheus Fernando Leitao
// 2019/02/07
**********************************************************/
#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H
#include <iostream>
#include "Message.h"

namespace sict {
	class Notifications {
		const Message** messageObjects;
		int maxAddrs;
		int numAddrs;
	public:
		Notifications();
		Notifications(size_t maxNumElements);
		Notifications(const Notifications& notification);
		Notifications& operator=(const Notifications& notification);
		Notifications(const Notifications&& notification);
		Notifications& operator=(Notifications&& notification);
		~Notifications();

		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		size_t size() const;
	};

	std::ostream & operator<<(std::ostream & os, Notifications & notification);
}

#endif
