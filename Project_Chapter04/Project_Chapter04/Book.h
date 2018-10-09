#pragma once
#include "pch.h"

class Book
{
public:
	virtual ~Book() {}
	virtual string getDescription() const { return "Book"; }
	virtual int getHeight() const { return 120;}
};
class Paperback : public Book
{
public:
	virtual string getDescription() const override
	{
		return "Paperback " + Book::getDescription();
	}
};
class Romance : public Paperback
{
public:
	virtual string getDescription() const override
	{
		return "Romance " + Paperback::getDescription();
	}
	virtual int getHeight() const override
	{
		return Paperback::getHeight() / 2;
		/*스코스 지정 연산자로 Paperback을 지정하더라도 Paperback은 getHeight()를
		오버라이딩하고 있지 않기 때문에 상위 계층을 뒤져서 처음 만나는 getHeight()
		메서드를 호출한다.*/
	}
};
class Technical : public Book
{
public:
	virtual string getDescription() const override
	{
		return "Technical " + Book::getDescription();
	}
};
