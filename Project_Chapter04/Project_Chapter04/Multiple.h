#pragma once
#include "pch.h" 

/*
다중 상속
	*DogBird는 Dog와 Bird객체를 부모로 가지고있다.
	*DogBird는 Dog와 Bird객체의 public과 protected 데이터멤버와 메서드를 지원한다.
	*DogBird는 Dog나 Bird로 업캐스팅이 가능하다.
	*DogBird라는 새로운 객체를 생성할때 상속 선언 순으로 상위클래스의 디폴트생성자가 차례대로 불린다.
	*소멸자는 생성자 호출의 역순으로 호출
*/
class Dog
{
public:
	virtual void bark() { cout << "Woof!" << endl; }
	virtual void eat() { cout << "The dog has eaten" << endl; }
};

class Bird
{
public:
	virtual void chirp() { cout << "Chirp!" << endl; }
	virtual void eat() { cout << "The bird has eaten" << endl; }
};

class DogBird : public Dog, public Bird
{
public:
	using Dog::eat; //명시적으로 Dog버전의 eat()를 상속
	void ead() { Dog::eat(); }//명시적으로 Dog객체의 eat 메서도 호출
};

/*
클래스 두번 상속 << 모호성 발생
class Dog{};
class Bird : Public Dog {};
class DogBird : public Bird, public Dog {}; //에러! Dog클래스가 모호함
*/

/*
	int main()
	{
		DogBird myConfusedAnimal;
		myConfusedAnimal.eat(); //에러! 모호한 메서드인 eat()를 호출했다.
		//하지만 스코프 지정 연산자나 업캐스팅을 한다면 에러가 나지 않는다.
		static_cast<Dog&>(myConfusedAnimal).eat(); //슬라이싱
		myConfusedAnimal.Dog::eat();			   //명시적으로 호출
		
		return 0;
	}
*/
