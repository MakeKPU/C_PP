#pragma once
#include "SpreadsheetCell.h"

//�߻� Ŭ�����̱� ������ �����ΰ� ���ų� �����⸸ ���°� ��κ��̴�.

class DoubleSpreadsheetCell;
class StringSpreadsheetCell : public SpreadsheetCell
{
	//�߻� Ŭ������ ��ӹ�����
	//�� ��ӹ��� �ڽ� Ŭ������ �߻� Ŭ������ �ִ� ��� ���� ���� �Լ��� �������� ��� �����ؾ� �Ѵ�.
	//�������� �ʴ´ٸ� �� Ŭ������ �߻� Ŭ������ �Ǿ� ������ �ν��Ͻ�ȭ�� �Ұ���������.
public:
	StringSpreadsheetCell();
	//���ռ��� ���� doubleŸ�� ���� string Ÿ�� ���� ��ȣ ��ȯ�� �� �ְ� �Ϸ��� 
	//������ �� Ÿ���� ���ڷ� ������ �����ڸ� �߰��ؾ� �Ѵ�. 
	//���� �����ڿ� ����� �������� ���� Ŭ������ ���� ���ڸ� �޴´�.
	StringSpreadsheetCell(const DoubleSpreadsheetCell& inDoubleCell);
	virtual ~StringSpreadsheetCell();
	virtual void set(const std::string& inString) override;
	virtual const std::string getString() const override;
private:
	std::string mValue;
};

