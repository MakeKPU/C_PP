#include "pch.h"
#include "SpreadsheetImpl.h"

//스코프 지정 연산자를 사용하여 초기화
int SpreadsheetImpl::sCounter;

SpreadsheetImpl::SpreadsheetImpl(const SpreadsheetApplication& theApp,
	int inWidth,
	int inHeight) :
	//mWidth(inWidth), mHeight(inHeight)
	mWidth(inWidth < kMaxWidth ? inWidth : kMaxWidth),
	mHeight(inHeight < kMaxHeight ? inHeight : kMaxHeight), mTheApp(theApp)
	//가로와 세로 크기가 허용 범위를 넘어설 때 최대값에 강제로 맞추는 대신
	//익셉션을 발생시킬 수도 있다. 그런데 생성자 안에서 익셉션을 발생시키면
	//**소멸자가 불리지 않는** 문제가 있기 때문에 조심해서 사용해야 한다. 
{
	mId = sCounter++;
	mCells = new SpreadsheetCell*[mWidth];
	for (int i = 0; i < mWidth; i++)
	{
		mCells[i] = new SpreadsheetCell[inHeight];
	}
}

SpreadsheetImpl::SpreadsheetImpl(const SpreadsheetImpl & src) :
	//복제 생성자도 잊지 말고 초기화해야 한다. 원본이 가진 SpreadsheetApplication
	//객체로 mTheApp 참조형 멤버를 초기화한다.
	mTheApp(src.mTheApp)
{
	//mWidth = src.mWidth;
	//mHeight = src.mHeight;
	////객체 생성을 위한 복제 생성자이기 때문에
	////이 코드가 실행되는 시점에는 mCell가 할당된 적이 없기 때문에
	////할당전에 mCell메모리 해제를 할 필요가 없다.
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
	// TODO: 여기에 반환 구문을 삽입합니다.
	//자기 자신을 대입하는지 검사
	if (this == &rhs)
		return *this;

	//기존에 사용하던 메모리 반환
	for (int i = 0; i < mWidth; i++)
	{
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;

	//새로운 메모리를 할당하고 값을 복제
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
	// TODO: 여기에 반환 구문을 삽입합니다.
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

//중첩 클래스
//이런식으로 하면 더 편하게 사용가능
using SCell = SpreadsheetImpl::TestClass;

int SCell::getNum()
{
	return mNum;
}
