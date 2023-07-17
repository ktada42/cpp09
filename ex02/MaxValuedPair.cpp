#include "MaxValuedPair.hpp"




template<>
MaxValuedPair<int>::MaxValuedPair(int val) : largeVal(val)
{
	vals.push_back(val);
}