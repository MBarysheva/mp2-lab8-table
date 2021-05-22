#pragma once
#include "TTable.h"
class TArrayTable : public TTable
{
protected:
	TRecord* pRec;
	int size;
	int DataCount;
	int Curr;
public:
	TArrayTable(int _size = 100) : TTable(DataCount = 0)
	{
		pRec = new TRecord[_size];
		size = _size;
	}
};
