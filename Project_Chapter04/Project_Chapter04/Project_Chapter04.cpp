// Project_Chapter04.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

#include "Super.h"
#include "Sub.h"
#include "test.h"
#include "Book.h"
#include "SpreadsheetCell.h"
#include "StringSpreadsheetCell.h"
#include "DoubleSpreadsheetCell.h"

//상속
//이미 존재하는 클래스를 기반으로 새로운 클래스를 만들 수 있다.
//이러한 방식으로 클래스는 재사용 할 수 있고 확장 가능한 Component가 된다.
//

/*
* is-a관계 계층은 몇가지 이유에 문제가있음
1. 원본 클래스에 대한 버그 수정이 새로운 클래스에는 반영되지 않는다.
	왜냐하면 두 클래스는 서로 다른 클래스이기 때문이다.
2. 컴파일러는 원본 클래스와 새로운 클래스의 관계를 알지 못한다. 따라서 두
	클래스는 어떤 공통의 것을 파생하여 다형성을 구현한 것이 아니라 그냥 별개의 클래스 이다.
3. 데이터 타입 관점에서 볼 때 두 클래스는 완전 별개이기 때문에, 단지 코드를 공유했을 
	뿐 진정하게 is-a 관계를 구현한 것으로는 볼 수 없다.
4. 어떤 경우에는 원본 클래스의 정의가 프리컴파일된 헤더 파일에 바이너리 상태로 존재하여
	코드를 복제할 방법이 없을 수도 있다.
*/

/*
이미 존재하는 다른 클래스를 상속 받거나 확장하여 작성한다는 것을 컴파일러에 알릴 수 있다.
이렇게 하면 새로 작성하는 클래스가 기존 클래스의 데이터 멤버와 메서드를 자동으로 포함하게 한다.
이때 기존 클래스를 부모 클래스 또는 베이스 클래스 또는 슈퍼 클래스라고 하고 새로 만들어지는
클래스를 자식 클래스 또는 파생 클래스 또는 서브클래스라고 한다. 
*/

StringSpreadsheetCell operator+(const StringSpreadsheetCell& lhs,
	const StringSpreadsheetCell& rhs);

void presumptuous(Super* inSuper)
{
	//Sub* mySub = static_cast<Sub*>(inSuper);
	//mySub를 통해 Sub의 멤버와 메서드에 접근

	/*다운 캐스팅은 컴파일 타임에 검증이 안 되기 때문에 이 코드는 아무런 근거도
	없이 inSuper가 가리키는 포인터가 Sub의 객체일 거라고 가정해버린다.
	그니까 상속한 다른 클래스가 아니더라도 그냥 캐스팅 해버림*/

	Sub* mySub = dynamic_cast<Sub*>(inSuper);
	if (mySub != nullptr)
	{
		//mySub를 통해 Sub의 멤버와 메서드에 접근
	}

	/*다운 캐스팅은 필요한 경우에만 사용하고, 이때 dynamic_cast를 사용하자!*/
}

