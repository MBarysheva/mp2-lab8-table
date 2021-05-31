#pragma once
#ifndef _arraytable_h
#define _arraytable_h

#include "table.h"

#define TabMaxSize 1000

enum TDataPos { FIRST_POS, CURRENT_POS, LAST_POS };

class TArrayTable : public TTable {

protected:
	//TTabRecord *pRecs; // ������ ��� ������� �������// table memory
	int TabSize; //����������� ��������� ���������� ������� � �������// max count of records
	int CurrPos; //����� ������� ������(������� � 0)// current record numder(staring from 0)

public:
	TTabRecord* pRecs; // ������ ��� ������� �������// table memory
	TArrayTable() {
		TabSize = -1;
		pRecs = NULL;
		CurrPos = -1;
	};
	TArrayTable(int Size = TabMaxSize) {
		pRecs = new TTabRecord[Size];
		TabSize = Size;
		DataCount = CurrPos = 0;
	}
	 ~TArrayTable() {
		delete[] pRecs;
	}

	//�������������� ������// informational metods
	virtual bool IsFull() const {
		return DataCount >= TabSize;
	}

	int GetTabSize() const {
		return TabSize;
	}

	//������//access
	virtual TKey GetKey(void) const {
		return GetKey(CURRENT_POS);
	}
	virtual TValue GetValue(void) const {
		return GetValue(CURRENT_POS);
	}
	virtual TKey GetKey(TDataPos mode) const;
	virtual TValue GetValue(TDataPos mode) const;

	//���������//navigation
	virtual int Reset(void);
	virtual int IsTabEnded(void) const;
	virtual int GoNext(void);
	virtual int SetCurrentPos(int pos);
	int GetCurrentPos(void) const {
		return CurrPos;
	}

	friend class SortTable;
};
#endif