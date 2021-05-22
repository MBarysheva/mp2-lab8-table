#pragma once
typedef int TKey;
typedef int TVal;
struct TRecord
{
	TKey k;
	TVal val;
};
class TTable
{
protected:
	int Eff;
public: 
int GetEff()
	{
		return Eff;
	}
void ClearEff()
{
	Eff = 0;
}
};
