//
// Created by Frederik Desmet on 29/04/2022.
//

#pragma once

#include <memory>

#include "SpreadsheetCell.h"

// forward declarations.
class SpreadsheetApplication;

class ISpreadsheet
{
public:
	ISpreadsheet(const SpreadsheetApplication& theApp, size_t width = _maxWidth, size_t height = _maxHeight);
	ISpreadsheet(const ISpreadsheet& rhs);
	~ISpreadsheet();

	ISpreadsheet& operator=(const ISpreadsheet& rhs);

	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);

	size_t getId() const;

	static const size_t _maxWidth{ 100 };
	static const size_t _maxHeight{ 100 };

	friend void swap(ISpreadsheet& first, ISpreadsheet& second) noexcept;
private:
	class Spreadsheet;
	std::unique_ptr<Spreadsheet> _spreadsheet;
};


