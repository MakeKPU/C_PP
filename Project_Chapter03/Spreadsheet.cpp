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
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	//�������� ���� ������ ������ ����
	//����Ʈ �����ʹ� ���Կ����� �������� �ʴ´�(������)(�������� ����)
	*mImpl = *rhs.mImpl;
	return *this;
}

void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell & inCell)
{
	mImpl->setCellAt(x, y, inCell);
}

SpreadsheetCell & Spreadsheet::getCellAt(int x, int y)
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	return mImpl->getCellAt(x, y);
}

int Spreadsheet::getId() const
{
	return mImpl->getId();
}
