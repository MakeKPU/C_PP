#pragma once
#include "SpreadsheetCell.h"


class StringSpreadsheetCell;
class DoubleSpreadsheetCell : public SpreadsheetCell
{
public:
	DoubleSpreadsheetCell();
	virtual ~DoubleSpreadsheetCell();
	virtual void set(double inDouble);
	virtual void set(const std::string& inString) override;
	virtual const std::string getString() const override;
private:
	static std::string doubleToString(double inValue);
	static double stringToDouble(const std::string& inString);
	double mValue;
};

