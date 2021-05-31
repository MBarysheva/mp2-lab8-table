#include "Table.h"
#include "gtest.h"
//TRecord
TEST(TRecord, can_create)
{
	ASSERT_NO_THROW(TRecord r);
}

//TTable

TEST(TTable, can_create)
{
	ASSERT_NO_THROW(TTable * tab);
}

//TArrayTable

TEST(TArrayTable, can_create)
{
	ASSERT_NO_THROW(TArrayTable * tab);
}

//TScanTable
TEST(TScanTable, can_create)
{
	ASSERT_NO_THROW(TScanTable tab(4));
}

TEST(TScanTable, can_insert)
{
	TRecord rec("100", "100");
	TScanTable tab(4);
	ASSERT_NO_THROW(tab.InsRec(rec));
}

TEST(TScanTable, can_delete)
{

	TRecord rec("100", "100");
	TScanTable a(6);
	a.InsRec(rec);
	a.DelRec("100");
	EXPECT_EQ(0, a.GetDataCount());
}


//TSortTable
TEST(TSortTable, can_create)
{
	ASSERT_NO_THROW(TSortTable t(2));
}

TEST(TSortTable, can_insert)
{
	TSortTable t(2);
	TRecord rec("10", "100");
	ASSERT_NO_THROW(t.InsRec(rec));
}

TEST(TSortTable, can_find)
{
	TSortTable t;
	TRecord r;
	ASSERT_NO_THROW(t.Find(r.GetKey()));
}

TEST(TSortTable, can_delete)
{
	TSortTable t(2);
	TRecord rec("10", "100");
	t.InsRec(rec);
	ASSERT_NO_THROW(t.DelRec(rec.GetKey()));
}


//TTreeTable

TEST(TTreeTable, can_create)
{
	ASSERT_NO_THROW(TTreeTable t);
}

TEST(TTreeTable, can_insert)
{
	TTreeTable t;
	TRecord r;
	ASSERT_NO_THROW(t.InsRec(r));
}
TEST(TTreeTable, can_find)
{
	TTreeTable t;
	TRecord r;
	ASSERT_NO_THROW(t.Find(r.GetKey()));
}
TEST(TTreeTable, can_delete)
{
	TTreeTable t;
	TRecord r;
	t.InsRec(r);
	ASSERT_NO_THROW(t.DelRec(r.GetKey()));
}



//THashTable
TEST(THashTable, can_create)
{
	ASSERT_NO_THROW(THashTable t);
}

TEST(THashTable, can_insert)
{
	THashTable t(5, 2);
	TRecord rec("10", "100");
	ASSERT_NO_THROW(t.InsRec(rec));
}

TEST(THashTable, can_find)
{
	THashTable t(5, 2);
	TRecord rec("10", "100");
	ASSERT_NO_THROW(t.Find(rec.GetKey()));
}
TEST(THashTable, can_delete)
{
	THashTable t(5, 2);
	TRecord rec("10", "100");
	t.InsRec(rec);
	ASSERT_NO_THROW(t.DelRec(rec.GetKey()));
}
