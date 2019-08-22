#pragma once

#include <vector>
template<typename T>
struct Sorting {

	void Insert(std::vector <T> &v) {
		short unsigned n = v.size();
		for (int i = 0; i < n; i++) {
			T temp = v[i];
			int j = i - 1;
			while ( j >= 0 && v[j] > temp ) {
				v[j + 1] = v[j];
				j--;
			}
			v[j + 1] = temp;
		}
	}

};
