
#include <iostream>
#include <cstring>
#include "String.h"
#include "process.h"
using namespace std;
using namespace sict;

int INITIAL = 3;

int main(int argLen, char* args[]) {

	if (argLen <= 1) {
		cout << "***Insufficient number of arguments***" << endl;
		return 1;
	}
	else {
		cout << "Command Line : ";
		for (int i = 0; i < argLen; i++) {
			cout << args[i] << ' ';
		}
		cout << endl;
		for (int i = 1; i < argLen; i++) {
			process(args[i]);
		}
	}
	
	return 0;
}