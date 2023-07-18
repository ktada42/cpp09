
#ifndef STREAM_HPP
#define STREAM_HPP

#include <vector>
#include <list>
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

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (i != 0)os<<" ";
		os<<vec[i];
	}
	return os;
}

#endif // STREAM_HPP