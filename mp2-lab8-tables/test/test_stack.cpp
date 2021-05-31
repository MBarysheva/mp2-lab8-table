#include "../mp2-lab7-tables/Table.h"
#include "../mp2-lab7-tables/Arraytable.h"
#include "../mp2-lab7-tables/ArrayHash.h"
#include "../mp2-lab7-tables/HashTable.h"
#include "../mp2-lab7-tables/Record.h"
#include "../mp2-lab7-tables/ScanTable.h"
#include "../mp2-lab7-tables/SortTable.h"
#include "../mp2-lab7-tables/Treetable.h"
#include "../mp2-lab7-tables/TreeNode.h"
#include "gtest.h"

TEST(TTable, can_create_table)
{

	ASSERT_NO_THROW(TTable <int> st(3));
}
TEST(TStack, can_create_stack_with_negativ_length)
{
	ASSERT_ANY_THROW(Stack<int>st(-1));
}
TEST(TStack, check_IsEmpty_with_empty_stack)
{
	Stack<int> st(5);
	EXPECT_EQ(true, st.Empty());
}
TEST(TStack, check_IsEmpty_with_not_empty_stack)
{
	Stack<int> st(5);
	st.Push(2);
	EXPECT_EQ(false, st.Empty());
}
TEST(TStack, check_IsFull_with_full_stack)
{
	Stack<int> st(2);
	st.Push(1);
	st.Push(2);
	EXPECT_EQ(true, st.Full());
}
TEST(TStack, check_IsFull_with_not_full_stack)
{
	Stack<int> st(5);
	st.Push(2);
	EXPECT_EQ(false, st.Full());
}
TEST(TStack, throws_when_Pop_stack_IsEmty)
{
	Stack<int> st(5);
	ASSERT_ANY_THROW(st.Pop());
}
TEST(TStack, throws_when_Push_stack_IsFull)
{
	Stack<int> st(2);
	st.Push(1);
	st.Push(2);
	ASSERT_ANY_THROW(st.Push(2));
}
