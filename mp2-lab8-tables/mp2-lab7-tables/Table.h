#pragma once
#ifndef _table_h
#define _table_h

#include <iostream>
#include "record.h"

#define TabOK        0 //ошибок нет
#define TabEmpty  -101 // таблица пуста
#define TabFull   -102 // таблица полна
#define TabNoRec  -103 // нет записей
#define TabRecDbl -104 // дублирование записи
#define TabNoMem  -105 // нет памяти

#define TabMaxSize 25

using namespace std;

class TTable {

protected:
	int DataCount;  //количество записей
	int Efficiency; //показатеь ээфективности выполнения операций

public:
	TTable() { DataCount = 0; Efficiency = 0; }
	virtual ~TTable() { };

	//методы
	int GetDataCount() const { return DataCount; } 
	int GetEfficiency() const { return   Efficiency; }
	void ClearEfficiency() { Efficiency = 0; }
	int IsEmpty() const { return DataCount == 0; }
	virtual bool IsFull() const = 0;

	//методы
	virtual bool FindRecord(TKey k) = 0;
	virtual int InsRecord(TKey k, TValue pVal) = 0;
	virtual int DelRecord(TKey k) = 0;

	//навигация
	virtual int Reset(void) = 0;
	virtual int IsTabEnded(void) const = 0;
	virtual int GoNext(void) = 0;

	//доступ
	virtual TKey GetKey(void) const = 0;
	virtual TValue GetValue(void) const = 0;

	//печать 
	friend ostream& operator<<(ostream& os, TTable& tab) {
		cout << "Table printing" << endl;
		for (tab.Reset(); !tab.IsTabEnded(); tab.GoNext()) {
			os << " Key: " << tab.GetKey() << " Val: " << tab.GetValue() << endl;
			tab.Efficiency++;
		}
		return os;
	}
};
#endif