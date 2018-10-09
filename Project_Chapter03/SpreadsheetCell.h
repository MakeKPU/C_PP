#pragma once
#include <string>
//definition of Class
class SpreadsheetCell
{
	//접근지정자를 사용자가 설정하지 않은 Default 접근지정자는 Private 고정이다.

//가독성을 위해 접근 지정자들에 속할 항목들을 그룹으로 선언하는 것이 좋다.
public:
	//상수값을 정의해야 한다면 #define 대신 열거 타입을 이용하는 것이 좋다.
	enum class Colors { Red = 1, Green, Blue, Yellow };
	void setColor(Colors color);
public:
	//friend class
	//이렇게 선언하면 Spreadsheet의 모든 메서드는 SpreadsheetCell의 private와 protected
	//멤버/메서드에 자유롭게 접근할 수 있게 된다.
	friend class Spreadsheet;
private:
	//friend의 활용 예로, SpreadsheetCell의 문자열이 공백이 아닌지 검증하는 함수를 클래스 외부에
	//독립적으로 두고 싶을 수 있다. 문자열을 검증하기 위해서는 SpreadsheetCell의 내부데이터에 
	//접근할 수 있어야 하므로 해당 검증 함수 checkSpreadsheetCell()을 다음과 같이 SpreadsheetCell
	//클래스 정의에서 friend로 선언한다.
	friend bool checkSpreadsheetCell(const SpreadsheetCell& cell);
	/*frient는 남용되기 쉽다. friend를 이용하면 내부 구조를 다른 클래스나 함수에 노출시키기 때문에 추상화 원칙이
	훼손된다. 그러므로 연산자 오버로딩과 같이 불가피한 상황에서만 이용하는 것이 바람직하다.*/
public:
	//디폴트 생성자를 포함하여 생성자가 전혀 정의되지 않은 클래스를 만들려면 delete를 대입
	//SpreadsheetCell() = delete;

	SpreadsheetCell() = default; //디폴트 생성자를 정의하는 새로운 방법! default를 적는순간 그 생성자가 기본이됨
	SpreadsheetCell(double InitialValue);
	/*explicit*/ SpreadsheetCell(const std::string& initialValue);
	~SpreadsheetCell();

	//메서드 오버로딩
	//파라미터가 같은 리턴 타입만 다른 메서드나 함수에 대해 오버로딩을 허용하지 않음
	//set을 메서드 오버로딩 하여 부름
	void set(double inValue);
	//객체의 Property 변경이 없는 Method는 const로 선언하는 것이 바람직하다.
	//const 선언시 Property 변경 불가
	double getValue() const;
	//텍스트셀 지원
	void set(const std::string& inString);
	const std::string& getString() const;
	//
	void printCell(const SpreadsheetCell& inCell);
public:
	//대입 연산자 선언
	//default와 delete으로 선언과 배제가 가능
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
	
	//덧셈기능 구현
	//첫번째 : add 메서드
	SpreadsheetCell add(const SpreadsheetCell& cell) const;
	//두번째 : operator+의 오버로딩
	//일반적인 오버로딩
	//이건 좌항이 객체가 아니면 연산 불가!
	//SpreadsheetCell operator+(const SpreadsheetCell& cell) const;
	//임시 객체 생성 줄이는 법
	SpreadsheetCell operator+(double rhs) const;
	//operator는 교환법칙이 성립되지 않기 떄문에 따로 정의가 필요하다.
	//전역 함수 operator+는 SpreadsheetCell클래스의 proteced 멤버에 접근해야 
	//하기 때문에 friend로 선언되어야 한다.
	//연산자 오버로딩은 그 기능을 쉽게 유추할 수 있도록 구현하는 것이 바람직하다.
	
	//주의점
	//문법상 자기 자신을 operator의 lhs로 쓰기 때문에 문법상 매개변수를 두개받는 operator는 
	//클래스 내의 구현이 불가능하기 때문에 friend를 사용하여 스코프 지정연산자 없이 메서드를 구현한다.
	friend SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);

	//축약 연산을 쓰고 싶다면 자동으로 명시되지 않기 때문에 명시를 해줘야한다.
	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);

	//비교연산자
	//tup : 부동 소수점값 비교는 앱실론 값 비교를 참조하자.
	friend bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);

	//연산자 오버로딩은 클래스 사용자를 위한 서비스 차원으로 생각한다.
private:
	//doubleToString과 stringToDouble은 객체에 종속되는 부분이 없다.
	//따라서 static으로 선언해도 된다.
	//이 두 메서드는 객체 데이터에 영향을 주지 않으므로 const를 붙였지만
	//static메서드에서는 빼야한다. 왜냐하면 static 메서드는 객체에 묶이지 않기 때문에
	//객체에 변경을 가하지 않는다는 시멘틱이 더 이상 적용될 수 없기 때문이다.
	//static메서드는 연결된 객체가 없으므로 this포인터도 사용이 불가능하다.
	//(단, static 데이터맴버는 이용이 가능하다)
	static std::string doubleToString(double inValue);
	static double stringToDouble(const std::string& inString);
private:
	//데이터의 멤버선언
	double mValue = 0.0; //클래스 내 멤버 초기화.
	std::string mString;
	//mutable
	//mutable속성을 접근 카운터 멤버 변수에 적용하면 컴파일러는 해당 변수의
	//변경이 메서드의 const에 영향을 미치지 않는 것으로 간주한다.
	mutable int mNumAccesses = 0;
	Colors mColor = Colors::Red;
};
//끝에 붙는 세미콜론은 꼭 붙여야 한다 
//만약 붙이지 않는다면 컴파일러에서 엄청난 오류를 뱉어낼 수 있다.

