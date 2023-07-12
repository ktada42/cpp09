#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>

//有効でない日付のインスタンスは作れない
class Date{
	Date();
public:
	int year;
	int month;
	int day;
	Date(int year, int month, int day);
	Date(const Date& date);
	~Date();
	//copy代入

};

std::ostream& operator<<(std::ostream& os, const Date& date);

#endif // DATE_HPP