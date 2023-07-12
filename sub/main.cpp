#include "Date.hpp"
#include <vector>




void test_date()
{
	Date a(2023, 5, 7);
	std::cout << a << std::endl;	
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	std::vector<Date>a;
	test_date();
	//Date d;
	return 0;
}