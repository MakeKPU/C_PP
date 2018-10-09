#pragma once
#include "pch.h"

class SpreadsheetCell
{
	/*
	ǻ����߾� �޼��� Pure virtual method(���� ���� �޼���)�� Ŭ������ ������ �� 
	���� �ϰ� ������ ���Ǵ� ���� �ʴ� �޼��带 ���Ѵ�. �޼��带 ǻ�� ���߾�� �����ϸ�
	�����Ϸ��� �� �޼��尡 ����� Ŭ�������� �޼��� �����θ� ã�� �ʴ´�. �� ������
	ǻ�� ���߾� �Լ��� ���� Ŭ������ �ν��Ͻ�ȭ �� �� �����Ƿ� �߻� Ŭ������� �θ���.
	Ŭ������ ǻ�� ���߾� �޼��带 �ϳ��� ������ ������ �����Ϸ��� ���� �ش� Ŭ������
	��ü ������ �����ȴ�.
	*/
public:
	SpreadsheetCell() {};
	virtual ~SpreadsheetCell() {};
	virtual void set(const std::string& inString) = 0; //=0 �� �ٿ� ���� ���� �޼��带 ����
	virtual const std::string getString() const = 0;  //�̷��� �޼��� ���Ǹ� ������ �ʿ䰡 ����.
//protected:
//	static std::string doubleToString(double inValue);
//	static double stringToDouble(const std::string& inString);
//	double mValue = 0.0;
//	std::string mString;
};


