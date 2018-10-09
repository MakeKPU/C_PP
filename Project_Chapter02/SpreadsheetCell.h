#pragma once

//definition of Class
class SpreadsheetCell
{
	//접근지정자를 사용자가 설정하지 않은 Default 접근지정자는 Private 고정이다.

//가독성을 위해 접근 지정자들에 속할 항목들을 그룹으로 선언하는 것이 좋다.
public:
	//디폴트 생성자를 포함하여 생성자가 전혀 정의되지 않은 클래스를 만들려면 delete를 대입
	//SpreadsheetCell() = delete;

	SpreadsheetCell();// = default; //디폴트 생성자를 정의하는 새로운 방법! default를 적는순간 그 생성자가 기본이됨
	SpreadsheetCell(double InitialValue);
	SpreadsheetCell(const std::string& initialValue);
	~SpreadsheetCell();

	void setValue(double inValue);
	//객체의 Property 변경이 없는 Method는 const로 선언하는 것이 바람직하다.
	//const 선언시 Property 변경 불가
	double getValue() const;
	//텍스트셀 지원
	void setString(const std::string& inString);
	const std::string& getString() const;
	//
	void printCell(const SpreadsheetCell& inCell);
	//대입 연산자 선언
	//default와 delete으로 선언과 배제가 가능
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
private:
	//데이터의 멤버선언
	std::string doubleToString(double inValue) const;
	double stringToDouble(const std::string& inString) const;
	double mValue = 0.0; //클래스 내 멤버 초기화.
	std::string mString;
};
//끝에 붙는 세미콜론은 꼭 붙여야 한다 
//만약 붙이지 않는다면 컴파일러에서 엄청난 오류를 뱉어낼 수 있다.

