//#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
using namespace std;
#include <stdlib.h>
namespace My{
	template<class T>
	struct __ListNode
	{
		T _data;
		__ListNode* _next;
		__ListNode* _prev;

		__ListNode(const T&x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	//_headΪ˽�еģ��������һ��������ȥ����
	template<class T, class Ref, class Ptr>
	struct __ListIterator
	{
		typedef __ListNode<T> Node;
		typedef __ListIterator<T, Ref, Ptr> Self;

		Node* _node;

		__ListIterator(Node* node)
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_data;
		}
		//��������T*���򷵻ص�ֻ���Ǹ��ڵ㣬����Ҫ���ʵ��ǽڵ��ֵ�����Ա��뷵��T*
		//T* operator->()
		//{
		//	//return &_node->_data;
		//	return &(operator()*);
		//}
		Ptr operator->()
		{
			//return &_node->_data;
			return &(operator()*);
		}
		//++it;
		//���ص�thisָ��
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		
		bool operator!=(const Self&s)
		{
			return _node != s._node;
		}
	};

	//����
	template<class T>
	class List
	{
		typedef __ListNode<T> Node;
	public:
		//typedef __ListIterator<T> iterator;
		typedef __ListIterator<T, T&, T*> iterator;
		typedef __ListIterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}

		size_t Size() const
		{
			size_t count = 0;
			Node* cur = _head->_next;
			while (cur!=_head)
			{
				count++;
				cur = cur->_next;
			}
			return count;
		}
		//����
		List()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		//��������
		List(const List<T>& l)
		{
			List<T> temp;
			this->Swap(temp);
		}
		//��ֵ
		List<T>& operator=(const List<T>& l) 
		{
			if (this != &l)
			{
				List<T> temp(l);
				this->Swap(temp);
			}
			return *this;
		}
		void Swap(List<T>& l)
		{
			swap(_head, l._head);
		}
		
		//����
		~List()
		{
			Clear();
			delete _head;
			_head = nullptr;
		}
		//_head,1,2,3��ֻ����1��2��3
		void Clear()
		{
			Node* cur = _head->_next;
			while (cur != _head)
			{
				Node* next = cur->_next;
				//new��deleteƥ��ʹ��
				delete cur;
				cur = next;
			}
			_head->_next = _head;
			_head->_prev = _head;
		}
		void PushBack(const T&x)
		{
			Node* newnode = new Node(x);
			Node* tail = _head->_prev;

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}
		void PopBack()
		{
			Node* tail = _head->_prev;
			Node* prev = tail->_prev;
			_head->_prev = prev;
			prev->_next = _head;
			delete tail;
		}
		void PushFront(const T& x)
		{
			Node* newnode = new Node(x);
			Node* cur = _head->_next;
			_head->_next = newnode;
			newnode->_prev = _head;
			newnode->_next = cur;
			cur->_prev = newnode;
		}
		void PopFront()
		{
			Node* next = _head->_next->_next;
			Node* cur = _head->_next;
			_head->_next = next;
			next->_prev = _head;
			delete cur;
		}
		iterator Insert(iterator pos, const T& x)
		{
			//�Զ������ͷ��ʳ�Ա�õ����
			//����pos->ȥ���ʣ�������operator->�����ص���ֵ��pos���Զ������ͣ����ʳ�ԱҪ�õ���ʣ�����Ҫ���ʵ��ǽڵ��ָ��
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			return iterator(newnode);
		}

		iterator Erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* pret = cur->_next;
			
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			return iterator(pret);
		}
	private:
		Node* _head;
	};
}
