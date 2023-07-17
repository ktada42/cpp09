#include "PmergeMe.hpp"

std::vector<size_t> getJakobNumbers(size_t limit)
{
	std::vector<size_t> jakobs(2);
	jakobs[0] = 0;
	jakobs[1] = 1;
	while(jakobs.back() < limit)
	{
		size_t v = jakobs[jakobs.size() - 2] * 2 + jakobs.back();
		jakobs.push_back(v); 
	}
	return jakobs;
}


//vector前提
void mergeInsertSort(std::vector<int> &a)
{
	std::vector<Pairable<int> > pa;
	for (size_t i = 0; i < a.size(); i++)
	{
		pa.push_back(Pairable<int>(a[i]));
	}
	mergeInsertSort(pa);
	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] = pa[i].largeVal;
	}
}
