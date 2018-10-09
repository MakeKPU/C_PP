#pragma once

class MyClass
{
public:
	void foo(int i);
	//foo 메서드 수행시 원치 않는 타입 캐스팅을 방지 하고 싶을때에는 delete를 붙여준다.
	//이러면 컴파일러에서 걸러준다.
	void foo(double i) = delete;
};