#pragma once

#include<iostream>
#include<fstream>
#include<algorithm>
#include<stack>
#include <string>
#include"T_Stack.h"
using namespace std;

#ifndef _T_RECORD_H_
#define _T_RECORD_H_

typedef string TKey;
typedef string TValue;

class TRecord
{
private:
	TKey key;
	TValue val;

public:
	TRecord(TKey _k = "", TValue _v = "") { key = _k; val = _v; };
	~TRecord() {};

	void SetKey(TKey _k) { key = _k; };
	TKey GetKey() { return key; };
	void SetValue(TValue _v) { val = _v; };
	TValue GetValue() { return val; };

	bool operator==(const TRecord& rec) { return this->key == rec.key; };
	bool operator<(const TRecord& rec) { return this->key < rec.key; };
	bool operator>(const TRecord& rec) { return this->key > rec.key; };

	TRecord& operator=(const TRecord& rec);

	friend istream& operator>>(istream& is, TRecord& rec);
	friend ostream& operator<<(ostream& os, const TRecord& rec);

};
#endif

#ifndef _T_TABLE_H_
#define _T_TABLE_H_

class TTable
{
protected:
	int DataCount, Eff;

public:
	TTable() { DataCount = 0; Eff = 0; };
	virtual ~TTable() {};

	int GetDataCount() const { return DataCount; };
	int GetEff() const { return Eff; };
	void ResetEff() { Eff = 0; };

	bool IsEmpty() { return DataCount == 0; };
	virtual bool IsFull() = 0;

	virtual bool Find(TKey key) = 0;
	virtual void DelRec(TKey key) = 0;
	virtual void InsRec(TRecord rec) = 0;

	virtual void Reset() = 0;
	virtual void GoNext() = 0;
	virtual bool IsEnd() = 0;

	virtual TRecord GetCurr() = 0;
	void Print();
};
#endif

#ifndef _T_ARRAY_TABLE_H_
#define _T_ARRAY_TABLE_H_

class TArrayTable :public TTable
{
protected:
	TRecord* pRec;
	int curr, maxSize;
	std::size_t size;

public:
	TArrayTable(int size);
	virtual ~TArrayTable() {};

	virtual bool IsFull() { return maxSize == DataCount; };
	virtual TRecord GetCurr() { return pRec[curr]; };
	virtual void Reset() { curr = 0; }
	virtual void GoNext() { curr++; }
	virtual bool IsEnd() { return curr == DataCount; };

	int GetMaxSize() const { return maxSize; };
	std::size_t GetSize() const;
};
#endif

#ifndef _T_SCAN_TABLE_H_
#define _T_SCAN_TABLE_H_

class TScanTable :public TArrayTable
{
public:
	TScanTable(int size = 0) :TArrayTable(size) {};
	virtual ~TScanTable() {};

	virtual bool Find(TKey key);
	virtual void InsRec(TRecord rec);
	virtual void DelRec(TKey key);
};
#endif

#ifndef _T_SORT_TABLE_H_
#define _T_SORT_TABLE_H_

class TSortTable :public TArrayTable
{
private:
	void SortInsert();
	void SortHoar(int start, int end, TKey mid);

public:
	TSortTable(int size = 0) :TArrayTable(size) {};
	TSortTable(TScanTable& sc_tab);
	virtual ~TSortTable() {};

	virtual bool Find(TKey key);
	virtual void InsRec(TRecord rec);
	virtual void DelRec(TKey key);

};
#endif

#ifndef _T_TREE_NODE_H_
#define _T_TREE_NODE_H_

class TTreeNode
{
public:
	TRecord rec;
	TTreeNode *pLeft, *pRight;

	TTreeNode(TRecord _rec, TTreeNode* pL = NULL, TTreeNode* pR = NULL)
	{
		rec = _rec;
		pLeft = pL;
		pRight = pR;
	};
	~TTreeNode() {};
	TRecord GetRec() const;
	void InsRec(const TRecord& r);
};


#endif

#ifndef _T_TREE_TABLE_H_
#define _T_TREE_TABLE_H_

class TTreeTable :public TTable
{
protected:
	TTreeNode* pRoot, * pCurr, * pPrev;
	T_Stack <TTreeNode*> st;
	TTreeNode** pRef;
	int pos;

public:
	TTreeTable() :TTable(), st(100)
	{
		pRoot = NULL;
		pCurr = NULL;
		pRef = NULL;
	}
	virtual ~TTreeTable() {
		if (pRoot)
		{
			while (!st.IsEmpty())
				st.Pop();
			pCurr = pRoot;
			st.Push(pCurr);
			while (!st.IsEmpty())
			{
				pCurr = st.Top();
				st.Pop();
				if (pCurr->pLeft)
					st.Push(pCurr->pLeft);
				else if (pCurr->pRight)
					st.Push(pCurr->pRight);
				delete pCurr;
			}
		}
	}

	virtual bool IsFull() { return false; };
	virtual bool Find(TKey key);
	virtual void InsRec(TRecord rec);
	virtual void DelRec(TKey key);

	virtual void Reset();
	virtual void GoNext();
	virtual bool IsEnd() { return pos == DataCount; };
	virtual TRecord GetCurr() { return pCurr->rec; };

};

#endif

#ifndef _T_HASH_TABLE_H_
#define _T_HASH_TABLE_H_

class THashTable :public TTable
{
protected:
	int HashFunc(TKey key);

	int maxSize, curr, step, free;
	TRecord* pRec;

public:
	THashTable(int _size = 0, int _step = 0);
	virtual ~THashTable() { delete[] pRec; pRec = NULL; };

	virtual bool IsFull() { return maxSize == DataCount; };
	virtual bool Find(TKey key);
	virtual void InsRec(TRecord rec);
	virtual void DelRec(TKey key);

	virtual void Reset();
	virtual void GoNext();
	virtual bool IsEnd() { return curr == maxSize; };
	virtual TRecord GetCurr() { return pRec[curr]; };
};


#endif