#pragma once
#ifndef _ARRAYHASH_
#define _ARRAYHASH_
#include"HashTable.h"
#define TabHashStep 2

class TArrayHashTable : public HashTable
{
protected:
	TTabRecord* pRecs;// память для таблицы
	int TabSize;//максимально возможный размер таблицы
	int HashStep;//шаг вторичного перемешивания
	int FreePos;//первая свободнаяя строка, обнаруженная при поиске
	int CurrPos;//строка памяти при завершении поиска 
	TTabRecord Mark;//маркер для индикации строк с удалёнными записями
	TTabRecord Empty;//маркер для индикации не занятых строк 
	int GetNextPos(int pos) { return (pos + HashStep) % TabSize; }// функция открытого перемешивания
public:
	TArrayHashTable(int size = TabMaxSize, int step = TabHashStep);
	virtual ~TArrayHashTable();
	virtual bool IsFull() const { return DataCount >= TabSize; };//заполнена
	//основные методы
	virtual bool FindRecord(TKey k);
	virtual int InsRecord(TKey k, TValue val);
	virtual int DelRecord(TKey k);
	//навигация
	virtual int Reset(void);
	virtual int IsTabEnded(void) const;
	virtual int GoNext(void);
	//доступ
	virtual TKey GetKey(void) const;
	virtual TValue GetValue(void) const;
};
#endif
