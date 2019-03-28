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
	//vector是一个动态数组
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
				//将根节点尾插入vector开辟的动态数组result中
				result.push_back(root->val);
				//将二叉树的左路节点入栈
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