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

//refactor 挿入する操作を切り出す
template<class Value>
void insertMergeStraggle(std::vector<Value>& a, Value& straggle)
{
	typename std::vector<Value>::iterator it = std::lower_bound(a.begin(), a.end(), straggle);
	a.insert(it, straggle);
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

// recursive template instantiation exceeded maximum depth of 1024 errorを避けるためのdummy
template<class _V>
void mergeInsertSort(std::vector<Pairable<Pairable<Pairable<Pairable<Pairable<Pairable<Pairable<Pairable<Pairable<Pairable<Pairable<Pairable<Pairable<Pairable<Pairable<Pairable<_V> > > > > > > > > > > > > > > > > &s, int dep)
{
	(void)s;
	(void)dep;
}


//todo 2冪前提になっている
//todo 5000より大きいものを弾く
template<class T>
void mergeInsertSort(std::vector<T > &s, int dep)
{
	typedef Pairable<T>  PT;
	if (s.size() <= 1)
	{
		return ;
	}
	std::string tab(dep * 4, ' ');
	std::cout <<tab<< "prv :"<<s << std::endl;
	bool hasStraggle = false;
	std::vector<T> straggle;
	if (s.size() % 2 == 1)
	{
		hasStraggle = true;
		straggle.push_back(s.back());
		s.pop_back();
	}
 	std::vector<PT> ab = getPairedVector(s);
	// std::cout <<"ab :"<< ab << std::endl;
	mergeInsertSort(ab, dep + 1);
	std::vector<T> a, b;
	splitPairedVector(ab, a, b);
	// std::cout << "a : "<<a << std::endl;
	// std::cout << "b : "<<b << std::endl;
	insertMerge(a, b);
	if (hasStraggle)
	{
		insertMergeStraggle(a, straggle[0]);
	}
	s = a;
	std::cout <<tab<< "aft :"<<s << std::endl;

	// std::cout << "s : "<<s << std::endl;
}

//vector前提
void mergeInsertSort(std::vector<int> &a);


template<class T>void f(std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<T> > > > > > > > > > > > > a)
{
	(void)a;
		std::cout << "ok" << std::endl;
}
template<class T>void f(std::vector<T> a)
{
	(void)a;
	f(std::vector<std::vector<T> >());
}
#endif // P_MERGE_ME_HPP