int main()
{
	//Super클래스를 상속받은 Sub객체는 두 클래스의 public 메서드에 접근이 가능하다.
	/*Sub mySub;
	mySub.someMethod();
	mySub.someOtherMethod();*/

	/*하지만 상속은 단방향으로 일어난다는 점을 알고 있어야 한다.
	Sub클래스 입장에서는 Super클래스와의 관계가 분명하지만, Super클래스 입장에서는 자신을 상속받은
	클래스가 무엇인지 전혀 알지 못한다.*/
	//Super mySuper;
	//mySuper.someOtherMethod(); //오류!

	//상속으로 구성된 클래스 객체를 사용하는 입장에서는 그 객체가 자식 클래스 타입으로도 보이고
	//부모 클래스 타입으로도 보인다.

	//Super* superPointer = new Sub(); //Sub 타입 객체를 생성하여 Super 타입 포인터 변수에 저장
	//하지만 Super 타입 포인터로는 Sub 타입에 정의된 메서드 호출이 불가능
	//superPointer->someOtherMethod(); //오류!

	//오버라이딩에 따른 메서드 호출
	/*Super mySuper;
	mySuper.someMethod();

	Sub mySub;
	mySub.someMethod();*/

	////오버라이딩 기능은 베이스 클래스에서 해당 메서드의 
	////virtual키워드를 빠뜨릴 경우 올바르게 작동하지 않는다.
	//Sub mySub;
	////Super클래스 타입 이지만 Sub를 타입 객체를 가리키고 있음
	//Super& ref = mySub;
	//ref.someMethod(); //Sub에서 오버라이딩된 someMethod() 호출

	///*포인터나 참조가 베이스 클래스 타입이면 실제 가리키는 객체가
	//파생 클래스라 하더라도 파생 클래스에만 정의된 멤버나 메서드에는 
	//접근할 수 없다는 점을 기억하자.
	//*/
	//mySub.someOtherMethod();
	//ref.someOtherMethod(); //오류!

	/*이렇게 객체 스스로 자신이 생성된 클래스를 기억해서 자신을 가리키는
	클래스 타입과 관계없이 메서드 오버라이딩을 반영하는 동작은
	**포인터나 참조형 변수에서만 발생한다.** 객체 간 타입 캐스팅이나 대입을
	통해 객체가 변경되는 경우에는 원본 객체의 클래스 정보가 기억되지 않는다.*/
	//Sub mySub;
	//Super assignedObject = mySub;
	//assignedObject.someMethod(); //Super클래스 someMethod()가 불림
	/*이러한 동작 방식은 다소 혼란스럽기 때문에 이것을 가장 쉽게 이해하는 방법은
	메모리에 객체가 할당 된 상태를 생각해보는 것이다. Sub객체는 Super객체보다 메모리 영역을
	조금 더 많이 차지한다. Sub만의 특성을 추가로 가지고 있기 때문이다. 포인터나 참조로 Sub객체를
	가리키고 있을 때 그 타입이 Super라 하더라도 메모리를 차지하고 있는 크기는 변하지 않는다.
	즉, Super 타입으로 참조하고 있어도 그 객체인 Sub의 특징들은 메모리에 유지된다. 반면 Sub객체를
	Super객체로 캐스팅하면 Sub객체만의 특징이 없어지고 Super 객체로서의 데이터만 복제된다.
	즉, 차지하고 있는 메모리 크기가 Sub에서 Super로 작아진다..
	
	*파생 클래스에서 오버라이딩하는 메서드들은 베이스 클래스 타입의 포인터나 참조로 접근되더라도
	그대로 유지된다. 하지만 베이스 클래스로 객체가 캐스팅되면 오버라이딩된 메서드들이 없어진다.
	이렇게 파생 클래스에서 오버라이딩된 메서드 속성이 삭제되는 것을 슬라이싱(Slicing)이라고 한다.*/
	
	//Child myChild;
	
	//각 클래스에 virtual 소멸자를 정의하지 않는다면 다음과 같은 선언은
	//상속되어있는 객체의 소멸자들이 불리지 않는 현상이 일어난다.
	/*Parent* ptr = new Child();
	delete ptr;*/
	

	/*Romance novel;
	Book book;
	cout << novel.getDescription() << endl;
	cout << book.getDescription() << endl;
	cout << novel.getHeight() << endl;
	cout << book.getHeight() << endl;*/

	/*
	업캐스팅과 다운캐스팅

	업캐스팅 : 상위(부모) 클래스로 타입 캐스팅하는 것
	객체는 부모 클래스로 업캐스팅되거나 부모 클래스의 객체에
	대입할 
	수 있다.

	다운캐스팅 : 하위(자식) 클래스로 타입 캐스팅하는 것
	다운캐스팅은 일반적으로 정상 동작이 보증되지 않기 때문에 전문 개발자는 아예 사용하지 않는다.
	*/

	//캐스팅이나 대입이 일어나면 자식 클래스의 특징이 사라지는 슬라이싱이 발생한다.
	Sub mySub;
	//Super mySuper = mySub;
	//mySuper.someMethod();

	//위와 같이 객체 간 대입으로서 Sub객체를 Super객체로 업캐스팅하면 Sub의 자식
	//클래스로서의 특징들이 빠진 채 Super 객체의 값이 Sub 객체의 값으로 업데이트 된다.

	//하지만 다음과 같이 참조변수의 초기화 방식으로 업캐스팅을 하면 슬라이싱이 발생하지 않는다.
	//Super& mySuper = mySub;
	//mySuper.someMethod();
	/*
	파생 클래스의 객체를 베이스 클래스 타입으로 이용할때, 즉 업캐스팅을 할때에는 이렇게 
	참조형을 사용하는 것이 올바른 방법. 메서드나 함수에서 객체를 이용해야 할 때는 사용할
	클래스 타입으로 직접 접근해서는 안 되고 항상 참조형으로 접근해야 한다. 그렇게 해야 
	슬라이싱을 피하고 파생 클래스의 객체를 그대로 사용할 수 있다.
	
	WARNING_ 베이스 클래스로 업캐스팅을 할 때는 포인터 또는 참조를 이용하여 슬라이싱이 
	발생하지 않도록 한다.
	*/
	
	/*다운 캐스팅이 필요한 경우도 있다. 단, 전체 이용 환경을 모두 통제 할 수 있어야 한다.
	다운 캐스팅을 꼭 써야 한다면 dynamic_cast를 이용해야 한다. static_cast와 달리
	dynamic_cast는 객체에 저장된 정보를 이용하여 해당 캐스팅이 적합한지 런타임에 검사하여
	문제가 있으면 캐스팅을 거부하고 에러를 발생 시킨다. 캐스팅 실패가 포인터 변수에 대해 발생하면
	무의미한 객체를 가리키는 대신 포인터 값이 nullptr이 된다. 참조형에 대해선 std::bad_cast이 된다.*/
	

	/*추상 클래스*/
	/*순수 가상 함수가 하나라도 들어간 클래스는 추상 클래스가 되므로 인스턴스화 시킬 수 없다.*/
	//SpreadsheetCell cell; //에러! 추상 클래스의 인스턴스를 생성하려 했다.

	SpreadsheetCell* ptr = nullptr; //다음은 컴파일이 가능하다.
	ptr = new StringSpreadsheetCell(); //나중에 파생 클래스를 인스턴스화 하면서 초기화 되기 때문..

	//다형성 활용의 극대화
	//SpreadsheetCell은 다형성을 가지게 되었다.

	vector<unique_ptr<SpreadsheetCell>> cellArray;
	cellArray.push_back(make_unique<StringSpreadsheetCell>());
	cellArray.push_back(make_unique<StringSpreadsheetCell>());
	cellArray.push_back(make_unique<DoubleSpreadsheetCell>());

	//SpreadsheetCell 타입의 포인터를 이용하기 때문에 컴파일러는
	//실제 객체가 어느 타입인지 전혀 알지 못한다. 하지만 이들 객체는 
	//파생 클래스이기 때문에 SpreadsheetCell에 정의된 메서드를 반드시 지원해야한다.

	cellArray[0]->set("hello");
	cellArray[1]->set("10");
	cellArray[2]->set("18");
	
	cout << "Vector values are [" << cellArray[0]->getString() << "," <<
									cellArray[1]->getString() << "," <<
									cellArray[2]->getString() << "]" <<
									endl;


	DoubleSpreadsheetCell myDbl;
	myDbl.set(8.4);
	StringSpreadsheetCell result = myDbl + myDbl;

	cout << "123 " << result.getString() << endl;

	return 0;
}

StringSpreadsheetCell operator+(const StringSpreadsheetCell& lhs,
	const StringSpreadsheetCell& rhs)
{
StringSpreadsheetCell newCell;
newCell.set(lhs.getString() + rhs.getString());
return newCell;
}
