#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <queue/queue.h>
#include<vector>
TEST_CASE("[queue] - queue ctor")
{
	
	CHECK(Queue(int) == Queue(std::vector<int> v(0), 0));
}
TEST_CASE("[queue] - queue operators")
{
	int a = 1;
	std::vector<int> v = { 5,1,2,3,6 };
	std::vector<int> x = { 5,1,1,2,3,6 };
	CHECK(Queue(v).top() == a);
	CHECK(Queue(v).push(a) == Queue(x));
	CHECK(Queue(v).pop() == Queue(v));
}
