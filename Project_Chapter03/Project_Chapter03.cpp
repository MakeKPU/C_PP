// Project_Chapter03.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "Spreadsheet.h"

//오늘의 중요한 것
//->클래스가 동적 메모리를 가진다면 소멸자, 복제 생성자, 대입 연산자를 꼭! 구현하여야한다.

//C++은 이동 시맨틱을 지원한다. 이 때문에 이동 생성자와 이동 대입 연산자가 필요하다.
//이러한 메서드들은 특정 상황에서 성능 오버헤드를 줄이는 데 사용할 수 있다.

void printSpreadsheet(Spreadsheet s)
{
	//얕은 복사이기 때문에 이 함수 return시 
	//s객체의 소멸자 호출로 s1에 있던 mCells가 가리키는 메모리를 해제해버린다.
	//s1이 가리키는 포인터는 더 이상 유효하지 않다. 댕글링 포인터(dangling pointer)
}

int main()
{
	/*Spreadsheet s1(4, 3);
	printSpreadsheet(s1);*/

	//대입시에는 더 최악
	//Spreadsheet s1(2, 2), s2(4, 3);
	//s1 = s2;
	//이 대입연산 수행시 얕은 복사로 인해
	//s2에 있던 mCell 메모리 영역이 주인을 잃어버린다!
	//이를 해결하기 위해서는 깊은 복사가 필요하다!
	//
	//이러한 문제들 떄문에 컴파일러가 자동으로 생성하는 
	//복제 생성자와 대입 연산자를 그대로 이용하는 것은 매우 위험하다.

	//const 객체
	//const가 아닌 객체는 const여부와 관계없이 메서드 호출이 가능하지만
	//const인 객체는 const 메서드만 호출이 가능하다.
	//비록 cosnt 객체라 하더라도 객체의 소멸은 가능하다. 어떤 경우라도 소멸자에 const제한자를
	//적용하는 것은 좋은 생각이 아니다.
	//SpreadsheetCell myCell(5);
	//cout << myCell.getValue() << endl; //정상
	//myCell.setString("6"); //정상
	//const SpreadsheetCell& anotherCell = myCell;
	//cout << anotherCell.getValue() << endl; //정상
	//anotherCell.setString("6");			    //non-const 메서드 호출. 컴파일 에러 발생!

	
	SpreadsheetCell myCell(4), aThirdCell;
	string str = "hello";
	//묵시적인 타입 캐스팅
	//암묵적인 변환을 막고 싶다면 막고 싶은 생성자 앞에 explicit를 붙여주면 된다.
	aThirdCell = myCell + str;
	aThirdCell = myCell + 5.6;
	aThirdCell = myCell + 4;

	return 0;
}
