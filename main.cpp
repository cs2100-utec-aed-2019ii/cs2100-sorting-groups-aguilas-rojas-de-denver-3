#include <iostream>
#include <vector>
#include "Sorting.h"

int main(int, char* []) {
	
	//InsertionSort
	Sorting<int> s;
	std::vector <int> IS = { 46, 25, 78, 105, 2, 34, 65, 102, 58, 97 };
	s.Insert(IS);

	for (auto item : IS)
		std::cout << item << ' ';

	return 0;
}