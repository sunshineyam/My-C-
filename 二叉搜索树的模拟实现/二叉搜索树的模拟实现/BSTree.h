#pragma once
#include <iostream>
#include <set>
using namespace std;
template <class K>
struct BSTNode
{
	BSTNode(const K& key = K())
		:_left(nullptr)
		,_right(nullptr)
		, _key(key)
	{}
	BSTNode* _left;
	BSTNode* _right;
	K _key;
};
template <class K>
class BSTree
{
	typedef BSTNode<K> Node;
public:
	BSTree()
		:_root(nullptr)
	{}
	Node* Copy(Node* root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		//前序拷贝
		Node* newroot = new Node(root->_key);
		newroot->_left = Copy(root->_left);
		newroot->_right = Copy(root->_right);

		return newroot;
	}
	//copy(t)
	BSTree(const BSTree<K>& tree)
	{
		_root = Copy(tree._root);
	}
	//t1=t2
	BSTree<K>& operator=(const BSTree<K>& tree)
	{
		if (this != &tree)
		{
			//首先销毁t1,再赋值
			_Destory(this->_root);
			this->_root = Copy(tree._root);
		}
		return *this;
	}
	~BSTree()
	{
		_Destroy(_root);
		_root = nullptr;
	}
	//插入元素
	bool Insert(const K& key)
	{
		//如果树为空，直接插入
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* cur = _root;
		Node* parents = nullptr;
		//找插入新节点的位置
		while (cur)
		{
			parents = cur;
			if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else
			{
				//set有重复的不插入
				return false;
			}
		}
		cur = new Node(key);
		//插入节点
		if (key > parents->_key)
		{
			parents->_right = cur;
		}
		else
			parents->_left = cur;
		return true;
	}
	//查找值为data的节点
	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key == key)
			{
				return true;
			}
			else if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else if (key > cur->_key)
			{
				cur = cur->_right;
			}
		}
		return false;
	}
	bool Erase(const K& key)
	{
		if (_root == nullptr)
			return false;
		Node* cur = _root;
		Node* parents = nullptr;
		if (Find(key))
		{
			//找data在树中的位置
			while (cur)
			{
				if (key == cur->_key)
				{
					break;
				}
				else if (key > cur->_key)
				{
					parents = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					parents = cur;
					cur = cur->_left;
				}
			}
			Node* del = cur;
			//cur的左树为空
			if (cur->_left == nullptr)
			{
				//key是根节点
				if (parents == nullptr)
				{
					_root = cur->_right;
				}
				else
				{
					//删除cur，再把parents和cur的子树链起来
					if (parents->_left == cur)
					{
						parents->_left = cur->_right;
					}
					else
						parents->_right = cur->_right;
				}
			}
			//cur的右树为空
			else if (cur->_right == nullptr)
			{
				//data是根节点
				if (parents == nullptr)
				{
					_root = cur->_left;
				}
				else
				{
					if (parents->_left == cur)
					{
						parents->_left = cur->_left;
					}
					else
						parents->_right = cur->_left;
				}
			}
			//替代法删除：用左树的最右节点或右树的最左节点覆盖cur
			//cur的左右都不为空,找左树的最右节点（该节点的右一定为空）和右树的最左节点（该节点的左一定为空）
			else
			{
				//1、找cur的替代节点,假定替代节点replace指向cur的右
				Node* replace = cur->_right;
				//p_replace作为replaced父亲节点
				Node* p_replace = cur;
				//2、找替代节点replace的最左节点
				while (replace->_left)
				{
					p_replace = replace;
					replace = replace->_left;
				}
				//3、用replace的值去覆盖cur的值
				cur->_key = replace->_key;
				//4、删除replace节点
				if (p_replace->_left == replace)
				{
					p_replace->_left = replace->_right;
				}
				else
				{
					p_replace->_right = replace->_right;
				}
				del = replace;
			}

			delete del;
			return true;
		}
		else
			return false;
	}
	//_root节点是私有的，在类外面无法访问，所以要套一个_InOrder
	void InOrder()
	{
		_InOrder(_root);
	}
private:
	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
	}
	void _Destory(Node* root)
	{
		//后序销毁
		if (root == nullptr)
		{
			return;
		}
		_Destory(root->_left);
		_Destory(root->_right);
		delete	root;
	}
private:
	Node* _root;
};
