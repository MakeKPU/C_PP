#include "pch.h"
#include "SpreadsheetCell.h"


void SpreadsheetCell::setColor(Colors color)
{
	mColor = color;
}

SpreadsheetCell::SpreadsheetCell(double InitialValue)
{
	set(InitialValue);
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

void SpreadsheetCell::set(double inValue)
{
	//�̷��� �����ν� mValue�� mString�� �׻� ��ȿ�� ���� ������ �Ǿ���.
	mValue = inValue;
	mString = doubleToString(inValue);
	//�ڽ��� ���� ���빰�� ����ϰ� ���� ������ this�����ʹ� �����ϰ� ��������.
	printCell(*this);
}

//Property�� �Ű������� �̸��� ������쿡�� this�����͸� Ȱ���ϸ� ���ϴ�.
//this->inValue = inValue;

//inline
//C++������ �޼��峪 �Լ��� ������ �и��� �ڵ� ������� ȣ���ϴ� ���, 
//ȣ�� ������ �ٷ� �޼��峪 �Լ��� �ٵ� �Űܳ��� ȣ�� ������带 ���̴� ����� ������
//inlining�̶�� �Ѵ�.
//�����Ϸ��� �ζ��̴��� ������ ���ɿ� �ذ� �ȴٰ� �Ǵ��ϸ� inline Ű���带 �����Ҽ��� �ִ�.
//������ C++�����Ϸ��� inline �޼��带 ��� ���Ͽ� �������� �ʴ��� �ζ��̴��� �����ϴ�.
//�̷��� �����Ϸ��� ���ٸ� �ǵ����̸� ������ �Լ��� ���Ǻθ� �̿����� ���� cpp������ �̿��ϴ� ���� ����.
//Ŭ���� ���� �ȿ��� �ٷ� �����θ� �����ϸ� �ζ��̴��� ����ȴ�.
inline double SpreadsheetCell::getValue() const
{
	mNumAccesses++;
	return mValue;
}

inline void SpreadsheetCell::set(const std::string & inString)
{
	mString = inString;
	mValue = stringToDouble(inString);
}

const std::string & SpreadsheetCell::getString() const 
//const �޼��� : �޼��� ���� �����ϴ� ��� �����͸���� cosnt�� �����
//�׷��� ����� �����Ϸ� �� �� �����Ϸ��� ������ �߻� ��Ų��.
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	mNumAccesses++;
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

SpreadsheetCell SpreadsheetCell::add(const SpreadsheetCell & cell) const
{
	SpreadsheetCell newCell;
	newCell.set(mValue + cell.mValue); //mValue�� mString�� ����� ������Ʈ
	return newCell;
}

//SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell & cell) const
//{
//	SpreadsheetCell newCell;
//	newCell.set(mValue + cell.mValue); //mValue�� mString�� ����� ������Ʈ
//	return newCell;
//}

SpreadsheetCell SpreadsheetCell::operator+(double rhs) const
{
	return SpreadsheetCell(mValue + rhs);
}

SpreadsheetCell & SpreadsheetCell::operator+=(const SpreadsheetCell & rhs)
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	set(mValue + rhs.mValue);
	return *this;
}

SpreadsheetCell & SpreadsheetCell::operator-=(const SpreadsheetCell & rhs)
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	set(mValue - rhs.mValue);
	return *this;
}

SpreadsheetCell & SpreadsheetCell::operator*=(const SpreadsheetCell & rhs)
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	set(mValue * rhs.mValue);
	return *this;
}

SpreadsheetCell & SpreadsheetCell::operator/=(const SpreadsheetCell & rhs)
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	if (rhs.mValue == 0)
		throw invalid_argument("Divide by zero.");
	set(mValue / rhs.mValue);
	return *this;
}

//#include <mutex>
std::string SpreadsheetCell::doubleToString(double inValue)
{
	//Automatically unlock
	/*mutex a;
	lock_guard<mutex> lockM{ a };*/
	//_asm mfence;


	ostringstream ostr;
	ostr << inValue;
	return ostr.str();
}

double SpreadsheetCell::stringToDouble(const std::string & inString)
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

bool checkSpreadsheetCell(const SpreadsheetCell & cell)
{
	return !(cell.mString.empty());
}

SpreadsheetCell operator+(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue + rhs.mValue); //mValue�� mString ����� ������Ʈ�Ѵ�.
	return newCell;
}

SpreadsheetCell operator-(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue - rhs.mValue); //mValue�� mString ����� ������Ʈ�Ѵ�.
	return newCell;
}

SpreadsheetCell operator*(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue * rhs.mValue); //mValue�� mString ����� ������Ʈ�Ѵ�.
	return newCell;
}

SpreadsheetCell operator/(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	if (rhs.mValue == 0)
		throw invalid_argument("Divide by zero.");
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue / rhs.mValue); //mValue�� mString ����� ������Ʈ�Ѵ�.
	return newCell;
}

bool operator==(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	return (lhs.mValue == rhs.mValue);
}

bool operator>(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	return (lhs.mValue > rhs.mValue);
}

bool operator<(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	return (lhs.mValue < rhs.mValue);
}

bool operator!=(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	return (lhs.mValue != rhs.mValue);
}

bool operator>=(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	return (lhs.mValue >= rhs.mValue);
	//Ȥ��
	//return !(lhs < rhs);
}

bool operator<=(const SpreadsheetCell & lhs, const SpreadsheetCell & rhs)
{
	return (lhs.mValue <= rhs.mValue);
	//Ȥ��
	//return !(lhs > rhs);
}
