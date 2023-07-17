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
class Pairable
{
	Pairable();
public:
	int largeVal;
	std::vector<Value> vals;//size is 1 or 2
	Pairable(int val);
	Pairable(const Value &val1, const Value &val2);
	~Pairable();
	Pairable(const Pairable& rhs);
	Pairable& operator=(const Pairable& rhs);
	bool operator<(const Pairable& rhs) const;
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
std::ostream& operator<<(std::ostream& os, const Pairable<T>& pairable)
{
	os << "{ "<<pairable.vals<<" }";
	return os;
}

template<class Value>
Pairable<Value>::Pairable()
{
	largeVal = -1;
}


template<class Value>
Pairable<Value>::Pairable(const Value &val1, const Value &val2)
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
Pairable<Value>::~Pairable()
{

}


template<class Value>
Pairable<Value>& Pairable<Value>::operator=(const Pairable<Value>& rhs)
{
	largeVal = rhs.largeVal;
	vals = rhs.vals;	
	return *this;
}

template<class Value>
Pairable<Value>::Pairable(const Pairable<Value>& rhs)
{
	*this = rhs;
}


	
template<class Value>
bool Pairable<Value>::operator<(const Pairable<Value>& rhs) const
{
	inclimentComparsion();
	return (largeVal < rhs.largeVal);
}

template<class Value>
Pairable<Value>::operator int() const
{
	return largeVal;
}

template<class Value>
size_t Pairable<Value>::size() const
{
	return vals.size();
}

#endif // PAIRABLE_HPP