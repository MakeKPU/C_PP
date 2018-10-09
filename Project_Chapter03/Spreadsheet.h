#pragma once
#include "SpreadsheetCell.h"
#include <memory>
//포워드 선언
class SpreadsheetImpl;
class SpreadsheetApplication;

//안정된 인터페이스 만들기
//인터페이스 클래스와 구현 클래스의 활용
//Pimpl(pointer to implementation)관례 
//클래스를 만들 때마다 매번 인터페이스 클래스와 구현 클래스를 만듬
//구현 클래스는 원래 만들던 방식의 클래스와 똑같음
//하지만 인터페이스 클래스는 구현 클래스의 public 메서드만 담음
//그저 단 하나의 데이터 멤버로 구현 클래스의 포인터를 가진다.
//이렇게 클래스를 분리하면 구현 클래스가 어떻게 바뀌든 public 인터페이스 클래스에는 변화가
//없으므로 컴파일을 다시 해야 할 필요를 줄일 수 있다.
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

