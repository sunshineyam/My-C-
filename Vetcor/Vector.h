#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <assert.h>
#include <algorithm>
using namespace std;
namespace My
{
	template <class T>
	class Vector
	{
	public:
		typedef T* iterator;
		typedef T* const_iterator;
		//无参构造
		Vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		//拷贝构造copy(v1)
		Vector(const Vector<T>& v)
		{
			_start = new T[v.Size()];
			memcpy(_start, v._start, sizeof(T)*v.Size());
			_finish = _start + v.Size();
			_endofstorage = _start + v.Size();
		}
		//v2=v1
		Vector<T>& operator=(const Vector<T>& v)
		{
			if (this != &v)
			{
				delete[] _start;
				_start = new T[v.Size()];
				memcpy(_start, v._start, sizeof(T)*v.Size());
				_finish = _start + v.Size();
				_endofstorage = _start + v.Size();
			}
		}
		/*Vector<T>& operator=(const Vector<T>& v)
		{
			this->Swap(v);
			return *this;
		}
		void Swap(Vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}*/
		void Reserve(size_t n)
		{
			if (n > Capacity())
			{
				size_t size = Size();
				T* tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < size; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + size;
				_endofstorage = _start + n;
			}
		}
		void Resize(size_t n, const T& value = T())
		{
			//如果n<=Size()，则把Size缩减到n
			if (n <= Size())
			{
				_finish = _start + n;
				return;
			}
			else
			{
				if (n > Capacity())
				{
					Reserve(n);
				}
				while (_finish != _start + n)
				{
					*_finish = value;
					_finish++;
				}
			}
		}
		void PushBack(const T &x)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = Capacity() == 0 ? 2 : Capacity() * 2;
				Reserve(newcapacity);
			}
			*_finish = x;
			++_finish;
		}
		void PopBack()
		{
			assert(Size() > 0);
			--_finish;
			
		}
		iterator Insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			size_t posindex = pos - _start;
			if (_finish == _endofstorage)
			{
				size_t newcapacity = Capacity() == 0 ? 2 : Capacity() * 2;
				Reserve(newcapacity);
				pos = posindex + _start;
			}
			iterator end = _finish;
			while (end>pos)
			{
				*end = *(end - 1);
				--end;
			}
			*pos = x;
			++_finish;
                        return pos;
		}
		iterator Erase(iterator pos)
		{
			assert(pos < _finish);
			iterator next = pos;
		   
			while (pos < _finish)
			{
				*pos = *(pos + 1);
				++pos;
			}
			--_finish;
			return next;
		}

		~Vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}
		T& operator[](size_t pos)
		{
			assert(pos < Size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const
		{
			assert(pos < Size());
			return _start[pos];
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		size_t Size() const
		{
			return _finish - _start;
		}
		size_t Capacity() const
		{
			return _endofstorage - _start;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
	void TestVector()
	{
		Vector<int> v1;
		v1.PushBack(1);
		v1.PushBack(2);
		v1.PushBack(3);
		v1.PushBack(4);
		v1.PushBack(5);
		v1.PopBack();
		/*auto pos = std::find(v1.begin(), v1.end(), 2);
		while (pos != v1.end())
		{
			v1.Insert(pos, 0);
		}*/
		auto pos = std::find(v1.begin(), v1.end(), 2);
		v1.Erase(pos);
		v1.Erase(pos);
		v1.Erase(pos);

		//循环遍历
		for (size_t i = 0; i < v1.Size(); i++)
		{
			cout << v1[i]<<" ";
		}
		cout << endl;
		//迭代器遍历
		Vector<int>::iterator it1 = v1.begin();
		while (it1 != v1.end())
		{
			cout << *it1<<" ";
			it1++;
		}
		cout << endl;
		//范围for遍历
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		
		

		Vector<int> copy(v1);
		Vector<int> v2;
	}
}

