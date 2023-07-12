#include "Date.hpp"
#include <vector>

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <deque>
#include <stdlib.h>
#include <iterator>

// void splitByConnmaAndInsertMap(std::string s_line,Map &map)
// {
// 	std::string s_year;
// 	std::string s_value;
// 	s_year = (std::string)strtok(const_cast<char*>(s_line.c_str()), ",");
// 	s_value = (std::string)strtok(NULL, ",");
// 	map.data.insert(std::make_pair(s_year,s_value));
// }

//a
int countChar(std::string s, char c)
{
	size_t cnt = 0;
	for(size_t i =0; i <s.size(); i++)
	{
		cnt += s[i] == c;
	}
	return cnt;
}

int countNum(std::string s, int l, int r)
{
	size_t cnt = 0;
	assert(l <= r);
	assert((size_t)r<=s.size());
	for(int i =l; i < r; i++)
	{
		cnt += '0' <= s[i] && s[i] <= '9';
	}
	return cnt;
}

int allOfNum(std::string s, int l, int r)
{
	return countNum(s, l, r) == r - l;
}

//スペースは許さない
//2001-01-01,0
bool tryParseLine(std::string line, std::map<GregorianDate, double> &map)
{
	const char dash = '-';
	const char comma = ',';
	const char dot = ',';
	const int dashPos1 = 4;
	const int dashPos2 = 7;
	const int commaPos = 10;
	if (countChar(line, ' ') > 0) {
		std::runtime_error("csv "+ line + " space must not exist");
		return false;
	}
	if (countChar(line, dash) != 2) {
		std::runtime_error("csv "+line + " dash must need 2");
		return false;
	}
	if (countChar(line, comma) != 1) {
		std::runtime_error("csv "+line + " comma must need 1");
		return false;
	}
	if (countChar(line, dot) > 1) {
		std::runtime_error("csv "+line + " dot must 0 or 1");
		return false;
	}
	if (line[commaPos + 1] == dot || line.back() == dot)
	{
		std::runtime_error("csv "+line + " dot must not on head and tail");
		 return false;
	}
	if (line.size() < std::string("2001-01-01,0").size()){
		std::runtime_error("csv "+line + "too few length");
		 return false;
	}
	if (line.size() > 1000) {
		std::runtime_error("csv "+line + "too long length");
		return false;
	}
	if (line[dashPos1] != dash || line[dashPos2] != dash)
	{
		std::runtime_error("csv "+line + "- position wrong");
		return false;
	}
	if (line[commaPos] != comma) {
		std::runtime_error("csv "+line + "comma position wrong");
		return false;
	}
	std::string strYear = line.substr(0, 4);
	std::string strMonth = line.substr(dashPos1 + 1, 2);
	std::string strDay = line.substr(dashPos2 + 1, 2);
	std::string strVal = line.substr(commaPos + 1, (line.size() - (commaPos + 1)));
	if (!allOfNum(strYear, 0, strYear.size()) 
	|| !allOfNum(strMonth, 0, strMonth.size())
	|| !allOfNum(strDay, 0, strDay.size())
	)
	{
		std::runtime_error("csv "+line + "date has no numeric error");
		return false;
	}
	int year = stoi(strYear);
	int month = stoi(strMonth);
	int day = stoi(strDay);
	if (countChar(strVal, dot))
	{
		int dotPos = strVal.find(dot);
		if(!allOfNum(strVal, 0, dotPos) || !allOfNum(strVal, dotPos + 1, strVal.size()))
		{
			std::runtime_error("csv "+line + "value error");
			return false;
		}
	}
	else if(!allOfNum(strVal, 0, strVal.size()))
	{
		std::runtime_error("csv "+line + "value error");
		return false;
	}
	double val = stod(strVal);
	map[GregorianDate(year, month, day)] = val;
	return true;
}

void readCsv()
{
	std::map<GregorianDate, double> map;
	std::string line;
	std::ifstream file("./a.csv");
	std::getline(file, line);
	throw std::runtime_error("csv top line must  date,exchange_rate");
	return;
	if (line != "date,exchange_rate")
	{
		throw std::runtime_error("csv top line must  date,exchange_rate");
		return;
	}
	while (std::getline(file, line))
	{
		if (line == "")
		{
			throw std::runtime_error("csv file must not have empty line");
			return;
		}
		if (!tryParseLine(line, map))
		{
			file.close();
			throw std::runtime_error("csv error");
			return;
		}
	}
	file.close();
}

int main(int argc, char **argv)
{
	readCsv();
	return 0;
}