#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <functional>
template<class T,class Container=vector<T>,class Compare=less<T>>
class PriorityQueue
{
public:
	//大堆
	void Adjustup(int child)
	{
		int parents = (child - 1) / 2;
		while (child>0)
		{
			Compare com;
			//重载operator()
			if (com(_con[parents] , _con[child]))
			{
				swap(_con[parents], _con[child]);
				child = parents;
				parents = (child - 1) / 2;
			}
			else
				break;
		}
	}
	void Adjustdown(size_t parents)
	{
		int child = parents * 2 + 1;
		while (child < _con.size())
		{
			Compare com;
			//找出左右孩子大的
			if (child + 1 < _con.size() && com(_con[child] ,_con[child + 1]))
				child++;
			if (com(_con[parents] , _con[child]))
			{
				swap(_con[parents], _con[child]);
				parents = child;
				child = parents * 2 + 1;
			}
			else
				break;
		}
	}
	void Push(const T& x)
	{
		_con.push_back(x);
		Adjustup(_con.size()-1);
	}
	void Pop()
	{
		swap(_con[0], _con[_con.size() - 1]);
		_con.pop_back();
		Adjustdown(0);
	}
	const T& Top()
	{
		return _con[0];
	}
	const T& Back()
	{
		return _con[_con.size() - 1];
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

void TestPriorityQueue()
{
	PriorityQueue<int, vector<int>,greater<int>> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);

	while (!q.Empty())
	{
		cout << q.Top() << " ";
		q.Pop();
	}
	cout << endl;
}