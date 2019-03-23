/**********************************************************
// Workshop 2: Move and Copy Semantics
// Timekeeper.h
// Matheus Fernando Leitao
// 2019/01/22
**********************************************************/
#ifndef SICT_TIMEKEEPER_H_
#define SICT_TIMEKEEPER_H_
#include <chrono>
#include <cstring>

namespace sict {

	const int MAX_RECORDS = 10;
	const std::string UNITS = "seconds";

	class Timekeeper {
		int recordIndex;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;

		struct {
			char* message;
			char* units;
			std::chrono::steady_clock::duration duration;
		} records[MAX_RECORDS];

	public:
		Timekeeper();
		void start();
		void stop();
		void recordEvent(const char* eventDesc);
		void report(std::ostream& os);

	};
}
#endif