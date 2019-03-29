//#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
//����
void test1()
{
	string s("hello world");
	//����operator[]
	size_t i = 0;
	for (i = 0; i < s.size(); i++)
	{
		cout << s[i];
	}
	cout << endl;
	//������
	string::iterator it = s.begin();
	while (it != s.end())//s.end()ָ��"world"��d�����λ��
	{
		//itָ���һ���ַ��ĵ�ַ
		cout << *it;
		++it;
	}
	cout << endl;
	//��Χfor�ɱ������е��������ײ�����������ʵ��
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
	//Ϊ�ַ���Ԥ���ռ䣬�������s   
    s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	//ֻ�ı�size�����ı�����
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
	//�൱������ָ��
	/*s2.swap(s1);
	cout << s1 << endl;
	cout << s2 << endl;*/
	//��Ҫ����һ���µĿռ䣬��ֵ����ȥ�ٽ���
	swap(s1, s2);
	cout << s1 << endl;
	cout << s2 << endl;
}
void test3()
{
	//��ȡ�ļ���׺
	/*string file1("test.cpp");
	size_t pos = file1.find('.');*/
	//substr:��posλ�ã���ȡn���ַ�
	/*string suffix(file1.substr(pos, file1.size() - pos));
	cout << suffix << endl;*/
	//ȡ��url�е�����
	string url("http://www.cpluxplux.com/reference/");
	size_t start = url.find("://");
	if (start == string::npos)
	{
		cout << "��Ч������" << endl;
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