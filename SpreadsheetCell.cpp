//
// Created by Frederik Desmet on 29/04/2022.
//

#include "SpreadsheetCell.h"

SpreadsheetCell::SpreadsheetCell(double initialValue)
	: _value(initialValue)
{
}
SpreadsheetCell::SpreadsheetCell(std::string_view initialValue)
	: _value(stringToDouble(initialValue))
{
}
SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& source)
	: _value(source._value)
{
}
SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
	if (this == &rhs)
		return *this;
	_value = rhs._value;
	return *this;
}
void SpreadsheetCell::setValue(double inValue)
{
	_value = inValue;
}
double SpreadsheetCell::getValue() const
{
	return _value;
}
void SpreadsheetCell::setString(std::string_view inString)
{
	_value = stringToDouble(inString);
}
std::string SpreadsheetCell::getString() const
{
	return doubleToString(_value);
}
std::string SpreadsheetCell::doubleToString(double inValue) const
{
	return std::to_string(inValue);
}
double SpreadsheetCell::stringToDouble(std::string_view inString) const
{
	return std::strtod(inString.data(), nullptr);
}