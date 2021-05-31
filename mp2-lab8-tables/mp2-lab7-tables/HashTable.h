#pragma once
#ifndef _HASHTAB_H_
#define _HASHTAB_H_
#include "Table.h"
#define TabMaxSize 10000

class HashTable : public TTable
{
protected:
	virtual unsigned int HashFunck(const TKey key);
public:
	HashTable():TTable(){}
};
#endif