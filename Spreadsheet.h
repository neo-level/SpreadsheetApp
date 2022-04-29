//
// Created by Frederik Desmet on 29/04/2022.
//

#pragma once

#include <cstddef>
#include "SpreadsheetCell.h"

class Spreadsheet
{
public:
	Spreadsheet(size_t width, size_t height);
	Spreadsheet(const Spreadsheet& src);
	~Spreadsheet();

	Spreadsheet& operator=(const Spreadsheet& rhs);

	/**
	 * Sets the value of the specified cell.
	 * @param x horizontal axis.
	 * @param y vertical axis.
	 * @param cell cell object, containing the value to be inserted.
	 */
	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);

	/**
	 * Gets the cell object of the specified cell.
	 * @param x horizontal axis.
	 * @param y vertical axis.
	 * @return SpreadsheetCell object reference.
	 */
	SpreadsheetCell& getCellAt(size_t x, size_t y);
	const SpreadsheetCell& getCellAt(size_t x, size_t y) const;

	friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
private:
	/**
	 * Checks if the passed coordinates are within the bounds of the sheet.
	 * @param x horizontal axis.
	 * @param y vertical axis.
	 */
	void verifyCoordinates(size_t x, size_t y) const;

	size_t _width, _height{};
	SpreadsheetCell** _cells{ nullptr };
};