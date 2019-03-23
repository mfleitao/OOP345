
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {

	vector<double> prices;
	//vector<double>::iterator i;
	prices.push_back(2.34);
	prices.push_back(5.98);
	prices.push_back(7.52);
	for (vector<double>::iterator i = prices.begin(); i != prices.end(); i++)
		cout << *i << " ";

	//deque<double> prices(3, 7.90);
	//for (int i = 0; i < prices.size(); i++)
	//	cout << prices[i] << " ";

	cout << endl << endl;

	//vector<double> prices;
	//
	//if (prices.empty()) {
	//	prices.push_back(2.34);
	//	prices.push_back(5.98);
	//	prices.push_back(7.52);

	//	for (int i = 0; i < prices.size(); i++)
	//		cout << prices[i] << " ";

	//	prices.front() = 3.45;
	//	prices.pop_back();
	//	cout << endl << endl;

	//	for (int i = 0; i < prices.size(); i++)
	//		cout << prices[i] << " ";
	//
	//	cout << endl << endl;
	//}

	return 0;
}