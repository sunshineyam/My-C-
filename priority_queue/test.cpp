#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <functional>
//仿函数/函数对象
//template <class T>
//struct Less
//{
//	bool operator()(const T& left, const T& right)
//	{
//		return left < right;
//	}
//};

//int main()
//{
//	//priority_queue<int> pq;
//	//库里面的定义格式
//	//template <class T, class Container = vector<T>,
//	//class Compare = less<typename Container::value_type> > class priority_queue;
//	priority_queue<int, vector<int>, greater<int>> pq;
//	pq.push(1);
//	pq.push(2);
//	pq.push(3);
//	pq.push(4);
//	pq.push(5);
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;
//
//	/*int a = 1, b = 2;
//	Less<int> less;
//	cout << less(a, b) << endl;
//	cout << less.operator()(a, b) << endl;*/
//
//	system("pause");
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 2019, int month = 3, int day = 5)
//	:_year(year)
//	,_month(month)
//	,_day(day)
//	{}
//	bool operator<(const Date& d) const
//	{
//		return (_year < d._year) ||
//			(_year == d._year && _month < d._month) ||
//			(_year == d._year && _month == d._month && _day < d._day);
//	}
//	bool operator>(const Date& d) const
//	{
//		return (_year > d._year) ||
//			(_year == d._year && _month > d._month) ||
//			(_year == d._year && _month == d._month && _day > d._day);
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	priority_queue<Date,vector<Date>,greater<Date>> pq;
//	pq.push(Date(2018, 10, 1));
//	pq.push(Date(2019, 3, 1));
//	pq.push(Date(2018, 1, 1));
//	pq.push(Date(2019, 3, 6));
//
//	Date top = pq.top();
//	system("pause");
//	return 0;
//}

class Goods
{
public:
	int _price;
	int salves_volume;
	int _comprehensive;
};

struct GoodsPriceLess
{
	bool operator()(const Goods& l1, const Goods& l2)
	{
		return l1._price > l2._price;
	}
};

