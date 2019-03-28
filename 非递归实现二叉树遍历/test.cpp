//#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class My {
public:
	//vector��һ����̬����
	vector<int> result;
	vector<int> preorderTraversal(TreeNode* root) {
		if (root == NULL)
			return{};
		stack<TreeNode*> st;
		vector<int> result;
		while (root != NULL || !st.empty())
		{
			if (root != NULL)
			{
				//�����ڵ�β����vector���ٵĶ�̬����result��
				result.push_back(root->val);
				//������������·�ڵ���ջ
				//root=root->left;
				if (root->left)
				{
					st.push(root->left);
				}
				else
				{
					if (root->right)
					{
						st.push(root->right);
					}
				}
				//continue;
			}
			root = st.top();
			st.pop();

		}
		return result;

	}
};

void test()
{
	My m;
	TreeNode* mroot;
	vector<int> array = { 1, NULL, 2, 3 };

	m.preorderTraversal(mroot);
	std::vector<int>::iterator it = array.begin();
	while (it != array.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}