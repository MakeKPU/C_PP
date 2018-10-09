#pragma once
#include "pch.h"

class Something
{
public:
	Something() { cout << "2"; }
	virtual ~Something() { cout << "2"; } //작동은 하지만 virtual로 선언하는 것이 좋음
};

class Parent
{
public:
	Parent() { cout << "1"; }
	Parent(int i) { cout << "4"; }
	~Parent() { cout << "1"; } //버그! 반드시 virtual이어야 한다.
};

class Child : public Parent
{
public:
	/*생성자 호출 순서*/
	/*이니셜라이저에서 따로 처리가 없다면 디폴트생성자*/
	Child() /*: Parent(4)*/ /*first*/ { cout << "3"; /*third*/ }
	virtual ~Child() { cout << "3"; } //작동은 하지만 virtual로 선언하는 것이 좋다.
private:
	Something mDataMember; /*second*/
};

/*
	맨처음 상속한 Parent가 생성자가 불리고 그이후 멤버 변수가 초기화되면서 Something이 생성자가 불린후
	마지막으로 Child가 생성자가 불린다.
	
	파생 클래스의 생성자 파라미터를 베이스 클래스의 생성자에 넘겨주는 것은 아주 일반적인 
	사용 예로 문제될 것이 전혀 없다. 하지만 파생 클래스의 데이터 멤버를 베이스 클래스의 
	생성자 파라미터로 넘기는 것은 제대로 작동하지 않는다. 코드는 컴파일 되겠지만 멤버의
	초기화는 베이스 클래스가 초기화된 다음에 일어나기 떄문에 실제 어떤 값이 넘겨질지
	보증하기 어렵다.
	
	warning : 생성자 안에서는 virtual 메서드의 동작 방식이 달라진다.
	파생 클래스에서 베이스 클래스의 virtual 메서드를 오버라이딩하고 있더라도 
	베이스 클래스의 생성자 안에서는 베이스 클래스의 메서드가 호출된다.
*/

/*
	Delete될때 Parent의 소멸자만 호출된다. 소멸자가 virtual로 선언되지 않았기 때문이다.
	결과적으로 Child의 소멸자는 호출 되지 않았고 그 데이터 멤버도 삭제되지 않았다.
	이 문제는 Parent의 소멸자만 virtual로 만들면 해결된다. 부모 클래스에서 virtual로 선언했기
	때문에 파생 클래스에서도 자동으로 virtual이 적용된다. 하지만 불필요한 불안 요소를 없애려면
	모든 소멸자를 virtual로 선언하는 것이 바람직하다.

	warning : 컴파일러가  생성하는 디폴트 소멸자는 virtual이 아니다! 그러므로 항상 소멸자를 명시적으로
	정의하여 virtual로 선언해주어야 한다! 전부 할 수 없다면 부모 클래스만이라도 꼭 해주어야 한다.
*/
