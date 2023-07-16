#include "debug.hpp"

void deb(std::string s)
{
	if(DEBUG)
	{
		std::cout<<s<<std::endl;
	}
}
