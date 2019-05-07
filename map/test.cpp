#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
void test_map1()
{
	map<string, string> m;
	//map�ײ��Ǽ�ֵ�Ե���ʽ�洢�������ڲ����ʱ��Ҫ�����ֵ��
	m.insert(pair<string,string>("apple", "ƻ��"));
	m.insert(make_pair("apple", "ƻ��"));
	m.insert(make_pair("banana", "�㽶"));
	m.insert(make_pair("banana", "�㽶"));
	m.insert(make_pair("peach", "����"));

	map<string, string> strs;
	strs.insert(make_pair("apple", "aaa"));
	strs.insert(make_pair("banana", "bbb"));
	strs.insert(make_pair("banana", "xxx"));
	strs.insert(make_pair("peach", "ppp"));
	m.swap(strs);
	//m.erase("apple");
	map<string, string>::iterator it = m.begin();
	//m.insert(it, make_pair("apple", "ƻ��"));
	while (it != m.end())
	{
		//*itȡ��pair,pair�������Ǽ�ֵ�ԣ�Ȼ������.�����������first��second
		//cout << (*it).first << ":" << (*it).second << endl;
		//(.)�ǽṹ���Ա�������ʳ�Ա������(->)�ǽṹ��ָ����ʳ�Ա
		//pair��һ���ṹ��ָ��
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
	string strs[] = { "ƻ��", "�㽶", "��ݮ", "ƻ��", "�㽶", "�㽶", "�㽶", "ƻ��", "�㽶", "��ݮ" };
	map<string, int> countmap;
	//����findͳ��ÿһ��Ԫ�س��ֵĴ���
	//ÿ��ѭ����strs����һ��Ԫ�ؿ�����e,���Լ����ÿ��Ա��⿽��ռ�ռ�
	for (const auto& e : strs)
	{
		map<string, int>::iterator it = countmap.find(e);
		//countmap.end()��map�����һ��Ԫ�ص���һ��
		if (it != countmap.end())
		{
			//����ҵ���value++��
			it->second++;
		}
		else
		{
			//����û����ȥ���룬��Ҫ����һ�飬��Щ������
			countmap.insert(make_pair(e, 1));
		}
	}
	//����ÿһ��Ԫ��
	map<string, int>::iterator cit = countmap.begin();
	while (cit != countmap.end())
	{
		cout << cit->first << ":" << cit->second << endl;
		cit++;
	}
}
void test_map3()
{
	string strs[] = { "ƻ��", "�㽶", "��ݮ", "ƻ��", "�㽶", "�㽶", "�㽶", "ƻ��", "�㽶", "��ݮ" };
	map<string, int> countmap;
	//����insertͳ��ÿ��Ԫ�س��ֵĴ���
	//pair<iterator,bool> insert (const value_type& val);
	//�����͵�insert����ֵ��һ��pair,��һ��Ԫ��first��һ����������ָ���²���Ԫ�ص�map���ڶ���Ԫ��second��һ��boolֵ������ɹ�����true,���򷵻�false
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
	string strs[] = { "ƻ��", "�㽶", "��ݮ", "ƻ��", "�㽶", "�㽶", "�㽶", "ƻ��", "�㽶", "��ݮ" };
	map<string, int> countmap;
	for (const auto& e : strs)
	{
		//�ȵ���operator[];�ٶԷ���ֵvalue����++��
		countmap[e]++;
	}
	for (auto& e : countmap)
	{
		cout << e.first << ":" << e.second << endl;
	}
	
	std::map<std::string, std::string> dict;
	dict.insert(std::make_pair("right", "�ұ�"));
	dict.insert(std::make_pair("right", "��ȷ��"));
	//����operator[]ֱ���޸ģ�[]������keyֵ���޸�value
	dict["right"] = "��ȷ��";
	//��ȱʡֵ
	dict["string"];
	dict["int"] = "����";
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