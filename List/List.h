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

	//_head为私有的，所以设计一个迭代器去遍历
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
		//若不返回T*，则返回的只是那个节点，现在要访问的是节点的值，所以必须返回T*
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
		//隐藏的this指针
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

	//链表
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
		//构造
		List()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		//拷贝构造
		List(const List<T>& l)
		{
			List<T> temp;
			this->Swap(temp);
		}
		//赋值
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
		
		//析构
		~List()
		{
			Clear();
			delete _head;
			_head = nullptr;
		}
		//_head,1,2,3；只清理1、2、3
		void Clear()
		{
			Node* cur = _head->_next;
			while (cur != _head)
			{
				Node* next = cur->_next;
				//new和delete匹配使用
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
			//自定义类型访问成员用点访问
			//若用pos->去访问，重载了operator->，返回的是值；pos是自定义类型，访问成员要用点访问；现在要访问的是节点的指针
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
