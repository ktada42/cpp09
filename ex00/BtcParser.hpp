#ifndef BTC_PARSER_HPP
#define BTC_PARSER_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <iterator>
#include "GregorianDate.hpp"
#include "debug.hpp"

enum ParseResult{
	success,
	badInput,
	notAPositiveNumber,
	tooLargeANumber,
	tooManyDigits,
};
ParseResult tryParseBtc(std::string line, std::string sep, GregorianDate& date, double& val, double valMax);
std::string getBtcErrMsg(std::string line,  ParseResult result);

#endif // BTC_PARSER_HPP