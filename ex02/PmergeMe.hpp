#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP
#include "MaxValuedPair.hpp"
#include "ListExtend.hpp"
#include <ctime>
#include "Stream.hpp"

namespace mergeInsertByVector{
	std::vector<size_t> getJakobNumbers(size_t limit);


	//簡単のためにlarger.size() == smaller.size()とする
	template<class Value>
	void insertMerge(std::vector<Value>& larger, std::vector<Value>& smaller, std::vector<Value>& straggle)
	{
		assert(larger.size() == smaller.size());
		if (smaller.size() == 0) return;
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
		if (straggle.size()!= 0)
		{
			assert(straggle.size() == 1);
			typename std::vector<Value>::iterator it = std::lower_bound(larger.begin(), larger.end(), straggle[0]);
			larger.insert(it, straggle[0]);
		}
	}

	template<class T>
	std::vector<MaxValuedPair<T> > getPairedVector(const std::vector<T> &s)
	{
		typedef MaxValuedPair<T> PT;
		assert(s.size()%2 == 0 || s.size() == 1);
		std::vector<PT> paired;
		for (size_t i = 0; i < s.size(); i += 2)
		{
			paired.push_back(PT(s[i], s[i+1]));
		}
		return paired;
	}

	template<class T>
	void splitPairedVector(std::vector<MaxValuedPair<T> >&s, std::vector<T>& a, std::vector<T>&b)
	{
		a.clear();
		b.clear();
		for (size_t i = 0; i < s.size(); i++)
		{
			a.push_back(s[i].vals[0]);
			b.push_back(s[i].vals[1]);
		}
	}

	template<class T>
	std::vector<T> pollStraggle(std::vector<T> &s)
	{
		if (s.size() % 2 == 1)
		{
			T val = s.back();
			s.pop_back();
			std::vector<T> res;
			res.push_back(val);
			return res;
		}
		return std::vector<T>();
	}

	// recursive template instantiation exceeded maximum depth of 1024 errorを避けるためのdummy
	template<class _V>
	void mergeInsertSort(std::vector<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<_V> > > > > > > > > > > > > > > > &s, int dep)
	{
		(void)s;
		(void)dep;
	}


	//todo 2冪前提になっている
	//todo 5000より大きいものを弾く
	template<class T>
	void mergeInsertSort(std::vector<T> &s, int dep)
	{
		if (s.size() <= 1)return ;
		typedef MaxValuedPair<T>  PT;
		std::vector<T> straggle = pollStraggle(s);
		std::vector<PT> ab = getPairedVector(s);
		mergeInsertSort(ab, dep + 1);
		std::vector<T> a, b;
		splitPairedVector(ab, a, b);
		insertMerge(a, b, straggle);
		s = a;
	}

	//vector前提
	void mergeInsertSort(std::vector<int> &a);
};


namespace mergeInsertByList{
	std::list<size_t> getJakobNumbers(size_t limit);


	template<class Value>
	typename std::list<Value>::iterator getLowerIt(typename std::list<Value>::iterator begin, typename std::list<Value>::iterator end, Value v)
	{
		typename std::list<Value>::iterator it = begin;
		while(it != end && (*it) < v)
		{
			it++;
		}
		return it;
	}

	//簡単のためにlarger.size() == smaller.size()とする
	template<class Value>
	void insertMerge(std::list<Value>& larger, std::list<Value>& smaller, std::list<Value>& straggle)
	{
		assert(larger.size() == smaller.size());
		if (smaller.size() == 0) return;
		std::list<size_t> jakobs = getJakobNumbers(smaller.size());
		larger.insert(larger.begin(), at(smaller, 0));
		size_t prevEndIdx = 0;
		size_t nowRange = 3;
		//jakobs[3] == 3
		for (size_t i = 3; i < jakobs.size(); i++)
		{
			size_t startIdx = std::min(smaller.size(), at(jakobs, i)) - 1;
			for (size_t j = startIdx; j > prevEndIdx; j--)
			{
				Value small = at(smaller, j);//todo at
				typename std::list<Value>::iterator it = getLowerIt(larger.begin(),larger.end(), small);
				 //std::lower_bound(larger.begin(), larger.begin() + std::min(nowRange, larger.size()), small);
				larger.insert(it, small);
			}
			prevEndIdx = startIdx;
			nowRange = nowRange * 2 + 1;
		}
		if (straggle.size()!= 0)
		{
			assert(straggle.size() == 1);
			typename std::list<Value>::iterator it = std::lower_bound(larger.begin(), larger.end(), at(straggle, 0));
			larger.insert(it, at(straggle, 0));
		}
	}

