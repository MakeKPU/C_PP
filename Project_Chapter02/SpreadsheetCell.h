#pragma once

//definition of Class
class SpreadsheetCell
{
	//���������ڸ� ����ڰ� �������� ���� Default ���������ڴ� Private �����̴�.

//�������� ���� ���� �����ڵ鿡 ���� �׸���� �׷����� �����ϴ� ���� ����.
public:
	//����Ʈ �����ڸ� �����Ͽ� �����ڰ� ���� ���ǵ��� ���� Ŭ������ ������� delete�� ����
	//SpreadsheetCell() = delete;

	SpreadsheetCell();// = default; //����Ʈ �����ڸ� �����ϴ� ���ο� ���! default�� ���¼��� �� �����ڰ� �⺻�̵�
	SpreadsheetCell(double InitialValue);
	SpreadsheetCell(const std::string& initialValue);
	~SpreadsheetCell();

	void setValue(double inValue);
	//��ü�� Property ������ ���� Method�� const�� �����ϴ� ���� �ٶ����ϴ�.
	//const ����� Property ���� �Ұ�
	double getValue() const;
	//�ؽ�Ʈ�� ����
	void setString(const std::string& inString);
	const std::string& getString() const;
	//
	void printCell(const SpreadsheetCell& inCell);
	//���� ������ ����
	//default�� delete���� ����� ������ ����
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
private:
	//�������� �������
	std::string doubleToString(double inValue) const;
	double stringToDouble(const std::string& inString) const;
	double mValue = 0.0; //Ŭ���� �� ��� �ʱ�ȭ.
	std::string mString;
};
//���� �ٴ� �����ݷ��� �� �ٿ��� �Ѵ� 
//���� ������ �ʴ´ٸ� �����Ϸ����� ��û�� ������ �� �� �ִ�.

