#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
void PrintList(const My::List<int>& lt)
{
	//lt是一个const对象，只能调const迭代器，否则会改变it的值
	My::List<int>::const_iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void TestList1()
{
	//类实例化,参数类型为int
	My::List<int> l;
	My::List<int> copy(l);
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PopBack();
	l.PushFront(0);
	l.PopFront();
	PrintList(copy);
	PrintList(l);


}

void TestList2()
{
	My::List<int> l;
	auto pos = l.begin();

	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	
	PrintList(l);
	
	//普通迭代器
	My::List<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void TestList3()
{
	//int array[] = { 1, 2, 3, 4, 5 };
	//My::List<int> l(array, array + sizeof(array) / sizeof(array[0]));
	My::List<int> l;
	auto pos = l.begin();
	l.Insert(l.begin(), 9);

	My::List<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	++pos;
	l.Insert(pos, 2);
}
void TestList4()
{
	My::List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.Clear();
	cout << "Clear()" << endl;

}
void TestList5()
{
	My::List<int> l;
	auto pos = l.begin();
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);
	
	//没删之前的size
	cout << l.Size() << endl;

	l.Erase(l.begin());
	cout << *pos << endl;
	auto it = l.begin();
	while (it != l.end())
	{
		it = l.Erase(it);
	}
	cout << l.Size() << endl;


	My::List<int> temp;
	temp = l;
	PrintList(temp);
}
int main()
{
	TestList3();
	system("pause");
	return 0;
}