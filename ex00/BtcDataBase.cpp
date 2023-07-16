#include "BtcDataBase.hpp"

void BtcDataBase::print()
{
	for(iterator it = map.begin(); it != map.end(); it++)
	{
		std::cout << (it->first) << " : "<<std::fixed<< std::setprecision(4)<<it->second<<" "<<std::endl;
	}
}

//todo catch
void BtcDataBase::addData(const GregorianDate& date, double btcVal)
{
	if (map.find(date) != map.end())
	{
		std::stringstream ss;
		ss<<date;
		throw std::runtime_error("duplicate date "+ss.str());
	}
	map[date] = btcVal;
}

BtcDataBase::~BtcDataBase()
{

}

BtcDataBase& BtcDataBase::operator=(const BtcDataBase& db)
{
	this->map = db.map;
	return (*this);
}

BtcDataBase::BtcDataBase(const BtcDataBase& db)
{
	(*this) = db;
}

BtcDataBase::BtcDataBase()
{

}

BtcDataBase::BtcDataBase(std::string filePath)
{
	std::string line;
	std::ifstream file(filePath);
	if (!file.is_open())
	{
		throw std::runtime_error("Error dataBase "+ filePath+ "can not open.");
	}
	bool first = true;
	while (std::getline(file, line))
	{
		if (line == "")continue;
		if (first)
		{
			first = false;
			continue;
		}
		GregorianDate date(2021,1,1);
		double val = 0;
		ParseResult result;
		if ((result = tryParseBtc(line, ",", date, val, 100000)) != success)
		{
			deb("s is " + line);
			throw std::runtime_error(getBtcErrMsg(line, result));
		}
		addData(date, val);
	}
}

bool BtcDataBase::findVal(const GregorianDate& date, double &res, std::string& resultErrMsg)
{
	if (map.empty())
	{
		resultErrMsg = "Error: dataBase is empty";
		return false;
	}
	iterator nextIt = map.upper_bound(date);
	if (nextIt == map.begin())
	{
		resultErrMsg = "Error: prev "+to_string(date)+ " there are no data on db";
		return false;
	}
	iterator targetIt = nextIt;
	--targetIt;
	//deb("q.date "+ to_string(date)+" a.date "+to_string(targetIt->first));
	res = targetIt->second;
	return true;
}

