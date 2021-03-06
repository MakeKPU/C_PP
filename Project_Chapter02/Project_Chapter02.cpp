// Project_Chapter02.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"



#include "SpreadsheetCell.h"
#include "EventSequence.h"




struct Struct_SpreadsheetCell
{
	//struct는 class와 다르게 default로 public 고정이다.
	void setValue(double inValue);
	double getValue() const;
protected:
	double mValue;
};

int main()
{
	////스마트 포인터
	//auto myCellp = make_unique<SpreadsheetCell>();
	////생성자
	//auto myCellpCoter = make_unique<SpreadsheetCell>(4.0);
	////아래 코드와 동일
	////unique_ptr<SpreadsheetCell> myCellp(new SpreadsheetCell());
	//myCellp->setValue(3.7);
	//cout << "cell 1: " << myCellp->getValue() << " "
	//	<< myCellp->getString() << endl;

	//initialize_list
	//try
	//{
	//	EvenSequence p1 = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
	//}
	//catch (const invalid_argument& e)
	//{
	//	cout << e.what() << endl;
	//}
	////p1.dump();

	//try
	//{
	//	EvenSequence p2 = { 1.0, 2.0, 3.0 };
	//}
	//catch (const invalid_argument& e)
	//{
	//	cout << e.what() << endl;
	//}

	//STL에서도 사용이 가능하다.
	//std::vector<std::string> myVec = { "String 1", "String 2", "String 3" };

	//변수 선언시 복제 생성자 이용, 대입 연산을 할 때 대입 연산자가 호출
	SpreadsheetCell myCell(5);	//복사생성자
	SpreadsheetCell anotherCell(myCell);	//복사생성자

	SpreadsheetCell aThirdCell = myCell;	//복사생성자

	anotherCell = myCell; //anotherCell의 operator=을 호출한다.
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

