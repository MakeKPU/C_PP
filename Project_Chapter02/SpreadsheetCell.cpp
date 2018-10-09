#include "pch.h"
#include "SpreadsheetCell.h"

SpreadsheetCell::SpreadsheetCell()
{
	mValue = 0;
}

SpreadsheetCell::SpreadsheetCell(double InitialValue)
{
	setValue(InitialValue);
}

SpreadsheetCell::SpreadsheetCell(const std::string & initialValue) :
	//�̴ϼȶ����� ���� ������� ���� ������ ���ߴ°� ��õ
	//���� �����ڸ� ���� �ʱ�ȭ
	//mValue{ stringToDouble(initialValue) }, mString{ initialValue }

	//������ ����(delegating constructor) : ������ �ȿ��� ���� Ŭ������ �ٸ� �����ڸ� ȣ��
	//��, �̴ϼ� ������θ� ������
	SpreadsheetCell(stringToDouble(initialValue))
{
	//�ӽð�ü
	//int {3};
	//setString(initialValue);

	//���� ������ ���� �ʱ�ȭ
	mString = initialValue;
}

SpreadsheetCell::~SpreadsheetCell()
{
}

void SpreadsheetCell::setValue(double inValue)
{
	//�̷��� �����ν� mValue�� mString�� �׻� ��ȿ�� ���� ������ �Ǿ���.
	mValue = inValue;
	mString = doubleToString(inValue);
	//�ڽ��� ���� ���빰�� ����ϰ� ���� ������ this�����ʹ� �����ϰ� ��������.
	printCell(*this);
}

//Property�� �Ű������� �̸��� ������쿡�� this�����͸� Ȱ���ϸ� ���ϴ�.
//this->inValue = inValue;

double SpreadsheetCell::getValue() const
{
	return mValue;
}

void SpreadsheetCell::setString(const std::string & inString)
{
	mString = inString;
	mValue = stringToDouble(inString);
}

const std::string & SpreadsheetCell::getString() const
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	return mString;
}

void SpreadsheetCell::printCell(const SpreadsheetCell & inCell)
{
	cout << inCell.getString() << endl;
}

SpreadsheetCell & SpreadsheetCell::operator=(const SpreadsheetCell & rhs)
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	//�ڱ� �ڽ��� �����ϴ��� �˻�
	if (this == &rhs)
	{
		return *this;
	}

	mValue = rhs.mValue;
	mString = rhs.mString;

	return *this;
}

//#include <mutex>
std::string SpreadsheetCell::doubleToString(double inValue) const
{
	//Automatically unlock
	/*mutex a;
	lock_guard<mutex> lockM{ a };*/
	//_asm mfence;
	
	
	ostringstream ostr;
	ostr << inValue;
	return ostr.str();
}

double SpreadsheetCell::stringToDouble(const std::string & inString) const
{
	double temp;
	istringstream istr(inString);
	istr >> temp;
	if (istr.fail() || !istr.eof())
	{
		return 0;
	}
	return temp;
}

