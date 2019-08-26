#include <iostream>
#include <vector>
#include "Sorting.h"

template <typename T>
void Print(std::vector <T>& v) {
	for (auto item : v)
		std::cout << item << ' ';
	std::cout << std::endl;
}

int main(int, char* []) {

	Sorting<int> s;

	//InsertionSort
	std::vector <int> IS = { 46, 25, 78, 105, 2, 34, 65, 102, 58, 97 };
	s.Insert(IS);
	Print(IS);

	//SelectionSort
	std::vector <int> SS = { 46, 25, 78, 105, 2, 34, 65, 102, 58, 97 };
	s.Selection(SS);
	Print(SS);

	//MergeSort
	std::vector <int> MS = { 46, 25, 78, 105, 2, 34, 65, 102, 58, 97 };
	s.Merge(MS, 0, MS.size() - 1);
	Print(MS);


	return 0;
}