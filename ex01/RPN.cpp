#include "RPN.hpp"

static bool is_space(char c)
{
	return c == ' ';
}

static bool is_digit(char c)
{
	return '0' <= c && c <= '9';
}

static bool is_plus(char c)
{
	return (c == '+');
}

static bool is_minus(char c)
{
	return (c == '-');
}

static bool is_mul(char c)
{
	return (c == '*');
}

static bool is_div(char c)
{
	return (c == '/');
}

static bool is_operator(char c)
{
	return is_plus(c) || is_minus(c) || is_mul(c) || is_div(c);
}

static double calc(double a, double b, char op)
{
	if (is_plus(op))
	{
		return a + b;
	}
	else if (is_minus(op))
	{
		return a - b;
	}
	else if (is_mul(op))
	{
		return a * b;
	}
	else if (is_div(op))
	{
		if (b == 0)
		{
			throw std::runtime_error("Error can not div by 0");
		}
		return a / b;
	}
	else
	{
		throw std::logic_error(std::to_string(op)+" is not a operator");
	}
}

void do_operation(std::deque<double>& dq, char op, size_t cur)
{
	if  (dq.size() < 2)
	{
		throw std::runtime_error("Error of too few number. at index "+std::to_string(cur)+" operation.");
	}
	double rhs = dq.back();
	dq.pop_back();
	double lhs = dq.back();
	dq.pop_back();
	double res = calc(lhs, rhs, op);
	//std::cout << lhs<<" "<<s[i]<< " "<<rhs<< " "<<res<< std::endl;
	dq.push_back(res);
}

void rpn(std::string s)
{
	std::deque<double> dq;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (is_space(s[i]))
		{
			continue;
		}
		else if (is_operator(s[i]))
		{
			do_operation(dq, s[i], i);
		}
		else if (is_digit(s[i]))
		{
			dq.push_back(s[i] - '0');
		}
		else
		{
			throw std::runtime_error("Error "+ std::string(1, s[i])+" is invalid character.");
		}
	}
	if (dq.size() != 1)
	{
		throw std::runtime_error("Error too few operator.");
	}
	std::cout<< dq.back() << std::endl;
}
