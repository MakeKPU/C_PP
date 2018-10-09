#pragma once
#include "SpreadsheetCell.h"

//Spreadsheet와 SpreadsheetApplication 두 클래스 모두 정의되어 있어서
//서로 참조할 수 있어야 한다.
//이런 문제는 #include로는 해결할 방법이 없다.
//그래서 포워드 선언이 필요하다.
//교차 참조되는 클래스의 헤더 파일 중 어느 한쪽에 상대편 클래스의 헤더 파일을 
//인클루드 하는 대신 포워드 선언을 해두면 컴파일러가 나중에 해당 정의를 찾아서 타입 매칭을 한다.
class SpreadsheetApplication; //포워드 선언
class SpreadsheetImpl
{
public:
	//중첩된 클래스는 간단한 클래스일때만 구현한다.
	//왜냐하면 코드가 지저분해지기 때문이다.
	class TestClass
	{
	public:
		int getNum();
	private:
		int mNum = 10;
	};
public:
	//friend선언은 권한을 열어줄 클래스에서만 할 수 있다. 
	//즉, 다른 클래스에 대해 접근 권한을 요청하는 클래스 또는 메서드, 함수 스스로
	//다른 클래스의 friend 선언을 할 수는 없다.
	//friend void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& cell);
public:
	SpreadsheetImpl() = default;
	//디폴트 파라미터
	//모든 파라미터에 대해 디폴트값이 지정되었다면,
	//아무런 인자 없이 객체의 생성자를 호출할 수 있게 된다.
	//하지만 이렇게 하면 객체 생성 시 컴파일러가 어느 메서드를 이용해야 할지 
	//알 수 없으므로 에러 메시지가 발생한다.
	SpreadsheetImpl(const SpreadsheetApplication& theApp,
		int inWidth = kMaxWidth, 
		int inHeight = kMaxHeight);
	//메모리할당으로 인한 복제 생성자나 대입 연산자 때문에 발생하는 문제를 피하는 방법은
	//복제 생성자와 대입 연산자를 배제하는 것이다. (정의부 뒤에 = delete를 붙인다.)
	//만약 배제한다면 대입이나 복제에 관한 작업은 컴파일러에서 걸러준다.
	//혹은 접근 지정자를 private으로 놓으면 된다.
	//복제 생성자
	SpreadsheetImpl(const SpreadsheetImpl& src);
	//대입 연산자
	SpreadsheetImpl& operator=(const SpreadsheetImpl& rhs);
	~SpreadsheetImpl();
public:
	void setCellAt(int x, int y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(int x, int y);
	//복제 생성자와 대입 연산자를 위한 공용 편의 루틴
	void copyFrom(const SpreadsheetImpl& src);
	int getId() const;
private:
	bool inRange(int val, int upper);
	int mWidth, mHeight;
	SpreadsheetCell** mCells;
private:
	//static 데이터 맴버
	//C의 global 변수와 유사하지만 특정 클래스에 종속된다.
	//클래스 안에서 정의하는 것으로 끝나지 않고 별도의 소스파일 안에서 다시 한번 선언해야함
	//static 멤버 변수는 일반 변수와 다르게 자동으로 0이나 nullptr로 초기화 된다.
	//public으로 접근 지정자 선언시에는 클래서 메서드 밖에서도 접근이 가능하다.
	//하지만 데이더 멤버를 public으로 선언하여 외부에 노출시키는 것은 바람직하지 않기 때문에 
	//getter setter를 사용하는게 바람직하다.
	static int sCounter;
	int mId;
public:
	//public이기 때문에 어디서든 접근이 가능하다.
	//const 데이터 멤버
	static const int kMaxHeight = 100;
	static const int kMaxWidth = 100;
private:
	//Spreadsheet 객체는 항상 SpreadsheetApplication 객체를 참조할 것이기 때문에 
	//포인터보다는 참조형을 사용하는 것이 바람직히다.
	//포인터와 달리 참조형은 적합한 객체로 초기화되어야 존재할 수 있기 때문에 훨씬 안전하다.
	//참조형 변수가 const냐 아니냐에 따라 큰 차이가 있다. const 형 참조형 변수로 참조된
	//SpreadsheetApplication 데이터 멤버는 SpreadsheetApplication 객체에 대해 const 메서드만 호출가능하다.
	//만약 그렇지 않으면 컴파일 에러를 낸다.
	const SpreadsheetApplication& mTheApp;
};

