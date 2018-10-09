#pragma once
#include "Super.h"

/*
	파생 클래스에서는 베이스 클래스에서 정의된 public, protected 멤버와
	메서드를 마치 자기 자신이 정의한 것처럼 사용할 수 있다. 사실 기술적으로도
	파생 클래스 안에 정의된 것과 마찬가지이다.
*/

class Sub : public Super //Super클래스가 final로 정의되어 있다면 부모클래스 상속 불가능!
{
public:
	Sub();
	
	//Sub클래스가 부모 역할을 할 일이 없다고 하더라도
	//메서드 선언에 virtual 키워드를 넣어두는 것이 안전하다.
	virtual void someOtherMethod();
	//someMethod()를 Sub 클래스에서 오버라이딩하기 위해서는
	//Sub클래스의 정의에서 오버라이딩할 메서드를 선언해주어야 한다.
	virtual void someMethod() override; //Super의 메서드 someMethod()를 오버라이딩
								        //virtual을 빼도 이미 부모클래스에 선언되어 있으므로
										//virtual로 적용된다.
	//Super클래스의 someMethod()가 final키워드로 정의되어 있다면 오류 발생!
	virtual ~Sub();

	/* virtual을 빠뜨렸을 때 발생하는 모호한 문제들을 피하기 위해 소멸자를 포함해서 모든 메서드를
	무조건 virtual로 선언하는 것이 좋다. 단, 생성자는 virtual로 선언할 수 없어 예외다.*/
};

