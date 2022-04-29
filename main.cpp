#include "Spreadsheet.h"

int main()
{
	Spreadsheet sheet(5, 6);
	SpreadsheetCell& cell = sheet.getCellAt(1, 1);

	const Spreadsheet sheet1(5, 6);
	const SpreadsheetCell cell1 = sheet1.getCellAt(1, 1);
	return 0;
}
