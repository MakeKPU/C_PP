#include "pch.h"
#include "SpreadsheetImpl.h"

//������ ���� �����ڸ� ����Ͽ� �ʱ�ȭ
int SpreadsheetImpl::sCounter;

SpreadsheetImpl::SpreadsheetImpl(const SpreadsheetApplication& theApp,
	int inWidth,
	int inHeight) :
	//mWidth(inWidth), mHeight(inHeight)
	mWidth(inWidth < kMaxWidth ? inWidth : kMaxWidth),
	mHeight(inHeight < kMaxHeight ? inHeight : kMaxHeight), mTheApp(theApp)
	//���ο� ���� ũ�Ⱑ ��� ������ �Ѿ �� �ִ밪�� ������ ���ߴ� ���
	//�ͼ����� �߻���ų ���� �ִ�. �׷��� ������ �ȿ��� �ͼ����� �߻���Ű��
	//**�Ҹ��ڰ� �Ҹ��� �ʴ�** ������ �ֱ� ������ �����ؼ� ����ؾ� �Ѵ�. 
{
	mId = sCounter++;
	mCells = new SpreadsheetCell*[mWidth];
	for (int i = 0; i < mWidth; i++)
	{
		mCells[i] = new SpreadsheetCell[inHeight];
	}
}

SpreadsheetImpl::SpreadsheetImpl(const SpreadsheetImpl & src) :
	//���� �����ڵ� ���� ���� �ʱ�ȭ�ؾ� �Ѵ�. ������ ���� SpreadsheetApplication
	//��ü�� mTheApp ������ ����� �ʱ�ȭ�Ѵ�.
	mTheApp(src.mTheApp)
{
	//mWidth = src.mWidth;
	//mHeight = src.mHeight;
	////��ü ������ ���� ���� �������̱� ������
	////�� �ڵ尡 ����Ǵ� �������� mCell�� �Ҵ�� ���� ���� ������
	////�Ҵ����� mCell�޸� ������ �� �ʿ䰡 ����.
	//mCells = new SpreadsheetCell*[mWidth];
	//for (int i = 0; i < mWidth; i++)
	//{
	//	mCells[i] = new SpreadsheetCell[mHeight];
	//}
	//
	//for (int i = 0; i < mWidth; i++)
	//{
	//	for (int j = 0; j < mHeight; j++)
	//	{
	//		mCells[i][j] = src.mCells[i][j];
	//	}
	//}
	mId = sCounter++;
	copyFrom(src);
}

SpreadsheetImpl & SpreadsheetImpl::operator=(const SpreadsheetImpl & rhs)
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	//�ڱ� �ڽ��� �����ϴ��� �˻�
	if (this == &rhs)
		return *this;

	//������ ����ϴ� �޸� ��ȯ
	for (int i = 0; i < mWidth; i++)
	{
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;

	//���ο� �޸𸮸� �Ҵ��ϰ� ���� ����
	copyFrom(rhs);
	return *this;
}

SpreadsheetImpl::~SpreadsheetImpl()
{
	for (int i = 0; i < mWidth; i++)
	{
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
}

void SpreadsheetImpl::setCellAt(int x, int y, const SpreadsheetCell & cell)
{
	if (!inRange(x, mWidth) || !inRange(y, mHeight))
	{
		throw out_of_range("");
	}
	mCells[x][y] = cell;
}

SpreadsheetCell & SpreadsheetImpl::getCellAt(int x, int y)
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	if (!inRange(x, mWidth) || !inRange(y, mHeight))
	{
		throw out_of_range("");
	}
	return mCells[x][y];
}

void SpreadsheetImpl::copyFrom(const SpreadsheetImpl & src)
{
	mWidth = src.mWidth;
	mHeight = src.mHeight;
	mCells = new SpreadsheetCell*[mWidth];
	for (int i = 0; i < mWidth; i++)
	{
		mCells[i] = new SpreadsheetCell[mHeight];
	}
	for (int i = 0; i < mWidth; i++)
	{
		for (int j = 0; j < mHeight; j++)
		{
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

int SpreadsheetImpl::getId() const
{
	return mId;
}

bool SpreadsheetImpl::inRange(int val, int upper)
{
	if (val > upper || val < 0)
		return false;
	else
		return true;
}

//��ø Ŭ����
//�̷������� �ϸ� �� ���ϰ� ��밡��
using SCell = SpreadsheetImpl::TestClass;

int SCell::getNum()
{
	return mNum;
}
