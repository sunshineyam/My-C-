#pragma once
#include <iostream>
#include <deque>
#include <vector>
#include <list>
using namespace std;
template <class T, class Container = vector<T>>
class Stack
{
public:
	void Push(const T& x)
	{
		_con.push_back(x);
	}
	void Pop()
	{
		_con.pop_back();
	}
    const T& Top()
	{
		return _con.back();
	}
	size_t Size() const
	{
		return _con.size();
	}
	bool Empty()
	{
		return _con.empty();
	}
private:
	Container _con;
};
void TestStack()
{
	Stack<int, vector<int>> st;
	//Stack<int,list<int>> st;
	//模板参数给了缺省值，template <class T, class Container = vector<T>>
	Stack<int> st;
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	st.Push(5);
	while (!st.Empty())
	{
		cout << st.Top()<<" ";
		st.Pop();
	}
	cout << endl;
}