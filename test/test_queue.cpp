/*#include "queue.h"
#include <gtest.h>

TEST(QUEUE, can_create_queue) {
	ASSERT_NO_THROW(Queue<int> A);
}

TEST(QUEUE, can_put_an_element_to_queue) {
	Queue<int> A;
	ASSERT_NO_THROW(A.Push(1));
}

TEST(QUEUE, can_get_an_element_from_queue) {
	Queue<int> A;
	A.Push(2);
	ASSERT_NO_THROW(A.Pop());
}

TEST(QUEUE, cant_get_an_element_from_empty_queue) {
	Queue<int> A;
	ASSERT_ANY_THROW(A.Pop());
}

TEST(QUEUE, isEmpty_returns_true_when_queue_is_empty) {
	Queue<int> A;
	EXPECT_EQ(true, A.isEmpty());
}

TEST(QUEUE, isEmpty_returns_false_when_queue_is_not_empty) {
	Queue<int> A;
	A.Push(1);
	EXPECT_EQ(false, A.isEmpty());
}*/
