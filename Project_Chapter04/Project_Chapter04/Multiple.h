#pragma once
#include "pch.h" 

/*
���� ���
	*DogBird�� Dog�� Bird��ü�� �θ�� �������ִ�.
	*DogBird�� Dog�� Bird��ü�� public�� protected �����͸���� �޼��带 �����Ѵ�.
	*DogBird�� Dog�� Bird�� ��ĳ������ �����ϴ�.
	*DogBird��� ���ο� ��ü�� �����Ҷ� ��� ���� ������ ����Ŭ������ ����Ʈ�����ڰ� ���ʴ�� �Ҹ���.
	*�Ҹ��ڴ� ������ ȣ���� �������� ȣ��
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
	using Dog::eat; //��������� Dog������ eat()�� ���
	void ead() { Dog::eat(); }//��������� Dog��ü�� eat �޼��� ȣ��
};

/*
Ŭ���� �ι� ��� << ��ȣ�� �߻�
class Dog{};
class Bird : Public Dog {};
class DogBird : public Bird, public Dog {}; //����! DogŬ������ ��ȣ��
*/

/*
	int main()
	{
		DogBird myConfusedAnimal;
		myConfusedAnimal.eat(); //����! ��ȣ�� �޼����� eat()�� ȣ���ߴ�.
		//������ ������ ���� �����ڳ� ��ĳ������ �Ѵٸ� ������ ���� �ʴ´�.
		static_cast<Dog&>(myConfusedAnimal).eat(); //�����̽�
		myConfusedAnimal.Dog::eat();			   //��������� ȣ��
		
		return 0;
	}
*/
