#pragma once
#include <exception>

class InvalidIndex : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Invalid Index!";
	}
};