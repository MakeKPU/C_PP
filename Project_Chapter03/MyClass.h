#pragma once

class MyClass
{
public:
	void foo(int i);
	//foo �޼��� ����� ��ġ �ʴ� Ÿ�� ĳ������ ���� �ϰ� ���������� delete�� �ٿ��ش�.
	//�̷��� �����Ϸ����� �ɷ��ش�.
	void foo(double i) = delete;
};