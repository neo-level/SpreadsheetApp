//
// Created by Frederik Desmet on 29/04/2022.
//

#pragma once
#include <string>
#include <string_view>

class SpreadsheetCell
{
public:
	SpreadsheetCell() = default;
	explicit SpreadsheetCell(double initialValue);
	explicit SpreadsheetCell(std::string_view initialValue);
	SpreadsheetCell(const SpreadsheetCell& source);

	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);

	/**
	 * Sets value in cell.
	 * @param inValue value to add inside the cell.
	 */
	void setValue(double inValue);
	/**
	 * Gets the value from the cell.
	 * @return double The value inside the cell.
	 */
	[[nodiscard]] double getValue() const;

	/**
	 * Sets string value.
	 * @param inString the string value.
	 */
	void setString(std::string_view inString);
	/**
	 * Gets the string inside the cell.
	 * @return string cell.
	 */
	[[nodiscard]] std::string getString() const;
private:
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

	double _value{ 0 };
};

