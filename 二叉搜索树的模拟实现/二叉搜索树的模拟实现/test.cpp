#define _CRT_SECURE_NO_WARNINGS 1
#include "BSTree.h"
void test()
{
	/*BSTree<int> BT;
	BT.Insert(5);
	BT.Insert(3);
	BT.Insert(7);
	BT.Insert(1);
	BT.Insert(4);
	BT.Insert(6);
	BT.Insert(8);
	BT.InOrder();
	cout << endl;*/
	/*cout <<"²éÕÒ£º"<< BT.Find(3) << endl;
	cout << endl;
	cout << "É¾³ý£º" << BT.Erase(7) << endl;*/
	BSTree<int> t;
	int a[] = { 5, 3, 7, 1, 4, 6, 8, 9, 0, 2 };
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();
	cout << endl;
	BSTree<int> copy(t);
	copy.InOrder();
	cout << endl;
	t = copy;
	t.InOrder();
	/*t.Erase(5);
	t.Erase(1);
	t.Erase(8);
	t.InOrder();
	t.~BSTree();*/
}
int main()
{
	test();
	system("pause");
	return 0;
}