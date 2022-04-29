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