#include "scantable.h"

bool TScanTable::FindRecord(TKey k) {
	int i;
	for (i = 0; i < DataCount; i++)
		if (pRecs[i].Key == k)
			break;
	Efficiency+=(i+1)/2;
	if (i < DataCount) {
		CurrPos = i;
		return true;
	}
	return false;
}

int TScanTable::InsRecord(TKey k, TValue pVal) {
	if (IsFull()) 
	{
		cout << "Table is full\n";
	}
	else {
		if (FindRecord(k))
		{
			cout << "Duplication\n";
		}
		else {
			pRecs[DataCount].Key = k;
			pRecs[DataCount].pValue = pVal;
			DataCount++;
			Efficiency++;
			return 0;
		}
	}
}

int TScanTable::DelRecord(TKey k) {
	if (FindRecord(k)) {
		pRecs[CurrPos] = pRecs[DataCount - 1];
		DataCount--;
		Efficiency++;
	}
	else {
		cout << "not found\n";
	}
	return 0;
}