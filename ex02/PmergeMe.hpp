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

template<class T>
std::vector<Pairable<T> > getPairedVector(const std::vector<T> &s)
{
	typedef Pairable<T> PT;
	assert(s.size()%2 == 0 || s.size() == 1);
	std::vector<PT> paired;
	for (size_t i = 0; i < s.size(); i += 2)
	{
		paired.push_back(PT(s[i], s[i+1]));
	}
	return paired;
}

template<class T>
void splitPairedVector(std::vector<Pairable<T> >&s, std::vector<T>& a, std::vector<T>&b)
{
	a.clear();
	b.clear();
	for (size_t i = 0; i < s.size(); i++)
	{
		a.push_back(s[i].vals[0]);
		b.push_back(s[i].vals[1]);
	}
}

template<class _V>
void mergeInsertSort(std::vector<Pairable<_V> > &s)
{
	typedef Pairable<_V> T;
	typedef Pairable<T>  PT;
	if (s.size() <= 1)
	{
		return ;
	}
	std::cout << "s :"<<s << std::endl;
 	std::vector<PT> ab = getPairedVector(s);
	std::cout <<"ab :"<< ab << std::endl;
	//mergeInsertSort(ab);
	std::vector<T> a, b;
	splitPairedVector(ab, a, b);
	std::cout << "a : "<<a << std::endl;
	std::cout << "b : "<<b << std::endl;
	//todo aがソートされている前提
	insertMerge(a, b);
	s = a;
	std::cout << "s : "<<s << std::endl;
}

//vector前提
void mergeInsertSort(std::vector<int> &a);
#endif // P_MERGE_ME_HPP