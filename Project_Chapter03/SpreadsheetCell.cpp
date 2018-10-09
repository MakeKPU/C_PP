#include "pch.h"
#include "SpreadsheetCell.h"


void SpreadsheetCell::setColor(Colors color)
{
	mColor = color;
}

SpreadsheetCell::SpreadsheetCell(double InitialValue)
{
	set(InitialValue);
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

void SpreadsheetCell::set(double inValue)
{
	//이렇게 함으로써 mValue와 mString은 항상 유효한 값을 가지게 되었다.
	mValue = inValue;
	mString = doubleToString(inValue);
	//자신의 셀의 내용물을 출력하고 싶을 때에도 this포인터는 유용하게 쓰여진다.
	printCell(*this);
}

//Property와 매개변수의 이름이 같은경우에는 this포인터를 활용하면 편하다.
//this->inValue = inValue;

//inline
//C++에서는 메서드나 함수를 별도의 분리된 코드 블록으로 호출하는 대신, 
//호출 지점에 바로 메서드나 함수의 바디를 옮겨놓아 호출 오버헤드를 줄이는 방법을 제공함
//inlining이라고 한다.
//컴파일러는 인라이닝이 오히려 성능에 해가 된다고 판단하면 inline 키워드를 무시할수도 있다.
//진보된 C++컴파일러는 inline 메서드를 헤더 파일에 정의하지 않더라도 인라이닝이 가능하다.
//이러한 컴파일러를 쓴다면 되도록이면 간단한 함수도 정의부를 이용하지 말고 cpp파일을 이용하는 것이 좋다.
//클래스 정의 안에서 바로 구현부를 정의하면 인라이닝이 적용된다.
inline double SpreadsheetCell::getValue() const
{
	mNumAccesses++;
	return mValue;
}

inline void SpreadsheetCell::set(const std::string & inString)
{
	mString = inString;
	mValue = stringToDouble(inString);
}

const std::string & SpreadsheetCell::getString() const 
//const 메서드 : 메서드 내에 접근하는 모든 데이터멤버를 cosnt로 취급함
//그래서 멤버를 변경하려 할 때 컴파일러가 에러를 발생 시킨다.
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	mNumAccesses++;
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

SpreadsheetCell SpreadsheetCell::add(const SpreadsheetCell & cell) const
{
	SpreadsheetCell newCell;
	newCell.set(mValue + cell.mValue); //mValue와 mString의 멤버를 업데이트
	return newCell;
}

//SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell & cell) const
//{
//	SpreadsheetCell newCell;
//	newCell.set(mValue + cell.mValue); //mValue와 mString의 멤버를 업데이트
//	return newCell;
//}

SpreadsheetCell SpreadsheetCell::operator+(double rhs) const
{
	return SpreadsheetCell(mValue + rhs);
}

SpreadsheetCell & SpreadsheetCell::operator+=(const SpreadsheetCell & rhs)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	set(mValue + rhs.mValue);
	return *this;
}

SpreadsheetCell & SpreadsheetCell::operator-=(const SpreadsheetCell & rhs)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	set(mValue - rhs.mValue);
	return *this;
}

SpreadsheetCell & SpreadsheetCell::operator*=(const SpreadsheetCell & rhs)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	set(mValue * rhs.mValue);
	return *this;
}

SpreadsheetCell & SpreadsheetCell::operator/=(const SpreadsheetCell & rhs)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	if (rhs.mValue == 0)
		throw invalid_argument("Divide by zero.");
	set(mValue / rhs.mValue);
	return *this;
}

//#include <mutex>
std::string SpreadsheetCell::doubleToString(double inValue)
{
	//Automatically unlock
	/*mutex a;
	lock_guard<mutex> lockM{ a };*/
	//_asm mfence;


	ostringstream ostr;
	ostr << inValue;
	return ostr.str();
}

double SpreadsheetCell::stringToDouble(const std::string & inString)
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

bool checkSpreadsheetCell(const SpreadsheetCell & cell)
{
	return !(cell.mString.empty());
}

SpreadsheetCell operator+(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue + rhs.mValue); //mValue와 mString 멤버를 업데이트한다.
	return newCell;
}

SpreadsheetCell operator-(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue - rhs.mValue); //mValue와 mString 멤버를 업데이트한다.
	return newCell;
}

SpreadsheetCell operator*(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue * rhs.mValue); //mValue와 mString 멤버를 업데이트한다.
	return newCell;
}

SpreadsheetCell operator/(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	if (rhs.mValue == 0)
		throw invalid_argument("Divide by zero.");
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue / rhs.mValue); //mValue와 mString 멤버를 업데이트한다.
	return newCell;
}

bool operator==(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	return (lhs.mValue == rhs.mValue);
}

bool operator>(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	return (lhs.mValue > rhs.mValue);
}

bool operator<(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	return (lhs.mValue < rhs.mValue);
}

bool operator!=(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	return (lhs.mValue != rhs.mValue);
}

bool operator>=(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	return (lhs.mValue >= rhs.mValue);
	//혹은
	//return !(lhs < rhs);
}

bool operator<=(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	return (lhs.mValue <= rhs.mValue);
	//혹은
	//return !(lhs > rhs);
}
