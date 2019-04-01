//#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class A
{
public:
	A()
	{
		++_scount;
	}
	A(const A&t)
	{
		++_scount;
	}
    int GetACount()
	{
		return _scount;
	}
	
private:
	static int _scount;
};
int A::_scount = 0;
void test()
{
	//cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	//cout << A::GetACount() << endl;

	cout << GetACount() << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}