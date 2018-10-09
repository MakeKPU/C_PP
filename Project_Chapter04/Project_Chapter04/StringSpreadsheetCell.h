#pragma once
#include "SpreadsheetCell.h"

//추상 클래스이기 떄문에 구현부가 없거나 껍데기만 들어가는게 대부분이다.

class DoubleSpreadsheetCell;
class StringSpreadsheetCell : public SpreadsheetCell
{
	//추상 클래스를 상속받으면
	//그 상속받은 자식 클래스는 추상 클래스에 있는 모든 순수 가상 함수를 빠짐없이 모두 구현해야 한다.
	//구현하지 않는다면 그 클래스도 추상 클래스가 되어 버려서 인스턴스화가 불가능해진다.
public:
	StringSpreadsheetCell();
	//통합성을 위해 double타입 셀과 string 타입 셀을 상호 변환할 수 있게 하려면 
	//각각의 셀 타입을 인자로 가지는 생성자를 추가해야 한다. 
	//복사 생성자와 비슷해 보이지만 형제 클래스의 참조 인자만 받는다.
	StringSpreadsheetCell(const DoubleSpreadsheetCell& inDoubleCell);
	virtual ~StringSpreadsheetCell();
	virtual void set(const std::string& inString) override;
	virtual const std::string getString() const override;
private:
	std::string mValue;
};

