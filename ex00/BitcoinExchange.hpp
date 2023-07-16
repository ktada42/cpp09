#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP
#include "GregorianDate.hpp"
#include "BtcDataBase.hpp"
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
#include "BtcParser.hpp"

void bitcoinExchange(std::string dataBasePath, std::string inputPath);

#endif // BITCOIN_EXCHANGE_HPP