cmake_minimum_required(VERSION 3.21)
project(SpreadsheetApp)

set(CMAKE_CXX_STANDARD 17)

add_executable(SpreadsheetApp main.cpp SpreadsheetCell.cpp SpreadsheetCell.h Spreadsheet.cpp Spreadsheet.h)
