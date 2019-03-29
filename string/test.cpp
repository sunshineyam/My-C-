//#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
//遍历
void test1()
{
	string s("hello world");
	//重载operator[]
	size_t i = 0;
	for (i = 0; i < s.size(); i++)
	{
		cout << s[i];
	}
	cout << endl;
	//迭代器
	string::iterator it = s.begin();
	while (it != s.end())//s.end()指向"world"的d后面的位置
	{
		//it指向第一个字符的地址
		cout << *it;
		++it;
	}
	cout << endl;
	//范围for可遍历所有的容器，底层依赖迭代器实现
	for (auto& e : s)
	{
		e += 1;
		cout << e;
	}
	string str("hello world");
	string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend())
	{
		cout << *rit;
		++rit;
	}
}
//
void test2()
{
	string s("hello world");
	/*cout << s.size()<<" ";
	cout << s.length()<<endl;
	cout << s.capacity()<<endl;
	cout << s.max_size() << endl;*/
	/*s.resize(10, "world");
	cout << s << endl;*/
	//string str("I like to code in C");
	//cout << str << '\n';
	/*unsigned sz = str.size();
	str.resize(sz+2, '+');
	cout << str << '\n';
	str.resize(14);
	cout << str << '\n';*/
	//string s("hello world");
	//为字符串预留空间，提高性能s   
    s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	//只改变size，不改变容量
	/*s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;*/
	/*cout << s.capacity() << endl;
	s.resize(20);
	cout << s.capacity() << endl;

	s.shrink_to_fit();
	cout << s.capacity() << endl;*/
	/*if (s.size() != s.capacity())
		s.push_back('x');
	cout << s << endl;
	s.erase(2, 5);
	cout << s << endl;
	s.erase(2);
	cout << s << endl;*/
	string s1("hello world");
	string s2("hahahah");
	//相当于两个指针
	/*s2.swap(s1);
	cout << s1 << endl;
	cout << s2 << endl;*/
	//需要开辟一段新的空间，把值拷进去再交换
	swap(s1, s2);
	cout << s1 << endl;
	cout << s2 << endl;
}
void test3()
{
	//获取文件后缀
	/*string file1("test.cpp");
	size_t pos = file1.find('.');*/
	//substr:从pos位置，截取n个字符
	/*string suffix(file1.substr(pos, file1.size() - pos));
	cout << suffix << endl;*/
	//取出url中的域名
	string url("http://www.cpluxplux.com/reference/");
	size_t start = url.find("://");
	if (start == string::npos)
	{
		cout << "无效的域名" << endl;
		return;
	}
	start += 3;
	size_t end = url.find('/',start);
	string address=url.substr(start, end - start);
	cout << address << endl;
}
int main()
{
	test2();
	system("pause");
	return 0;
}