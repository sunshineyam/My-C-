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
		//ǰ�򿽱�
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
			//��������t1,�ٸ�ֵ
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
	//����Ԫ��
	bool Insert(const K& key)
	{
		//�����Ϊ�գ�ֱ�Ӳ���
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* cur = _root;
		Node* parents = nullptr;
		//�Ҳ����½ڵ��λ��
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
				//set���ظ��Ĳ�����
				return false;
			}
		}
		cur = new Node(key);
		//����ڵ�
		if (key > parents->_key)
		{
			parents->_right = cur;
		}
		else
			parents->_left = cur;
		return true;
	}
	//����ֵΪdata�Ľڵ�
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
			//��data�����е�λ��
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
			//cur������Ϊ��
			if (cur->_left == nullptr)
			{
				//key�Ǹ��ڵ�
				if (parents == nullptr)
				{
					_root = cur->_right;
				}
				else
				{
					//ɾ��cur���ٰ�parents��cur������������
					if (parents->_left == cur)
					{
						parents->_left = cur->_right;
					}
					else
						parents->_right = cur->_right;
				}
			}
			//cur������Ϊ��
			else if (cur->_right == nullptr)
			{
				//data�Ǹ��ڵ�
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
			//�����ɾ���������������ҽڵ������������ڵ㸲��cur
			//cur�����Ҷ���Ϊ��,�����������ҽڵ㣨�ýڵ����һ��Ϊ�գ�������������ڵ㣨�ýڵ����һ��Ϊ�գ�
			else
			{
				//1����cur������ڵ�,�ٶ�����ڵ�replaceָ��cur����
				Node* replace = cur->_right;
				//p_replace��Ϊreplaced���׽ڵ�
				Node* p_replace = cur;
				//2��������ڵ�replace������ڵ�
				while (replace->_left)
				{
					p_replace = replace;
					replace = replace->_left;
				}
				//3����replace��ֵȥ����cur��ֵ
				cur->_key = replace->_key;
				//4��ɾ��replace�ڵ�
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
	//_root�ڵ���˽�еģ����������޷����ʣ�����Ҫ��һ��_InOrder
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
		//��������
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
