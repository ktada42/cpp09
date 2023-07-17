#include "Pairable.hpp"




template<>
Pairable<int>::Pairable(int val) : largeVal(val)
{
	vals.push_back(val);
}