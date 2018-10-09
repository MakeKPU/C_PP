#pragma once
#include <string>
//definition of Class
class SpreadsheetCell
{
	//���������ڸ� ����ڰ� �������� ���� Default ���������ڴ� Private �����̴�.

//�������� ���� ���� �����ڵ鿡 ���� �׸���� �׷����� �����ϴ� ���� ����.
public:
	//������� �����ؾ� �Ѵٸ� #define ��� ���� Ÿ���� �̿��ϴ� ���� ����.
	enum class Colors { Red = 1, Green, Blue, Yellow };
	void setColor(Colors color);
public:
	//friend class
	//�̷��� �����ϸ� Spreadsheet�� ��� �޼���� SpreadsheetCell�� private�� protected
	//���/�޼��忡 �����Ӱ� ������ �� �ְ� �ȴ�.
	friend class Spreadsheet;
private:
	//friend�� Ȱ�� ����, SpreadsheetCell�� ���ڿ��� ������ �ƴ��� �����ϴ� �Լ��� Ŭ���� �ܺο�
	//���������� �ΰ� ���� �� �ִ�. ���ڿ��� �����ϱ� ���ؼ��� SpreadsheetCell�� ���ε����Ϳ� 
	//������ �� �־�� �ϹǷ� �ش� ���� �Լ� checkSpreadsheetCell()�� ������ ���� SpreadsheetCell
	//Ŭ���� ���ǿ��� friend�� �����Ѵ�.
	friend bool checkSpreadsheetCell(const SpreadsheetCell& cell);
	/*frient�� ����Ǳ� ����. friend�� �̿��ϸ� ���� ������ �ٸ� Ŭ������ �Լ��� �����Ű�� ������ �߻�ȭ ��Ģ��
	�Ѽյȴ�. �׷��Ƿ� ������ �����ε��� ���� �Ұ����� ��Ȳ������ �̿��ϴ� ���� �ٶ����ϴ�.*/
public:
	//����Ʈ �����ڸ� �����Ͽ� �����ڰ� ���� ���ǵ��� ���� Ŭ������ ������� delete�� ����
	//SpreadsheetCell() = delete;

	SpreadsheetCell() = default; //����Ʈ �����ڸ� �����ϴ� ���ο� ���! default�� ���¼��� �� �����ڰ� �⺻�̵�
	SpreadsheetCell(double InitialValue);
	/*explicit*/ SpreadsheetCell(const std::string& initialValue);
	~SpreadsheetCell();

	//�޼��� �����ε�
	//�Ķ���Ͱ� ���� ���� Ÿ�Ը� �ٸ� �޼��峪 �Լ��� ���� �����ε��� ������� ����
	//set�� �޼��� �����ε� �Ͽ� �θ�
	void set(double inValue);
	//��ü�� Property ������ ���� Method�� const�� �����ϴ� ���� �ٶ����ϴ�.
	//const ����� Property ���� �Ұ�
	double getValue() const;
	//�ؽ�Ʈ�� ����
	void set(const std::string& inString);
	const std::string& getString() const;
	//
	void printCell(const SpreadsheetCell& inCell);
public:
	//���� ������ ����
	//default�� delete���� ����� ������ ����
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
	
	//������� ����
	//ù��° : add �޼���
	SpreadsheetCell add(const SpreadsheetCell& cell) const;
	//�ι�° : operator+�� �����ε�
	//�Ϲ����� �����ε�
	//�̰� ������ ��ü�� �ƴϸ� ���� �Ұ�!
	//SpreadsheetCell operator+(const SpreadsheetCell& cell) const;
	//�ӽ� ��ü ���� ���̴� ��
	SpreadsheetCell operator+(double rhs) const;
	//operator�� ��ȯ��Ģ�� �������� �ʱ� ������ ���� ���ǰ� �ʿ��ϴ�.
	//���� �Լ� operator+�� SpreadsheetCellŬ������ proteced ����� �����ؾ� 
	//�ϱ� ������ friend�� ����Ǿ�� �Ѵ�.
	//������ �����ε��� �� ����� ���� ������ �� �ֵ��� �����ϴ� ���� �ٶ����ϴ�.
	
	//������
	//������ �ڱ� �ڽ��� operator�� lhs�� ���� ������ ������ �Ű������� �ΰ��޴� operator�� 
	//Ŭ���� ���� ������ �Ұ����ϱ� ������ friend�� ����Ͽ� ������ ���������� ���� �޼��带 �����Ѵ�.
	friend SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);

	//��� ������ ���� �ʹٸ� �ڵ����� ��õ��� �ʱ� ������ ��ø� ������Ѵ�.
	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);

	//�񱳿�����
	//tup : �ε� �Ҽ����� �񱳴� �۽Ƿ� �� �񱳸� ��������.
	friend bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);

	//������ �����ε��� Ŭ���� ����ڸ� ���� ���� �������� �����Ѵ�.
private:
	//doubleToString�� stringToDouble�� ��ü�� ���ӵǴ� �κ��� ����.
	//���� static���� �����ص� �ȴ�.
	//�� �� �޼���� ��ü �����Ϳ� ������ ���� �����Ƿ� const�� �ٿ�����
	//static�޼��忡���� �����Ѵ�. �ֳ��ϸ� static �޼���� ��ü�� ������ �ʱ� ������
	//��ü�� ������ ������ �ʴ´ٴ� �ø�ƽ�� �� �̻� ����� �� ���� �����̴�.
	//static�޼���� ����� ��ü�� �����Ƿ� this�����͵� ����� �Ұ����ϴ�.
	//(��, static �����͸ɹ��� �̿��� �����ϴ�)
	static std::string doubleToString(double inValue);
	static double stringToDouble(const std::string& inString);
private:
	//�������� �������
	double mValue = 0.0; //Ŭ���� �� ��� �ʱ�ȭ.
	std::string mString;
	//mutable
	//mutable�Ӽ��� ���� ī���� ��� ������ �����ϸ� �����Ϸ��� �ش� ������
	//������ �޼����� const�� ������ ��ġ�� �ʴ� ������ �����Ѵ�.
	mutable int mNumAccesses = 0;
	Colors mColor = Colors::Red;
};
//���� �ٴ� �����ݷ��� �� �ٿ��� �Ѵ� 
//���� ������ �ʴ´ٸ� �����Ϸ����� ��û�� ������ �� �� �ִ�.

