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

int main()
{
	std::vector<int> a;
	for (size_t i = 0; i < 3000; i++)
	{
		a.push_back(rand());
	}
	testMergeInsertSort(a);
	
	return 0;
}