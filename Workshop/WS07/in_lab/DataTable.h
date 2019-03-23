// ***********************************************************
// Workshop 7 - STL Algorithms
// DataTable.h
// Matheus Fernando Leitao
// Date: 2019/03/18
// ***********************************************************
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

extern int FW;
extern int ND;

namespace sict {

	template<class T> class DataTable {

		vector<pair<T, T>> dataList;

		T mean() const {
			T total = 0;
			total += accumulate(dataList.begin(), dataList.end(), static_cast<T>(0), [](auto& v1, auto& v2) {
				return v1 + v2.second;
			});
			return (total / dataList.size());

			//
			pair<T, T> elements = sumElements();
			return get<1>(elements) / dataList.size();
		}

		T sigma() const {
			vector<T> yValues;
			for (auto& i : dataList)
				yValues.push_back(get<1>(i));

			T total = 0;
			for_each(yValues.begin(), yValues.end(), [&](T& data) {
				total += pow(data - mean(), 2);
			});
			return sqrt(total / (yValues.size() - 1));

			//
			T total = { 0 };
			pair<vector<T>, vector<T>> v_xy = xy_collection();
			vector<T> y = get<1>(v_xy);

			for_each(y.begin(), y.end(), [&](T& n) {
				total += pow(n - mean(), 2);
			});

			return sqrt(total / (y.size() - 1));
		}

		pair<T, T> sumElements() const {
			T x = 0, y = 0;
			x += accumulate(dataList.begin(), dataList.end(), static_cast<T>(0), [](auto& v1, auto& v2) { 
				return v1 + v2.first; 
			});
			y += accumulate(dataList.begin(), dataList.end(), static_cast<T>(0), [](auto& v1, auto& v2) { 
				return v1 + v2.second; 
			});
			return make_pair(x, y);
		}

		pair<vector<T>, vector<T>> xy_collection() const {
			vector<T> x;
			vector<T> y;
			for (auto& i : dataList) {
				x.push_back(get<0>(i));
				y.push_back(get<1>(i));
			}
			return make_pair(x, y);
		}

		T median() const {
			pair<vector<T>, vector<T>> xy = xy_collection();
			vector<T> y = get<1>(xy);
			sort(y.begin(), y.end());
			return y[y.size() / 2];
		}

		T slope() const {
			size_t n = dataList.size();
			pair<T, T> sums_xy = sumElements();
			pair<vector<T>, vector<T>> v_xy = xy_collection();
			vector<T> x = get<0>(v_xy);
			T sum_x = get<0>(sums_xy);
			T sum_y = get<1>(sums_xy);

			T sum_prod_x_y = { 0 };
			for_each(dataList.begin(), dataList.end(), [&](auto& i) { sum_prod_x_y += i.first * i.second; });

			T sum_squared_x = { 0 };
			for_each(x.begin(), x.end(), [&](auto& i) { sum_squared_x += i * i; });

			T numerator = (n * sum_prod_x_y) - (sum_x * sum_y);
			T denominator = ((n * sum_squared_x) - (sum_x * sum_x));

			return numerator / denominator;
		}

		T intercept() const {
			size_t n = dataList.size();
			pair<T, T> sums_xy = sum_x_y();
			T sum_x = get<0>(sums_xy);
			T sum_y = get<1>(sums_xy);
			return (sum_y - (slope() * sum_x)) / n;
		}

	public:
		DataTable(ifstream& file) {
			if (file.is_open()) {
				T x = 0, y = 0;
				string line = {};
				do {
					file >> x >> y;
					dataList.push_back(make_pair(x, y));
				} while (getline(file, line));
			}
		}

		void displayData(ostream& os) {
			os << "Data Values\n------------" << endl;
			os << setw(FW) << "x" << setw(FW) << "y" << endl;
			for (auto& i : dataList) {
				os << fixed;
				os << setprecision(ND) << setw(FW) << right << get<0>(i);
				os << setprecision(ND) << setw(FW) << get<1>(i) << endl;
			}
		}

		void displayStatistics(ostream& os) {
			os << "\nStatistics\n----------" << endl;
			os << fixed << setprecision(ND) << "  y mean    = " << setw(FW) << mean() << endl;
			os << fixed << setprecision(ND) << "  y sigma   = " << setw(FW) << sigma() << endl;
			os << fixed << setprecision(ND) << "  y median  = " << setw(FW) << median() << endl;
			os << fixed << setprecision(ND) << "  slope     = " << setw(FW) << slope() << endl;
			os << fixed << setprecision(ND) << "  intercept = " << setw(FW) << intercept() << endl;
		}
	};

}
#endif