//
// Created by Frederik Desmet on 29/04/2022.
//

#include <utility>
#include <stdexcept>
#include <algorithm>

#include "ISpreadsheet.h"
#include "Spreadsheet.h"

ISpreadsheet::Spreadsheet::Spreadsheet(const SpreadsheetApplication& theApp, size_t width, size_t height)
	: _id(_counter++), _theApp(theApp), _width(width), _height(height)
{
	_cells = new SpreadsheetCell* [_width];
	for (size_t i = 0; i < _width; i++)
	{
		_cells[i] = new SpreadsheetCell[_height];
	}
}
ISpreadsheet::Spreadsheet::~Spreadsheet()
{
	for (size_t i = 0; i < _width; i++)
	{
		delete[] _cells[i];
	}
	delete[] _cells;
	_cells = nullptr;
}

ISpreadsheet::Spreadsheet::Spreadsheet(const Spreadsheet& src)
	: Spreadsheet(src._theApp, src._width, src._height)
{
	for (size_t i = 0; i < _width; i++)
	{
		for (size_t j = 0; j < _height; j++)
		{
			_cells[i][j] = src._cells[i][j];
		}
	}
}
void ISpreadsheet::Spreadsheet::verifyCoordinates(size_t x, size_t y) const
{
	if (x >= _width || y >= _height)
		throw std::out_of_range("");
}
void ISpreadsheet::Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
{
	verifyCoordinates(x, y);
	_cells[x][y] = cell;
}
SpreadsheetCell& ISpreadsheet::Spreadsheet::getCellAt(size_t x, size_t y)
{
	verifyCoordinates(x, y);
	return _cells[x][y];
}
void ISpreadsheet::Spreadsheet::swap(Spreadsheet& other) noexcept
{
	using std::swap;

	swap(_width, other._width);
	swap(_height, other._height);
	swap(_cells, other._cells);
}
ISpreadsheet::Spreadsheet& ISpreadsheet::Spreadsheet::operator=(const Spreadsheet& rhs)
{
	if (this == &rhs)
		return *this;

	Spreadsheet temp(rhs);
	swap(temp);
	return *this;
}
size_t ISpreadsheet::Spreadsheet::getId() const
{
	return _id;
}