	template<class T>
	std::list<MaxValuedPair<T> > getPairedlist(const std::list<T> &s)
	{
		typedef MaxValuedPair<T> PT;
		assert(s.size()%2 == 0 || s.size() == 1);
		std::list<PT> paired;
		typename std::list<T>::const_iterator it = s.begin();
		(void)it;
		for (size_t i = 0; i < s.size(); i += 2)
		{
			T v1 = *(it++);
			T v2 = *(it++);
			paired.push_back(PT(v1, v2));
		}
		return paired;
	}

	template<class T>
	void splitPairedList(std::list<MaxValuedPair<T> >&s, std::list<T>& a, std::list<T>&b)
	{
		a.clear();
		b.clear();
		typename std::list<MaxValuedPair<T> >::iterator sIt = s.begin();
		for (size_t i = 0; i < s.size(); i++)
		{
			a.push_back(at(sIt->vals, 0));
			b.push_back(at(sIt->vals, 1));
			sIt++;
		}
	}

	template<class T>
	std::list<T> pollStraggle(std::list<T> &s)
	{
		if (s.size() % 2 == 1)
		{
			T val = s.back();
			s.pop_back();
			std::list<T> res;
			res.push_back(val);
			return res;
		}
		return std::list<T>();
	}

	// recursive template instantiation exceeded maximum depth of 1024 errorを避けるためのdummy
	template<class _V>
	void mergeInsertSort(std::list<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<MaxValuedPair<_V> > > > > > > > > > > > > > > > &s, int dep)
	{
		(void)s;
		(void)dep;
	}


	//todo 2冪前提になっている
	//todo 5000より大きいものを弾く
	template<class T>
	void mergeInsertSort(std::list<T> &s, int dep)
	{
		if (s.size() <= 1)return ;
		typedef MaxValuedPair<T>  PT;
		std::list<T> straggle = pollStraggle(s);
		std::list<PT> ab = getPairedlist(s);
		mergeInsertSort(ab, dep + 1);
		std::list<T> a, b;
		splitPairedList(ab, a, b);
		insertMerge(a, b, straggle);
		s = a;
	}

	//list前提
	void mergeInsertSort(std::list<int> &a);
};

template<class T>
void testMergeInsertSortByVector(std::vector<T>& a, double &timeUs, size_t &comparsionsNum)
{
	comparsionCnt = 0;
	clock_t start = clock();
	mergeInsertByVector::mergeInsertSort(a);
	clock_t end = clock();
	comparsionsNum = comparsionCnt;
	comparsionCnt = 0;
	timeUs = (double)(end - start) / ((double)CLOCKS_PER_SEC / 1000);
}

template<class T>
void testMergeInsertSortByList(std::list<T>& a, double &timeUs, size_t &comparsionsNum)
{
	comparsionCnt = 0;
	clock_t start = clock();
	mergeInsertByList::mergeInsertSort(a);
	clock_t end = clock();
	comparsionsNum = comparsionCnt;
	comparsionCnt = 0;
	timeUs = (double)(end - start) / ((double)CLOCKS_PER_SEC / 1000);
}

bool compare(int a, int b);


template<class T>
void testStdSort(std::vector<T>& a, double &timeUs, size_t &comparsionsNum)
{
	comparsionCnt = 0;
	clock_t start = clock();

	std::sort(a.begin(), a.end(), compare);
	clock_t end = clock();
	comparsionsNum = comparsionCnt;
	comparsionCnt = 0;
	timeUs = (double)(end - start) / ((double)CLOCKS_PER_SEC / 1000);
}

void testMergeInsertSort(const std::vector<int> &a);

#endif // P_MERGE_ME_HPP
