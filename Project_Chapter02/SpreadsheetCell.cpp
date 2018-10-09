#include "pch.h"
#include "SpreadsheetCell.h"

SpreadsheetCell::SpreadsheetCell()
{
	mValue = 0;
}

SpreadsheetCell::SpreadsheetCell(double InitialValue)
{
	setValue(InitialValue);
}

SpreadsheetCell::SpreadsheetCell(const std::string & initialValue) :
	//이니셜라이즈 순서 멤버변수 선언 순서와 맞추는걸 추천
	//복제 생성자를 통한 초기화
	//mValue{ stringToDouble(initialValue) }, mString{ initialValue }

	//생성자 위임(delegating constructor) : 생성자 안에서 같은 클래스의 다른 생성자를 호출
	//단, 이니셜 라이즈로만 가능함
	SpreadsheetCell(stringToDouble(initialValue))
{
	//임시객체
	//int {3};
	//setString(initialValue);

	//대입 연산을 통한 초기화
	mString = initialValue;
}

SpreadsheetCell::~SpreadsheetCell()
{
}

void SpreadsheetCell::setValue(double inValue)
{
	//이렇게 함으로써 mValue와 mString은 항상 유효한 값을 가지게 되었다.
	mValue = inValue;
	mString = doubleToString(inValue);
	//자신의 셀의 내용물을 출력하고 싶을 때에도 this포인터는 유용하게 쓰여진다.
	printCell(*this);
}

//Property와 매개변수의 이름이 같은경우에는 this포인터를 활용하면 편하다.
//this->inValue = inValue;

double SpreadsheetCell::getValue() const
{
	return mValue;
}

void SpreadsheetCell::setString(const std::string & inString)
{
	mString = inString;
	mValue = stringToDouble(inString);
}

const std::string & SpreadsheetCell::getString() const
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return mString;
}

void SpreadsheetCell::printCell(const SpreadsheetCell & inCell)
{
	cout << inCell.getString() << endl;
}

SpreadsheetCell & SpreadsheetCell::operator=(const SpreadsheetCell & rhs)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	//자기 자신을 대입하는지 검사
	if (this == &rhs)
	{
		return *this;
	}

	mValue = rhs.mValue;
	mString = rhs.mString;

	return *this;
}

//#include <mutex>
std::string SpreadsheetCell::doubleToString(double inValue) const
{
	//Automatically unlock
	/*mutex a;
	lock_guard<mutex> lockM{ a };*/
	//_asm mfence;
	
	
	ostringstream ostr;
	ostr << inValue;
	return ostr.str();
}

double SpreadsheetCell::stringToDouble(const std::string & inString) const
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

