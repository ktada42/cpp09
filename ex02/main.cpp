#include <vector>
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <exception>
#include <iterator>
#include <algorithm>
#include "PmergeMe.hpp"
#include "Pairable.hpp"
#include "ComparsionCnt.hpp"



// void test_insert_merge()
// {
// 	for (size_t test_i = 0; test_i < 1000; test_i++)
// 	{
// 		int n = (rand()%3000) + 1;
// 		std::vector<int> a;
// 		std::vector<int> b;
// 		for (size_t i = 0; i < (size_t)n; i++)
// 		{	
// 			a.push_back((rand() % 10000) + 1);
// 		}
// 		std::sort(a.begin(), a.end());
// 		std::vector<int >c = a;
// 		for (size_t i = 0; i < (size_t)n; i++)
// 		{
// 			b.push_back(rand()%a[i]);
// 			c.push_back(b[i]);
// 		}
// 		std::sort(c.begin(), c.end());
// 		insertMerge(a, b);
// 		if (a != c)
// 		{
// 			std::cout << "error" << std::endl;
// 			exit(0);
// 		}
// 	}
// 	std::cout << "ok" << std::endl;
// }

int main()
{
	std::vector<int> a;

	a.push_back(2);
	a.push_back(55);
	a.push_back(18);
	
	a.push_back(11);
	a.push_back(3);
	a.push_back(14);
	a.push_back(25);
	a.push_back(32);
	a.push_back(19);
	a.push_back(9);
	
	// a.push_back(59);
	// /*b*/a.push_back(7);
	// a.push_back(10);
	// /*b*/a.push_back(39);
	// a.push_back(44);
	mergeInsertSort(a);
	std::cout << a << std::endl;
	return 0;
}