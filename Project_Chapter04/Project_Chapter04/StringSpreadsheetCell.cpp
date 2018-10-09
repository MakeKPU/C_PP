#include "pch.h"
#include "StringSpreadsheetCell.h"
#include "DoubleSpreadsheetCell.h"

StringSpreadsheetCell::StringSpreadsheetCell()
	: mValue("#NOVALUE")
{
}


StringSpreadsheetCell::StringSpreadsheetCell(const DoubleSpreadsheetCell & inDoubleCell)
{
	set(inDoubleCell.getString());
}

StringSpreadsheetCell::~StringSpreadsheetCell()
{
}

void StringSpreadsheetCell::set(const std::string & inString)
{
	mValue = inString;
}

const std::string StringSpreadsheetCell::getString() const
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return mValue;
}


