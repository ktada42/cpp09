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

int ft_atoi(const std::string &str, size_t can_min, size_t can_max)
{
    assert(can_min < can_max && can_max <= INT_MAX);
    unsigned long i = 0;
    size_t val = 0;
    bool valid = false;
    val = 0;
    for (; i < str.size(); i++)
    {
        if (!('0' <= str[i] && str[i] <= '9'))
            return -1;
        val = val * 10 + (str[i] - '0');
        if (val > can_max)
            return -1;
        valid = true;
    }
    if (!valid)
        return -1;
    if (val < can_min)
        return -1;
    return (int)val;
}

std::vector<int> tryArgToVector(int argc, char **argv)
{
	int argLen = argc - 1;
	if (!(1 <= argLen && argLen <= 3000))
	{
		throw std::runtime_error("Error. elements count must 1 ~ 3000");
	}
	std::vector<int> args(argLen);
	for (size_t i = 0; i < (size_t)argLen; i++)
	{
		args[i] = ft_atoi(argv[i + 1], 1, INT_MAX);
		if (args[i] == -1)
		{
			throw std::runtime_error("Error. number must 1 ~ INT_MAX");
		}
	}
	return args;
}

int main(int argc, char **argv)
{
	try
	{
		testMergeInsertSort(tryArgToVector(argc, argv));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	return 0;
}