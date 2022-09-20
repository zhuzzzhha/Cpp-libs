// PriorityQueue.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
template <typename T>
struct Queue {
	struct Node {
		T data;
		std::unique_ptr <Node> next;
		Node():
			data(0),
			next(nullptr)
		{}
		Node(T value):
			data(value),
			next(nullptr)
		{}
	};
	std::unique_ptr<Node> head;
	~Queue()
	{
		while (head)
			head = std::move(head->next);
	}
	Queue() = default;
	Queue(const std::vector<T>& v)
	{
		
		for (int i = 0; i < v.size(); i++)
		{
			push(v[i]);
		}
	}
	Queue(const Queue& copy) = default;
	void push(T value)
	{
		Node* ind = head.get();
		Node* prev = head.get();
		if (value > ind->data)
			ind = (ind->next).get();
		while (value > ind->data && ind->next!=nullptr)
		{
			ind=(ind->next).get();
			prev = (prev->next).get();
		}
		Node* new_value;
		new_value->data = value;
		new_value->next = std::move(prev->next);
		prev->next = *(new_value);
		
	}
	void pop()
	{
		head = std::move(head->next);
	}
	T top()
	{
		return head->data;
	}
};
int main()
{
	return 0;
}
