//
// Created by Frederik Desmet on 29/04/2022.
//

#include "SpreadsheetCell.h"
#include <stdexcept>

SpreadsheetCell::SpreadsheetCell(double initialValue)
	: _value(initialValue)
{
}
SpreadsheetCell::SpreadsheetCell(std::string_view initialValue)
	: _value(stringToDouble(initialValue))
{
}
void SpreadsheetCell::set(double inValue)
{
	_value = inValue;
}
void SpreadsheetCell::set(std::string_view inValue)
{
	_value = stringToDouble(inValue);
}
std::string SpreadsheetCell::doubleToString(double inValue) const
{
	return std::to_string(inValue);
}
double SpreadsheetCell::stringToDouble(std::string_view inString) const
{
	return std::strtod(inString.data(), nullptr);
}

SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(lhs.getValue() + rhs.getValue());
}
SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& rhs)
{
	set(getValue() + rhs.getValue());
	return *this;
}
SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(lhs.getValue() - rhs.getValue());
}
SpreadsheetCell& SpreadsheetCell::operator-=(const SpreadsheetCell& rhs)
{
	set(getValue() - rhs.getValue());
	return *this;
}
SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(lhs.getValue() * rhs.getValue());
}
SpreadsheetCell& SpreadsheetCell::operator*=(const SpreadsheetCell& rhs)
{
	set(getValue() * rhs.getValue());
	return *this;
}
SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	if (rhs.getValue() == 0)
		throw std::invalid_argument("Divide by zero.");

	return SpreadsheetCell(lhs.getValue() / rhs.getValue());
}
SpreadsheetCell& SpreadsheetCell::operator/=(const SpreadsheetCell& rhs)
{
	if (rhs.getValue() == 0)
		throw std::invalid_argument("Divide by zero.");

	set(getValue() / rhs.getValue());
	return *this;
}
bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() < rhs.getValue());
}
bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() <= rhs.getValue());
}
bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() > rhs.getValue());
}
bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() >= rhs.getValue());
}
bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() == rhs.getValue());
}
bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() < rhs.getValue());
}
