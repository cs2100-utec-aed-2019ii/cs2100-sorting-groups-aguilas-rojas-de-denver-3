#pragma once
#include <vector>

template <typename T>
struct Sorting {

	void Insert(std::vector <T> &v) {
		int n = v.size();
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

	void Selection(std::vector <T> &v) {
		int cont = 0;
		for (int i = 0; i < v.size(); i++) {
			T pivot = v[cont];
			int index = cont;
			for (int j = cont; j < v.size(); j++) {
				if (pivot > v[j]) {
					pivot = v[j];
					index = j;
				}
			}
			T temp = v[index];
			v[index] = v[cont];
			v[cont] = temp;
			cont++;
		}
	}

};