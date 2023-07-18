#include "MaxValuedPair.hpp"



namespace mergeInsertByVector{
	template<>
	MaxValuedPair<int>::MaxValuedPair(int val) : largeVal(val)
	{
		vals.push_back(val);
	}
};

namespace mergeInsertByList{
	template<>
	MaxValuedPair<int>::MaxValuedPair(int val) : largeVal(val)
	{
		vals.push_back(val);
	}
};