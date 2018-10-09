#include "pch.h"
#include "DoubleSpreadsheetCell.h"
#include "StringSpreadsheetCell.h"
#include <limits>

DoubleSpreadsheetCell::DoubleSpreadsheetCell()
	:mValue(std::numeric_limits<double>::quiet_NaN())
	//NaN은 "Not a Number"의 약어로 숫자가 아니라는 의미
{
}

DoubleSpreadsheetCell::~DoubleSpreadsheetCell()
{
}

void DoubleSpreadsheetCell::set(double inDouble)
{
	mValue = inDouble;
}

void DoubleSpreadsheetCell::set(const std::string & inString)
{
	mValue = stringToDouble(inString);
}

const std::string DoubleSpreadsheetCell::getString() const
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return doubleToString(mValue);
}

std::string DoubleSpreadsheetCell::doubleToString(double inValue)
{
	ostringstream ostr;
	ostr << inValue;
	return ostr.str();
}

double DoubleSpreadsheetCell::stringToDouble(const std::string & inString)
{
	double temp;
	istringstream istr(inString);
	istr >> temp;
	if (istr.fail() || !istr.eof())
	{
		return 0;
	}
	return temp;
}
