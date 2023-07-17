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
	a.push_back(8);
	a.push_back(10);
	a.push_back(14);
	a.push_back(16);
	a.push_back(20);
	a.push_back(26);
	a.push_back(30);
	a.push_back(38);
	std::vector<int> b;
	b.push_back(5);
	b.push_back(1);
	b.push_back(7);
	b.push_back(13);
	b.push_back(19);
	b.push_back(3);
	b.push_back(11);
	b.push_back(9);
	std::vector<Pairable<int> > p;
	for (size_t i = 0; i < a.size(); i++)
	{
		if (rand()%2)
			p.push_back(Pairable<int>(a[i], b[i]));
		else
			p.push_back(Pairable<int>(b[i], a[i]));
	}
	std::cout << p << std::endl;

	std::vector<Pairable<int> >sa;
	for (size_t i = 0; i < a.size(); i++)
	{
		sa.push_back(Pairable<int>(a[i]));
	}
	std::cout <<"sa "<< sa << std::endl;
	
	std::vector<Pairable<int> >sb;
	for (size_t i = 0; i < b.size(); i++)
	{
		sb.push_back(Pairable<int>(b[i]));
	}
	std::cout <<"sb "<< sb << std::endl;

	std::cout << getComparsionCnt() << std::endl;
	insertMerge(sa, sb);
	std::cout <<"merged "<< sa << std::endl;
	
	std::cout << getComparsionCnt() << std::endl;
	// std::vector<Pairable<Pairable<int> > > p2;

	// for (size_t i = 0; i < p.size(); i+=2)
	// {
	// 	p2.push_back(Pairable<Pairable<int> >(p[i], p[i+1]));
	// }
	// std::cout << p2 << std::endl;
	// // insertMerge(a, b);
	// // std::cout << a << std::endl;
	// // test_insert_merge();
	return 0;
}