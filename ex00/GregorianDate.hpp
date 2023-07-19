#ifndef GREGORIAN_DATE_HPP
#define GREGORIAN_DATE_HPP

#include <iostream>
#include <exception>
#include <sstream>
#include <iomanip>

const int gregorianStartYear = 1582;
const int gregorianStartMonth = 10;
const int gregorianStartDay = 15;

//有効でない日付のインスタンスは作れない
class GregorianDate{
	GregorianDate();
	int year;
	int month;
	int day;
	int calcDays(const GregorianDate& date)const;
public:
	GregorianDate(int year, int month, int day);
	GregorianDate(const GregorianDate& date);
	~GregorianDate();
	GregorianDate& operator=(const GregorianDate& date);
	bool operator<(const GregorianDate& date) const;
	bool operator==(const GregorianDate& date) const;
	bool operator>(const GregorianDate& date) const;
	int operator-(const GregorianDate& date) const;
	GregorianDate& operator++();
	GregorianDate& operator--();
	int getYear() const;
	int getMonth() const;
	int getDay() const;
};

std::ostream& operator<<(std::ostream& os, const GregorianDate& date);
bool isValidGregorianDate(int year, int month, int day);
std::string to_string(const GregorianDate& date);
#endif // GREGORIAN_DATE_HPP