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
		/*���ڽ� ���� �����ڷ� Paperback�� �����ϴ��� Paperback�� getHeight()��
		�������̵��ϰ� ���� �ʱ� ������ ���� ������ ������ ó�� ������ getHeight()
		�޼��带 ȣ���Ѵ�.*/
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
