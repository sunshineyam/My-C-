#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
void test_map1()
{
	map<string, string> m;
	//map底层是键值对的形式存储，所以在插入的时候要构造键值对
	m.insert(pair<string,string>("apple", "苹果"));
	m.insert(make_pair("apple", "苹果"));
	m.insert(make_pair("banana", "香蕉"));
	m.insert(make_pair("banana", "香蕉"));
	m.insert(make_pair("peach", "桃子"));

	map<string, string> strs;
	strs.insert(make_pair("apple", "aaa"));
	strs.insert(make_pair("banana", "bbb"));
	strs.insert(make_pair("banana", "xxx"));
	strs.insert(make_pair("peach", "ppp"));
	m.swap(strs);
	//m.erase("apple");
	map<string, string>::iterator it = m.begin();
	//m.insert(it, make_pair("apple", "苹果"));
	while (it != m.end())
	{
		//*it取到pair,pair里面存的是键值对，然后再用.访问它里面的first和second
		//cout << (*it).first << ":" << (*it).second << endl;
		//(.)是结构体成员变量访问成员函数，(->)是结构体指针访问成员
		//pair是一个结构体指针
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
	/*for (auto e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;
	cout << m.size() << endl;*/
}
void test_map2()
{
	string strs[] = { "苹果", "香蕉", "草莓", "苹果", "香蕉", "香蕉", "香蕉", "苹果", "香蕉", "草莓" };
	map<string, int> countmap;
	//利用find统计每一个元素出现的次数
	//每次循环将strs的下一个元素拷贝给e,所以加引用可以避免拷贝占空间
	for (const auto& e : strs)
	{
		map<string, int>::iterator it = countmap.find(e);
		//countmap.end()是map中最后一个元素的下一个
		if (it != countmap.end())
		{
			//如果找到，value++；
			it->second++;
		}
		else
		{
			//若是没有再去插入，又要遍历一遍，有些许冗余
			countmap.insert(make_pair(e, 1));
		}
	}
	//遍历每一个元素
	map<string, int>::iterator cit = countmap.begin();
	while (cit != countmap.end())
	{
		cout << cit->first << ":" << cit->second << endl;
		cit++;
	}
}
void test_map3()
{
	string strs[] = { "苹果", "香蕉", "草莓", "苹果", "香蕉", "香蕉", "香蕉", "苹果", "香蕉", "草莓" };
	map<string, int> countmap;
	//利用insert统计每个元素出现的次数
	//pair<iterator,bool> insert (const value_type& val);
	//此类型的insert返回值是一个pair,第一个元素first是一个迭代器，指向新插入元素的map，第二个元素second是一个bool值，插入成功返回true,否则返回false
	for (const auto& e : strs)
	{
		std::pair<std::map<std::string, int>::iterator, bool> ret = countmap.insert(make_pair(e, 1));
		if (ret.second == false)
		{
			ret.first->second++;
		}
	}
	map<string, int>::iterator cit = countmap.begin();
	while (cit != countmap.end())
	{
		cout << cit->first << ":" << cit->second << endl;
		cit++;
	}
}
void test_map4()
{
	string strs[] = { "苹果", "香蕉", "草莓", "苹果", "香蕉", "香蕉", "香蕉", "苹果", "香蕉", "草莓" };
	map<string, int> countmap;
	for (const auto& e : strs)
	{
		//先调用operator[];再对返回值value进行++。
		countmap[e]++;
	}
	for (auto& e : countmap)
	{
		cout << e.first << ":" << e.second << endl;
	}
	
	std::map<std::string, std::string> dict;
	dict.insert(std::make_pair("right", "右边"));
	dict.insert(std::make_pair("right", "正确的"));
	//利用operator[]直接修改，[]里面是key值，修改value
	dict["right"] = "正确的";
	//给缺省值
	dict["string"];
	dict["int"] = "整型";
}
int main()
{
	//test_map1();
	//test_map2();
	//test_map3();
	test_map4();
	system("pause");
	return 0;
}