#include "stack.h"
#include <gtest.h>

TEST(STACK, can_create_stack) {
	ASSERT_NO_THROW(Stack<int> A);
}

TEST(STACK, can_put_an_element_to_stack) {
	Stack<int> A;
	ASSERT_NO_THROW(A.Push(1));
}

TEST(STACK, can_get_an_element_from_stack) {
	Stack<int> A;
	A.Push(2);
	ASSERT_NO_THROW(A.Pop());
}

TEST(STACK, cant_get_an_element_from_empty_stack) {
	Stack<int> A;
	ASSERT_ANY_THROW(A.Pop());
}

TEST(STACK, isEmpty_returns_true_when_stack_is_empty) {
	Stack<int> A;
	EXPECT_EQ(true, A.isEmpty());
}

TEST(STACK, isEmpty_returns_false_when_stack_is_not_empty) {
	Stack<int> A;
	A.Push(1);
	EXPECT_EQ(false, A.isEmpty());
}

