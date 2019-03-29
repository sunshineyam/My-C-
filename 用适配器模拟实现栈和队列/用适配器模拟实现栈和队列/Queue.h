#pragma once
#include <iostream>
#include <queue>
#include <list>
using namespace std;
template<class T,class Container>
class Queue
{
public:
	void Push(const T& x)
	{
		_con.push_back(x);
	}
	void Pop()
	{
		_con.pop_front();
	}
	const T& back()
	{
		return _con.back();
	}
	const T& Front()
	{
		return _con.front();
	}
	bool Empty()
	{
		return _con.empty();
	}
	size_t Size()
	{
		return _con.size();
	}
private:
	Container _con;
};

void TestQueue()
{
	Queue<int,list<int>> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);

	while (!q.Empty())
	{
		cout << q.Front() << " ";
		q.Pop();
	}
	cout << endl;

}