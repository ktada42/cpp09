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
#include "MaxValuedPair.hpp"
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
	for (size_t i = 0; i < 3000; i++)
	{
		a.push_back(rand());
	}
	std::vector<int> b = a;

	comparsionCnt = 0;
	mergeInsertSort(a);
	// std::cout << a << std::endl;
	std::cout << "cnt : "<<comparsionCnt<< std::endl;
	comparsionCnt = 0;
	std::vector<MaxValuedPair<int> > pb;
	for (size_t i = 0; i < b.size(); i++)
	{
		pb.push_back(MaxValuedPair<int>(b[i], -1));
	}
	std::sort(pb.begin(), pb.end());
	std::cout << "cnt : "<<comparsionCnt<< std::endl;

	// std::sort();
	return 0;
}