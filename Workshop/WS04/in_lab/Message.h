/**********************************************************
// Workshop 4: Containers
// Message.h
// Matheus Fernando Leitao
// 2019/02/07
**********************************************************/
#ifndef SICT_MESSAGE_H_
#define SICT_MESSAGE_H_

#include <iostream>
#include <string>

namespace sict {
	class Message {
		std::string userWhoSent;
		std::string message;
		std::string reply;
		bool isReply;
	public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
	};
}

#endif
