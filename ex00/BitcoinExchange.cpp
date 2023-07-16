#include "BitcoinExchange.hpp"

void bitcoinExchange(std::string dataBasePath, std::string inputPath)
{
	BtcDataBase db(dataBasePath);
	std::string line;
	std::ifstream file(inputPath);
	if (!file.is_open())
	{
		std::cout<<inputPath<<" can not open"<<std::endl;
		return;
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
		if ((result = tryParseBtc(line, " | ", date, val, 1000)) != success)
		{
		//	deb("s is " + line);
			std::cout << getBtcErrMsg(line, result) << std::endl;
		//	deb("\n");
		}
		else 
		{
//			deb("i. "+to_string(date)+" "+std::to_string(val));
			double dbVal = 0;
			std::string errMsg = "";
			if (!db.findVal(date, dbVal, errMsg))
			{
				std::cout << errMsg << std::endl;
				continue;
			}
			std::cout << to_string(date)<<" => "<< val<<" = "<< (val * dbVal) << std::endl;
		}
	}
}