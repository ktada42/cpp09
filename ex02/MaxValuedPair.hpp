#ifndef PAIRABLE_HPP
#define PAIRABLE_HPP
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
#include "debug.hpp"
#include "ComparsionCnt.hpp"

template<class Value>
class MaxValuedPair
{
	MaxValuedPair();
public:
	int largeVal;
	std::vector<Value> vals;//size is 2
	MaxValuedPair(int val);
	MaxValuedPair(const Value &val1, const Value &val2);
	~MaxValuedPair();
	MaxValuedPair(const MaxValuedPair& rhs);
	MaxValuedPair& operator=(const MaxValuedPair& rhs);
	bool operator<(const MaxValuedPair& rhs) const;
	operator int() const;
	size_t size()const;
};

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (i != 0)os<<", ";
		os<<vec[i];
	}
    return os;
}


template<class T>
std::ostream& operator<<(std::ostream& os, const MaxValuedPair<T>& pairable)
{
	os << "{ "<<pairable.vals<<" }";
	return os;
}

template<class Value>
MaxValuedPair<Value>::MaxValuedPair()
{
	largeVal = -1;
}


template<class Value>
MaxValuedPair<Value>::MaxValuedPair(const Value &val1, const Value &val2)
{
	if (val1 < val2)
	{
		largeVal = (int)val2;
		vals.push_back(val2);
		vals.push_back(val1);
	}
	else
	{
		largeVal = (int)val1;
		vals.push_back(val1);
		vals.push_back(val2);	
	}
}
	
template<class Value>
MaxValuedPair<Value>::~MaxValuedPair()
{

}


template<class Value>
MaxValuedPair<Value>& MaxValuedPair<Value>::operator=(const MaxValuedPair<Value>& rhs)
{
	largeVal = rhs.largeVal;
	vals = rhs.vals;	
	return *this;
}

template<class Value>
MaxValuedPair<Value>::MaxValuedPair(const MaxValuedPair<Value>& rhs)
{
	*this = rhs;
}


	
template<class Value>
bool MaxValuedPair<Value>::operator<(const MaxValuedPair<Value>& rhs) const
{
	inclimentComparsion();
	return (largeVal < rhs.largeVal);
}

template<class Value>
MaxValuedPair<Value>::operator int() const
{
	return largeVal;
}

template<class Value>
size_t MaxValuedPair<Value>::size() const
{
	return vals.size();
}

#endif // PAIRABLE_HPP