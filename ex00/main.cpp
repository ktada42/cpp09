#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (argc != 2)
	{
		std::cout << "arg must 1" << std::endl;
		return 0;
	}
	try
	{
		//todo data.csvないとき
		//input.txtない時
		bitcoinExchange("./data.csv", argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}