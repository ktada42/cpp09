#ifndef LIST_EXTEND_HPP
#define LIST_EXTEND_HPP


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

template<class T>T at(std::list<T>& a, size_t i)
{
	typename std::list<T>::iterator it = a.begin();
	for (size_t j = 0; j < i; j++)
	{
		it++;
	}
	return (*it);
}

#endif // LIST_EXTEND_HPP