#include "Date.hpp"

//年月日が存在するかは考慮せず、明らかに1582年10月15日より前か判定する
static bool isPastGregorian(int year, int month, int day)
{
	if (year < gregorianStartYear)return true;
	if (year > gregorianStartYear)return false;
	if (month < gregorianStartMonth) return true;
	if (month > gregorianStartMonth) return false;
	if (day < gregorianStartDay) return true;
	return false;
}

bool isUruYear(int year)
{
	if (year % 400 == 0) return true;
	if (year % 100 == 0) return false;
	if (year % 4 == 0) return true;
	return false;
}

int calcDayNum(int year, int month)
{
	if (month == 2)
	{
		if (isUruYear(year))return 29;
		else return 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		return 30;	
	}
	else
	{
		return 31;
	}
}

bool isValidGregorianDate(int year, int month, int day)
{
	if (isPastGregorian(year, month, day))
		return false;
	if (!(1 <= month && month <= 12))
		return false;
	if (!(1 <= day && day <= calcDayNum(year, month)))
		return false;
	return true;
}

std::ostream& operator<<(std::ostream& os, const GregorianDate& date)
{
	 os << date.getYear() << "/" << date.getMonth() << "/" << date.getDay();
    return os;
}

GregorianDate::GregorianDate(int year, int month, int day)
{
	if (!isValidGregorianDate(year, month, day))
		throw std::runtime_error(std::to_string(year) + "/" + std::to_string(month) + "/" + std::to_string(day) + " is invalid date(must 1582/10/15~)");
	this->year = year;
	this->month = month;
	this->day = day;
}

//呼んではいけない
GregorianDate::GregorianDate():year(-1), month(-1), day(-1)
{
	throw std::logic_error("default constructor must not call");
}

GregorianDate::GregorianDate(const GregorianDate& date)
{
	(*this) = date;
}

GregorianDate::~GregorianDate()
{

}

GregorianDate& GregorianDate::operator=(const GregorianDate& date)
{
	this->year = date.year;
	this->month = date.month;
	this->day = date.day;
	return *this;
}

bool GregorianDate::operator<(const GregorianDate& date)
{
	int r_year = date.getYear();
	int r_month = date.getMonth();
	int r_day = date.getDay();
	if (year < r_year) return true;
	if (year > r_year) return false;
	if (month < r_month) return true;
	if (month > r_month) return false;
	if (day < r_day) return true;
	if (day > r_day) return false;
	//同じ場合
	return false;
}

bool GregorianDate::operator==(const GregorianDate& date)
{
	int r_year = date.getYear();
	int r_month = date.getMonth();
	int r_day = date.getDay();
	return year == r_year && month == r_month && day == r_day;
}

bool GregorianDate::operator>(const GregorianDate& date)
{
	return !(*this < date) && !(*this == date);
}


GregorianDate& GregorianDate::operator++()
{
	if (day < calcDayNum(year, month))
	{
		day++;
		return *this;
	}
	else if (month < 12)
	{
		month++;
		day = 1;
		return *this;
	}
	else
	{
		year++;
		month = 1;
		day = 1;
		return *this;
	}
}

GregorianDate& GregorianDate::operator--()
{
	if (year == gregorianStartYear 
	&& month == gregorianStartMonth
	&& day  == gregorianStartDay)
	{
		throw std::runtime_error("cant decliment " + std::to_string(gregorianStartYear)+"/" + std::to_string(gregorianStartMonth)+ "/" + std::to_string(gregorianStartDay));
		return *this;
	}
	else if (day > 1)
	{
		day--;
		return *this;
	}
	else if (month > 1)
	{
		month--;
		day = calcDayNum(year, month);
		return *this;
	}
	else
	{
		year--;
		month = 12;
		day = calcDayNum(year, month);
		return *this;
	}
}
	

//1/1/1をグレゴリオ暦とみなした時の経過日数を返す
int GregorianDate::calcDays(const GregorianDate& date)
{
	int y = date.getYear();
	int m = date.getMonth();
	int d = date.getDay();
	int yearSum = 365 * (y - 1);
	int uruCnt = (y-1) / 4 - (y-1) / 100 + (y-1) / 400;
	int monthSum = 0;
	for(int nowMonth = 1; nowMonth < m; nowMonth++)
	{
		monthSum += calcDayNum(y, nowMonth);
	}
	int daySum = d - 1;
	return yearSum + uruCnt  + monthSum + daySum;
}

int GregorianDate::operator-(const GregorianDate& date)
{
	return  calcDays(*this) - calcDays(date);
}

int GregorianDate::getYear() const
{
	return year;
}

int GregorianDate::getMonth() const
{
	return month;
}

int GregorianDate::getDay() const
{
	return day;
}

/*
int calcDec(GregorianDate a, GregorianDate b)
{
	int sign;
	if (a > b)
	{
		sign = 1;
	}
	else if (a < b)
	{
		sign = -1;
		std::swap(a, b);
	}
	for(int date = 0; ; date++)
	{
		if (a == b)
		{
			return date * sign;
		}
		--a;
	}
	return (1<<30);
}

int getRnd(int l, int r)
{
	assert(l < r);
	return l + (rand()%(r-l));
}

GregorianDate getRndDate()
{
	int year = -1, month = -1, day = -1;
	do{
		year = getRnd(1582, 3010);
		month =getRnd(1, 13);
		day = getRnd(1, 32);
	}while(!isValidGregorianDate(year, month, day));
	return GregorianDate(year, month, day);
}

void test_date()
{
	int test_loop = 500;
	while (test_loop--){
		GregorianDate a = getRndDate();
		GregorianDate b = getRndDate();
		int r1 = (b - a);
		int r2 = calcDec(b, a);
		if (r1 != r2)
		{
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			std::cout << "r1 "<<r1 << std::endl;
			std::cout << "r2 "<<r2 << std::endl;
			exit(0);
		}
	}
}
*/