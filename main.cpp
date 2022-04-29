#include "Spreadsheet.h"

class SpreadsheetApplication
{
};
int main()
{
	SpreadsheetApplication theApp;
	ISpreadsheet s1(theApp);
	ISpreadsheet s3(theApp, 5, 6);
	ISpreadsheet s4(s3);
	s1 = s4;
	return 0;
}
