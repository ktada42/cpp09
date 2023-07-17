#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP
#include "Pairable.hpp"

std::vector<size_t> getJakobNumbers(size_t limit);


//簡単のためにlarger.size() == smaller.size()とする
template<class Value>
void insertMerge(std::vector<Value>& larger, std::vector<Value>& smaller)
{
	assert(larger.size() == smaller.size());
	if (smaller.size() == 0)
	{
		return;
	}
	if (DEBUG)
	{
		for (size_t i = 0; i < larger.size() - 1; i++)
		{
			if (larger[i] > larger[i+1])
			{
				throw std::runtime_error("larger > ");
			}
		}
	}
	std::vector<size_t> jakobs = getJakobNumbers(smaller.size());
	larger.insert(larger.begin(), smaller[0]);
	size_t prevEndIdx = 0;
	size_t nowRange = 3;
	//jakobs[3] == 3
	for (size_t i = 3; i < jakobs.size(); i++)
	{
		size_t startIdx = std::min(smaller.size(), jakobs[i]) - 1;
		for (size_t j = startIdx; j > prevEndIdx; j--)
		{
			Value small = smaller[j];
			typename std::vector<Value>::iterator it = std::lower_bound(larger.begin(), larger.begin() + std::min(nowRange, larger.size()), small);
			larger.insert(it, small);
		}
		prevEndIdx = startIdx;
		nowRange = nowRange * 2 + 1;
	}
}


#endif // P_MERGE_ME_HPP