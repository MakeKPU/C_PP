#pragma once
#include "SpreadsheetCell.h"
#include <memory>
//������ ����
class SpreadsheetImpl;
class SpreadsheetApplication;

//������ �������̽� �����
//�������̽� Ŭ������ ���� Ŭ������ Ȱ��
//Pimpl(pointer to implementation)���� 
//Ŭ������ ���� ������ �Ź� �������̽� Ŭ������ ���� Ŭ������ ����
//���� Ŭ������ ���� ����� ����� Ŭ������ �Ȱ���
//������ �������̽� Ŭ������ ���� Ŭ������ public �޼��常 ����
//���� �� �ϳ��� ������ ����� ���� Ŭ������ �����͸� ������.
//�̷��� Ŭ������ �и��ϸ� ���� Ŭ������ ��� �ٲ�� public �������̽� Ŭ�������� ��ȭ��
//�����Ƿ� �������� �ٽ� �ؾ� �� �ʿ並 ���� �� �ִ�.
class Spreadsheet
{
public:
	Spreadsheet() = default;
	Spreadsheet(const SpreadsheetApplication& theApp, int inWidth, int inHeight);
	Spreadsheet(const SpreadsheetApplication& theApp);
	Spreadsheet(const Spreadsheet& src);
	~Spreadsheet();
	Spreadsheet& operator=(const Spreadsheet& rhs);
	void setCellAt(int x, int y, const SpreadsheetCell& inCell);
	SpreadsheetCell& getCellAt(int x, int y);
	int getId() const;
private:
	std::unique_ptr<SpreadsheetImpl> mImpl;
};

