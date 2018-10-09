#include "pch.h"
#include "DoubleSpreadsheetCell.h"
#include "StringSpreadsheetCell.h"
#include <limits>

DoubleSpreadsheetCell::DoubleSpreadsheetCell()
	:mValue(std::numeric_limits<double>::quiet_NaN())
	//NaN�� "Not a Number"�� ���� ���ڰ� �ƴ϶�� �ǹ�
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
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
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
