#include "RPN.hpp"

int main(int argc,char **argv)
{
	if(argc != 2 || !strlen(argv[1]))
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	try
	{
		rpn(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
