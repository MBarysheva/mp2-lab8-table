#pragma once
#ifndef _scantable_h
#define _scantable_h
//таблица, в которой все записи не упорядочены 

#include "arraytable.h"

class TScanTable : public TArrayTable {

public:

	TScanTable(int Size = TabMaxSize) : TArrayTable(Size) { };

	virtual bool FindRecord(TKey k);
	virtual int InsRecord(TKey k, TValue pVal);
	virtual int DelRecord(TKey k);
};

#endif