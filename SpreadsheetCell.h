//
// Created by Frederik Desmet on 29/04/2022.
//

#pragma once

#include <cstddef>
#include <string>
#include <string_view>

class SpreadsheetCell
{
public:
	SpreadsheetCell() = default;
	explicit SpreadsheetCell(double initialValue);
	explicit SpreadsheetCell(std::string_view initialValue);

	/**
	 * Sets value in cell.
	 * @param inValue value to add inside the cell.
	 */
	void set(double inValue);
	void set(std::string_view inValue);
	/**
	 * Gets the value from the cell.
	 * @return double The value inside the cell.
	 */
	[[nodiscard]] double getValue() const
	{
		_numberOfAccesses++;
		return _value;
	}

	/**
	 * Gets the string inside the cell.
	 * @return string cell.
	 */
	[[nodiscard]] std::string getString() const
	{
		_numberOfAccesses++;
		return doubleToString(_value);
	}

	/**
	 * Converts double to a string
	 * @param inValue double value to convert.
	 * @return string Variant of the double value.
	 */
	[[nodiscard]] std::string doubleToString(double inValue) const;
	/**
	 * Converts string to a double.
	 * @param inString string value to convert.
	 * @return double Variant of the string value.
	 */
	[[nodiscard]] double stringToDouble(std::string_view inString) const;

	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);
private:
	double _value{ 0 };
	mutable size_t _numberOfAccesses{ 0 };
};

SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);

bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
