#pragma once
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

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

	void Si_menor_cambio(T& a, T& b) {
		if (a < b) {
			T aux = b;
			b = a;
			a = aux;
		}
	}

	void Bubble(vector<T>& lista) {
		int tamano = lista.size();
		if (tamano > 1) {
			for (int j = 0; j < tamano; j++) {
				for (int k = 0; k < tamano - 1; k++) {
					Si_menor_cambio(lista[j], lista[k]);
				}
			}
		}
	}

	void Bin(vector<T>& v) {
		double size = v.size();
		vector < vector <T> > bucket;
		bucket.resize(size);
		T max = *std::max_element(v.begin(), v.end());
		int divider = ceil( (max + 1) / size );
		int b_num;
		for (int i = 0; i < size; i++) {
			b_num = floor(v[i] / divider);
			bucket[b_num].push_back(v[i]);
		}
		for (int i = 0; i < size; i++) {
			Insert(bucket[i]);
		}
		int i = 0;
		for (int j = 0; j < size; j++) {
			for (unsigned int k = 0; k < bucket[j].size(); k++) {
				v[i] = bucket[j][k];
				i++;
			}
		}
	}

	void Cambiazo(T& a, T& b) {
		T aux = b;
		b = a;
		a = aux;
	}

	void Quick(vector<T>& lista) {
		Quick(lista, 0, lista.size() - 1);
	}


	void Quick(vector<T>& lista, int ini, int fin) {

		if (fin - ini > 1) {
			T pivot = lista[ini];
			int i = ini;
			int j = ini + 1;
			while (j < fin) {
				while (j <= fin) {
					if (lista[i] >= pivot && lista[j] < pivot) {
						Cambiazo(lista[i], lista[j]);
						break;
					}
					j++;
				}
				i++;
			}
			Quick(lista, ini, i);
			Quick(lista, i, fin);
		}
		else {
			if (fin - ini == 1) {
				if (lista[ini] >= lista[fin]) {
					Cambiazo(lista[ini], lista[fin]);
				}
			}
		}
	}


};