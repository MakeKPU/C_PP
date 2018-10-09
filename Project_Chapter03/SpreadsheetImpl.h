#pragma once
#include "SpreadsheetCell.h"

//Spreadsheet�� SpreadsheetApplication �� Ŭ���� ��� ���ǵǾ� �־
//���� ������ �� �־�� �Ѵ�.
//�̷� ������ #include�δ� �ذ��� ����� ����.
//�׷��� ������ ������ �ʿ��ϴ�.
//���� �����Ǵ� Ŭ������ ��� ���� �� ��� ���ʿ� ����� Ŭ������ ��� ������ 
//��Ŭ��� �ϴ� ��� ������ ������ �صθ� �����Ϸ��� ���߿� �ش� ���Ǹ� ã�Ƽ� Ÿ�� ��Ī�� �Ѵ�.
class SpreadsheetApplication; //������ ����
class SpreadsheetImpl
{
public:
	//��ø�� Ŭ������ ������ Ŭ�����϶��� �����Ѵ�.
	//�ֳ��ϸ� �ڵ尡 ������������ �����̴�.
	class TestClass
	{
	public:
		int getNum();
	private:
		int mNum = 10;
	};
public:
	//friend������ ������ ������ Ŭ���������� �� �� �ִ�. 
	//��, �ٸ� Ŭ������ ���� ���� ������ ��û�ϴ� Ŭ���� �Ǵ� �޼���, �Լ� ������
	//�ٸ� Ŭ������ friend ������ �� ���� ����.
	//friend void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& cell);
public:
	SpreadsheetImpl() = default;
	//����Ʈ �Ķ����
	//��� �Ķ���Ϳ� ���� ����Ʈ���� �����Ǿ��ٸ�,
	//�ƹ��� ���� ���� ��ü�� �����ڸ� ȣ���� �� �ְ� �ȴ�.
	//������ �̷��� �ϸ� ��ü ���� �� �����Ϸ��� ��� �޼��带 �̿��ؾ� ���� 
	//�� �� �����Ƿ� ���� �޽����� �߻��Ѵ�.
	SpreadsheetImpl(const SpreadsheetApplication& theApp,
		int inWidth = kMaxWidth, 
		int inHeight = kMaxHeight);
	//�޸��Ҵ����� ���� ���� �����ڳ� ���� ������ ������ �߻��ϴ� ������ ���ϴ� �����
	//���� �����ڿ� ���� �����ڸ� �����ϴ� ���̴�. (���Ǻ� �ڿ� = delete�� ���δ�.)
	//���� �����Ѵٸ� �����̳� ������ ���� �۾��� �����Ϸ����� �ɷ��ش�.
	//Ȥ�� ���� �����ڸ� private���� ������ �ȴ�.
	//���� ������
	SpreadsheetImpl(const SpreadsheetImpl& src);
	//���� ������
	SpreadsheetImpl& operator=(const SpreadsheetImpl& rhs);
	~SpreadsheetImpl();
public:
	void setCellAt(int x, int y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(int x, int y);
	//���� �����ڿ� ���� �����ڸ� ���� ���� ���� ��ƾ
	void copyFrom(const SpreadsheetImpl& src);
	int getId() const;
private:
	bool inRange(int val, int upper);
	int mWidth, mHeight;
	SpreadsheetCell** mCells;
private:
	//static ������ �ɹ�
	//C�� global ������ ���������� Ư�� Ŭ������ ���ӵȴ�.
	//Ŭ���� �ȿ��� �����ϴ� ������ ������ �ʰ� ������ �ҽ����� �ȿ��� �ٽ� �ѹ� �����ؾ���
	//static ��� ������ �Ϲ� ������ �ٸ��� �ڵ����� 0�̳� nullptr�� �ʱ�ȭ �ȴ�.
	//public���� ���� ������ ����ÿ��� Ŭ���� �޼��� �ۿ����� ������ �����ϴ�.
	//������ ���̴� ����� public���� �����Ͽ� �ܺο� �����Ű�� ���� �ٶ������� �ʱ� ������ 
	//getter setter�� ����ϴ°� �ٶ����ϴ�.
	static int sCounter;
	int mId;
public:
	//public�̱� ������ ��𼭵� ������ �����ϴ�.
	//const ������ ���
	static const int kMaxHeight = 100;
	static const int kMaxWidth = 100;
private:
	//Spreadsheet ��ü�� �׻� SpreadsheetApplication ��ü�� ������ ���̱� ������ 
	//�����ͺ��ٴ� �������� ����ϴ� ���� �ٶ�������.
	//�����Ϳ� �޸� �������� ������ ��ü�� �ʱ�ȭ�Ǿ�� ������ �� �ֱ� ������ �ξ� �����ϴ�.
	//������ ������ const�� �ƴϳĿ� ���� ū ���̰� �ִ�. const �� ������ ������ ������
	//SpreadsheetApplication ������ ����� SpreadsheetApplication ��ü�� ���� const �޼��常 ȣ�Ⱑ���ϴ�.
	//���� �׷��� ������ ������ ������ ����.
	const SpreadsheetApplication& mTheApp;
};

