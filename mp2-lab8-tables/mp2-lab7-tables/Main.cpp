#define _CRT_SECURE_NO_WARNINGS

#include "scantable.h"
#include "sorttable.h"
#include "treetable.h"
#include"ArrayHash.h"
#include <string>
#include <random>

enum TTabMode { SCAN_TABLE = 1, SORT_TABLE = 2, TREE_TABLE = 3, HASH_TABLE = 4};
TTable* pTab = NULL;
int* pKeys = NULL;
int* pVals = NULL;
int DataCount = 0, MemSize;

void TableGenerator(TTabMode mode) {
	int  MaxKey;
	char Line[100];
	cout << "Input the max size of table - ";
	cin >> MemSize;
	cout << "Input the size of table - ";
	cin >> DataCount;
	cout << "Input the max key  - ";
	cin >> MaxKey;
	switch (mode) {
	case SCAN_TABLE:
		pTab = new TScanTable(MemSize);
		break;
	case SORT_TABLE:
		pTab = new TSortTable(MemSize);
		break;
	case TREE_TABLE:
		pTab = new TTreeTable();
		break;
	case HASH_TABLE:
		pTab = new TArrayHashTable(MemSize);
		break;
	}
	pKeys = new int[MemSize];
	pVals = new int[MemSize];
	for (int i = 0; i < DataCount; i++) {
		pKeys[i] = rand() % MaxKey;
		pVals[i] = (rand() % 1000);
		pTab->InsRecord(pKeys[i], pVals[i]);
	}
	pTab->ClearEfficiency();
}

int TableProcessor(TTabMode mode) {
	int com;
	int key;
	int rec;
	while (1) {
		cout << "0 - New Table, 1 - Find, 2 - Insert, 3 - Delete, 4 - Print, 5 - Exit  ";
		cin >> com;
		if (com == 0)
			return 0;
		if (com == 2) {
			cout << "Input the key - ";
			cin >> key;
			cout << "Input the rec - ";
			cin >> rec;
		}
		if (com == 1 || com == 3) {
			cout << "Input the key - ";
			cin >> key;
		}
		if (com == 1) {
			pTab->ClearEfficiency();
			if (pTab->FindRecord(key))
			{
				cout << " Find " << pTab->FindRecord(key) << endl;
				cout << " Efficiency  = " << pTab->GetEfficiency() << endl;
			}
			else cout << "not found\n";
		}
		if (com == 2) {
			pTab->ClearEfficiency();
			if (DataCount >= MemSize)
				cout << "Table is full" << endl;
			else {
				pKeys[DataCount] = key;
				pVals[DataCount] = rec;
				pTab->InsRecord(key, pVals[DataCount]);
				DataCount++;
			}
		}
		if (com == 3) {
			pTab->ClearEfficiency();
			pTab->DelRecord(key);
			cout << " Efficiency  = " << pTab->GetEfficiency() << endl;
		}
		if (com == 4)
		{
			pTab->ClearEfficiency();
			if (mode != TREE_TABLE)
			{
				cout << *pTab; 
			}
			else
				((TTreeTable*)pTab)->Draw();
		}
		if (com == 5)
		{
			return 1;
		}
	}
	
}

int main() {
	int TableType;
	int sw = 0;
	while (!sw) 
	{
	    cout << "1-Scan, 2-Sort, 3-Tree, 4-Hash: ";
	    cin >> TableType;
		TableGenerator((TTabMode)TableType);
		sw = TableProcessor((TTabMode)TableType);
	}
}