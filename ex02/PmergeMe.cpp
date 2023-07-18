#include "PmergeMe.hpp"

namespace mergeInsertByVector{
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
		comparsionCnt = 0;
		std::vector<mergeInsertByVector::MaxValuedPair<int> > pa;
		for (size_t i = 0; i < a.size(); i++)
		{
			pa.push_back(mergeInsertByVector::MaxValuedPair<int>(a[i], -1));
		}
		mergeInsertByVector::mergeInsertSort(pa, 0);
		for (size_t i = 0; i < a.size(); i++)
		{
			a[i] = pa[i].largeVal;
		}
	}
};


namespace mergeInsertByList{
	std::list<size_t> getJakobNumbers(size_t limit)
	{
		std::list<size_t> jakobs;
		jakobs.push_back(0);
		jakobs.push_back(1);
		size_t p1 = 0;
		size_t p2 = 1;
		while(jakobs.back() < limit)
		{
			size_t v = p1 * 2 + p2;
			jakobs.push_back(v); 
			p1 = p2;
			p2 = v;
		}
		return jakobs;
	}


	//list前提
	void mergeInsertSort(std::list<int> &a)
	{
		comparsionCnt = 0;
		std::list<mergeInsertByList::MaxValuedPair<int> > pa;
		for (size_t i = 0; i < a.size(); i++)
		{
			pa.push_back(mergeInsertByList::MaxValuedPair<int>(at(a, i), -1));
		}
		mergeInsertByList::mergeInsertSort(pa, 0);
		a.clear();
		size_t len = pa.size();
		for (size_t i = 0; i < len; i++)
		{
			a.push_back(pa.front().largeVal);
			pa.pop_front();
		}
	}
};

static void checkSame(std::vector<int> &a, std::list<int> &b)
{
	std::vector<int> vecB(b.begin(), b.end());
	assert(a == vecB);
}

bool compare(int a, int b)
{
	inclimentComparsion();
	return a < b;
}

void testMergeInsertSort(const std::vector<int> &a)
{
	std::cout << "Before:  " << a << std::endl;
	std::vector<int> vec = a;
	std::vector<int> vec2 = a;
	std::list<int> list(a.begin(), a.end());
	double vecTimeUs=0, listTimeUs=0, stdSortByVecTimeUs =0;
	size_t vecComparsion=0, listComparsion = 0, stdSortComparsion=0;
	testMergeInsertSortByVector(vec, vecTimeUs, vecComparsion);
	testMergeInsertSortByList(list, listTimeUs, listComparsion);
	testStdSort(vec2, stdSortByVecTimeUs, stdSortComparsion);
	std::cout << "After:   " << vec << std::endl;
	std::cout << "Time to process a range of "<<a.size() <<" elements sort by merge-insert sort with std::vector : "<< vecTimeUs<< " us" << std::endl;
	std::cout << "Time to process a range of "<<a.size() <<" elements sort by merge-insert sort with std::list   : "<< listTimeUs<< " us" << std::endl;
	std::cout << "Time to process a range of "<<a.size() <<" elements sort by std::sort with std::vector         : "<< stdSortByVecTimeUs<< " us" << std::endl;
	std::cout << "Number of comparsions with merge-insert sort with std::vector : " << vecComparsion << std::endl;
	std::cout << "Number of comparsions with merge-insert sort with std::list   : " << listComparsion << std::endl;
	std::cout << "Number of comparsions with std::sort with vector              : " <<stdSortComparsion <<std::endl;
	checkSame(vec, list);
	checkSame(vec2, list);
}

