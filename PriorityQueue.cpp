// PriorityQueue.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
struct Queue {
	struct Node {
		int data;
		std::unique_ptr <Node> next;
		Node():
			data(0),
			next(nullptr)
		{}
		Node(int value):
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
	void push(int value)
	{
		Node* ind = head.get();
		Node* prev = head.get();
		if (value > ind->data)
			ind = (ind->next).get();
		while (value > ind->data)
		{
			ind=(ind->next).get();
			prev = (prev->next).get();
		}
		Node* new_value;
		new_value->data = value;
		new_value->next = *(ind);
		prev->next = *(new_value);
		
	}
	void pop()
	{
		head = std::move(head->next);
	}
	int top()
	{
		return head->data;
	}
};
