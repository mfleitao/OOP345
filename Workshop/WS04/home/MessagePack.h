/**********************************************************
// Workshop 4: Containers
// MessagePack.h
// Matheus Fernando Leitao
// 2019/02/07
**********************************************************/
#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H

#include <iostream>
#include "Message.h"

namespace sict {
	class MessagePack {
		Message* messages;
		size_t numElements;
	public:
		MessagePack();
		MessagePack(Message* m, size_t num);
		MessagePack(const MessagePack& src);
		MessagePack(MessagePack&& src);
		MessagePack& operator=(const MessagePack& src);
		MessagePack& operator=(MessagePack&& src);
		~MessagePack();
		void display(std::ostream& os) const;
		size_t size() const;
	};

	std::ostream& operator<<(std::ostream& os, const MessagePack& m);
}

#endif
