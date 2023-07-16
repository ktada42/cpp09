#ifndef BITCOINEXCHANGE_CPP
#define BITCOINEXCHANGE_CPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <iterator>
#include "GregorianDate.hpp"
#include "BtcParser.hpp"

class BtcDataBase{
	typedef std::map<GregorianDate, double> Map;
	typedef Map::iterator iterator;
	std::map<GregorianDate, double> map;
	BtcDataBase();
public:
	BtcDataBase(std::string filePath);
	BtcDataBase(const BtcDataBase& db);
	~BtcDataBase();
	BtcDataBase& operator=(const BtcDataBase& db);
	bool findVal(const GregorianDate& date, double &res, std::string& resultErrMsg);

	void addData(const GregorianDate& date, double btcVal);
	void print();
};

#endif
