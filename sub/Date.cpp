#include "Date.hpp"

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	 os << date.year << "/" << date.month << "/" << date.day;
    return os;
}

Date::Date(int year, int month, int day):year(year), month(month), day(day)
{

}

Date::Date():year(-1), month(-1), day(-1)
{
	
}

Date::Date(const Date& date)
{
	(void)date;
}

Date::~Date()
{

}
