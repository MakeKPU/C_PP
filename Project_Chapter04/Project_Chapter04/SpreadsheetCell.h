#pragma once
#include "pch.h"

class SpreadsheetCell
{
	/*
	퓨어버추얼 메서드 Pure virtual method(순수 가상 메서드)는 클래스를 정의할 때 
	선언만 하고 구현부 정의는 하지 않는 메서드를 말한다. 메서드를 퓨어 버추얼로 선언하면
	컴파일러가 그 메서드가 선언된 클래스에서 메서드 구현부를 찾지 않는다. 이 때문에
	퓨어 버추얼 함수를 가진 클래스는 인스턴스화 할 수 없으므로 추상 클래스라고 부른다.
	클래스가 퓨어 버추얼 메서드를 하나라도 가지고 있으면 컴파일러에 의해 해당 클래스의
	객체 생성이 금지된다.
	*/
public:
	SpreadsheetCell() {};
	virtual ~SpreadsheetCell() {};
	virtual void set(const std::string& inString) = 0; //=0 을 붙여 순수 가상 메서드를 정의
	virtual const std::string getString() const = 0;  //이러면 메서드 정의를 구현할 필요가 없다.
//protected:
//	static std::string doubleToString(double inValue);
//	static double stringToDouble(const std::string& inString);
//	double mValue = 0.0;
//	std::string mString;
};


