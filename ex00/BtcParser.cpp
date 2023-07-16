#include "BtcParser.hpp"


static int countChar(std::string s, char c)
{
	size_t cnt = 0;
	for(size_t i =0; i <s.size(); i++)
	{
		cnt += s[i] == c;
	}
	return cnt;
}

static int countNum(std::string s, int l, int r)
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

static int allOfNum(std::string s, int l, int r)
{
	return countNum(s, l, r) == r - l;
}

static bool splitDateVal(std::string line, std::string sep, std::string &date, std::string &val)
{
	size_t midPos = line.find(sep);
	if (midPos == std::string::npos)
		return false;
	date = line.substr(0, midPos);
	size_t dateStart = midPos + sep.size();
	val = line.substr(dateStart, line.size() - dateStart);
	return true;
}


static ParseResult tryParseDate(std::string s, GregorianDate& result)
{
	const char dash = '-';
	const int dashPos1 = 4;
	const int dashPos2 = 7;
	if (s == "")
	{
		deb("s is empty");
		return badInput;
	}
	if (countChar(s, ' ') > 0) 
	{
		deb("csv "+ s + " space must not exist");
		return badInput;
	}
	else if (countChar(s, dash) != 2) 
	{
		deb("csv "+s + " dash must need 2");
		return badInput;
	}
	else if (s.size() != std::string("2001-01-01").size())
	{
		deb("csv "+s + "wrong length");
		return badInput;
	}
	else if (s[dashPos1] != dash || s[dashPos2] != dash)
	{
		deb("csv "+s + "- position wrong");
		return badInput;
	}
	std::string strYear = s.substr(0, 4);
	std::string strMonth = s.substr(dashPos1 + 1, 2);
	std::string strDay = s.substr(dashPos2 + 1, 2);
	if (!allOfNum(strYear, 0, strYear.size()) 
	|| !allOfNum(strMonth, 0, strMonth.size())
	|| !allOfNum(strDay, 0, strDay.size())
	)
	{
		deb("csv "+s + "date has no numeric error");
		return badInput;
	}
	result = GregorianDate(stoi(strYear), stoi(strMonth), stoi(strDay));
	return success;
}

static ParseResult tryParseVal(std::string s, double& result, double valMax)
{
	const char dot = '.';
	if (s == "")
	{
		deb("s is empty");
		return badInput;
	}
	if (countChar(s, ' ') > 0) {
		deb("csv "+ s + " space must not exist");
		return badInput;
	}
	if (countChar(s, dot) > 1) {
		deb("csv "+s + " dot must 0 or 1");
		return badInput;
	}
	if (s[0] == dot || s.back() == dot)
	{
		deb("csv "+s + " dot must not on head and tail");
		 return badInput;
	}
	size_t startNum = s[0] == '-' ? 1 : 0;
	if (countChar(s, dot))
	{
		size_t dotPos = s.find(dot);
		if(!allOfNum(s, startNum, dotPos - startNum) || !allOfNum(s, dotPos + 1, s.size()))
		{
			deb("csv "+s + "value error");
			return badInput;
		}
	}
	else if(!allOfNum(s, startNum, s.size() - startNum))
	{
		deb("csv "+s + "value error");
		return badInput;
	}
	if (s[0] == '-')
	{
		return notAPositiveNumber;
	}
	if (s.size() > 20) {
		return tooManyDigits;
	}
	double val = stod(s);
	if (val > valMax)
	{
		return tooLargeANumber;
	}
	result = val;
	return success;
}

//スペースは許さない
//2001-01-01,0
ParseResult tryParseBtc(std::string line, std::string sep, GregorianDate& date, double& val, double valMax)
{
	std::string dateStr, valStr;
	if(!splitDateVal(line ,sep, dateStr, valStr))
		return badInput;
	ParseResult parseResult;
	if ((parseResult = tryParseDate(dateStr, date)) != success)
	{
		return parseResult;
	}
	if ((parseResult = tryParseVal(valStr, val, valMax)) != success)
	{
		return parseResult;
	}
	return success;
}

std::string getBtcErrMsg(std::string line, ParseResult result)
{
	if (result == badInput)
	{
		return "Error: bad input => " + line;
	}
	else if (result == notAPositiveNumber)
	{
		return "Error: not a positive number.";
	}
	else if(result == tooLargeANumber)
	{
		return "Error: too large a number.";
	}
	else if (result == tooManyDigits)
	{
		return "Error: too many digits number.";
	}
	else
	{
		throw std::logic_error("result must error");
	}
}
