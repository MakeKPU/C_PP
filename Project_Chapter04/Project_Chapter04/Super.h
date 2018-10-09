#pragma once

//부모 클래스

/**/

class Super //final 
/*상속방지 : final키워드를 통해 파생 클래스로의 확장이 불가능한 
		    클래스를 정의 할 수 있다.*/
{
public:
	Super();
	//void someMethod();
	/*
	메서드 오버라이딩
	메서드 오버라이딩을 하는 이유는 기능 추가하거나 바꾸기 위해서이다.
	Sub의 정의는 부모 클래스에 새로운 메서드 someOtherMethod()를 추가한다.
	다른 메서드 someMethod()는 Super로 부터 상속받은 것이고 당연하게도
	베이스 클래스에서와 완벽히 같게 동작한다. 하지만 많은 경우 상속을
	받으면서 베이스 클래스에 이미 정의되어 있는 메서드의 행동을 바꾸어야 할 때가
	있다. 이것을 메서드 오버라이딩이라고 한다.
	*/
	virtual void someMethod(); //final;
	/*오버라이딩 방지 : final키워드를 통해 파생 클래스에 오버라이딩 되지 않도록 할수 있다.*/
	~Super();

	/*protected 멤버나 메서드는 파생클래스에서 접근 가능
	  private은 파생클래스에서 접근 불가능*/
	/*모든 멤버 데이터는 private으로 하는걸 권장한다. 파생클래스에서 
	  쓰고 싶다면 protected 메서드로 getter setter를 만들면 된다.*/
protected:
	int mProtectedInt;
private:
	int mPrivateInt;
};

