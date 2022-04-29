//
// Created by Frederik Desmet on 29/04/2022.
//

#include <utility>

#include "ISpreadsheet.h"
#include "Spreadsheet.h"

ISpreadsheet::ISpreadsheet(const SpreadsheetApplication& theApp, size_t width, size_t height)
{
	_spreadsheet = std::make_unique<Spreadsheet>(theApp, width, height);
}
ISpreadsheet::ISpreadsheet(const ISpreadsheet& src)
{
	_spreadsheet = std::make_unique<Spreadsheet>(*src._spreadsheet);
}
ISpreadsheet::~ISpreadsheet() = default;

void ISpreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
{
	_spreadsheet->setCellAt(x, y, cell);
}
SpreadsheetCell& ISpreadsheet::getCellAt(size_t x, size_t y)
{
	return _spreadsheet->getCellAt(x, y);
}
size_t ISpreadsheet::getId() const
{
	return _spreadsheet->getId();
}
ISpreadsheet& ISpreadsheet::operator=(const ISpreadsheet& rhs)
{
	*_spreadsheet = *rhs._spreadsheet;
	return *this;
}
void swap(ISpreadsheet& first, ISpreadsheet& second) noexcept
{
	using std::swap;
	swap(first._spreadsheet, second._spreadsheet);
}