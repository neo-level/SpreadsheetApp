//
// Created by Frederik Desmet on 29/04/2022.
//

#include <stdexcept>
#include <utility>

#include "Spreadsheet.h"

Spreadsheet::Spreadsheet(size_t width, size_t height)
	: _width(width), _height(height)
{
	_cells = new SpreadsheetCell* [_width];
	for (size_t i = 0; i < _width; i++)
	{
		_cells[i] = new SpreadsheetCell[_height];
	}
}
Spreadsheet::~Spreadsheet()
{
	for (size_t i = 0; i < _width; i++)
	{
		delete[] _cells[i];
	}
	delete[] _cells;
	_cells = nullptr;
}
Spreadsheet::Spreadsheet(const Spreadsheet& src)
	: Spreadsheet(src._width, src._height)
{
	for (size_t i = 0; i < _width; i++)
	{
		for (size_t j = 0; j < _height; j++)
		{
			_cells[i][j] = src._cells[i][j];
		}
	}
}
void Spreadsheet::verifyCoordinates(size_t x, size_t y) const
{
	if (x >= _width || y >= _height)
		throw std::out_of_range("");
}
void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
{
	verifyCoordinates(x, y);
	_cells[x][y] = cell;
}
const SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y) const
{
	verifyCoordinates(x, y);
	return _cells[x][y];
}
SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
	return const_cast<SpreadsheetCell&>(std::as_const(*this).getCellAt(x, y));
}
void swap(Spreadsheet& first, Spreadsheet& second) noexcept
{
	using std::swap;

	swap(first._width, second._width);
	swap(first._height, second._height);
	swap(first._cells, second._cells);
}
Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	if (this == &rhs)
		return *this;

	Spreadsheet temp(rhs);
	swap(*this, temp);
	return *this;
}
