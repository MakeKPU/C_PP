#include "pch.h"
#include "Spreadsheet.h"
#include "SpreadsheetImpl.h"


Spreadsheet::Spreadsheet(const SpreadsheetApplication & theApp, int inWidth, int inHeight)
{
	mImpl = std::make_unique<SpreadsheetImpl>(theApp, inWidth, inHeight);
	//unique_ptr<SpreadsheetImpl>mImpl(new SpreadsheetImpl(theApp, inWidth, inHeight));
}

Spreadsheet::Spreadsheet(const SpreadsheetApplication & theApp)
{
	mImpl = std::make_unique<SpreadsheetImpl>(theApp);
}

Spreadsheet::Spreadsheet(const Spreadsheet & src)
{
	mImpl = std::make_unique<SpreadsheetImpl>(*src.mImpl);
}

Spreadsheet::~Spreadsheet()
{
}

Spreadsheet & Spreadsheet::operator=(const Spreadsheet & rhs)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	//역참조를 하지 않으면 문제가 생김
	//스마트 포인터는 대입연산을 지원하지 않는다(본래값)(역참조는 가능)
	*mImpl = *rhs.mImpl;
	return *this;
}

void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell & inCell)
{
	mImpl->setCellAt(x, y, inCell);
}

SpreadsheetCell & Spreadsheet::getCellAt(int x, int y)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return mImpl->getCellAt(x, y);
}

int Spreadsheet::getId() const
{
	return mImpl->getId();
}
