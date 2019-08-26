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
	
	void Combine(std::vector <T>& v, int leftIndex, int middle, int rightIndex) {
		int Len_1 = middle - leftIndex + 1;
		int Len_2 = rightIndex - middle;
		std::vector <T> tempV_1(Len_1);
		std::vector <T> tempV_2(Len_2);
		
		for (int i = 0; i < Len_1; i++) {
			tempV_1[i] = v[leftIndex + i];
		}
		for (int i = 0; i < Len_2; i++) {
			tempV_2[i] = v[middle + i + 1];
		}
		
		int cont_1 = 0;
		int cont_2 = 0;
		int cont_3 = leftIndex;

		while (cont_1 < Len_1 && cont_2 < Len_2) {
			if (tempV_1[cont_1] < tempV_2[cont_2]) {
				v[cont_3] = tempV_1[cont_1];
				cont_1++;
			}
			else {
				v[cont_3] = tempV_2[cont_2];
				cont_2++;
			}
			cont_3++;
		}

		while (cont_1 < Len_1) {
			v[cont_3] = tempV_1[cont_1];
			cont_1++;
			cont_3++;
		}
		while (cont_2 < Len_2) {
			v[cont_3] = tempV_2[cont_2];
			cont_2++;
			cont_3++;
		}

	}

	void Merge(std::vector <T> &v, int leftIndex, int rightIndex) {
		if (leftIndex < rightIndex) {
			int middle = (leftIndex + (rightIndex - 1)) / 2;
			Merge(v, leftIndex, middle);
			Merge(v, middle + 1, rightIndex);

			Combine(v, leftIndex, middle, rightIndex);
		}
	}

};
