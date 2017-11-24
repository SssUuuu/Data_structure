#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

//�ѣ����������±�����Ŷ�����,
//֪�����ӽڵ��±�Ϊi ,���׽ڵ��±�Ϊ(i-1)/2
//֪�����׽ڵ��±�Ϊi�����ӽڵ��±�Ϊ2*i +1���Һ����±�Ϊ2*i+2;

template<class T>
struct Greater
{
	bool operator()(const T& l, const T& r)
	{
		return l > r;
	}
};

template <class T>
struct Less
{
	bool operator()(const T& l, const T& r)
	{
		return l < r;
	}
};


template <class T, class Compare = Greater<T>>
class Heap
{
public:
	Heap()
	{}

	Heap(const T* arr, int n)
	{
		_a.reserve(n);
		for (int i = 0; i < n; i++)
			_a.push_back(arr[i]);

		for (int i = (_a.size() - 2) >> 1; i >= 0; --i)
			_AdjustDown(i);
	}

	//���뵽��󣬴Ӹ�λ�����ϵ���
	void Push(const T& x)
	{
		_a.push_back(x);
		_AdjustUp(_a.size() - 1);
	}

	//pop��_a[0]���滻ɾ��
	void Pop()
	{
		assert(!_a.empty());
		swap(_a[0], _a[_a.size() - 1]);
		_a.pop_back();
		_AdjustDown(0);
	}

	const T& Top()
	{
		assert(!_a.empty());
		return _a[0];
	}

	size_t Size() 
	{
		return _a.size();
	}

	bool Empty()
	{
		return _a.empty();
	}

protected:

	void _AdjustUp(int child)
	{
		Compare Com;
		int parent = (child - 1) >> 1;
		while (child > 0)
		{
			//if (_a[child] > _a[parent])
			if (Com(_a[child] , _a[parent]))
			{
				swap(_a[child], _a[parent]);
				child = parent;
				parent = (child - 1) >> 1;
			}
			else
			{
				break;
			}
		}
	}


	void _AdjustDown(int root)
	{
		Compare Com;
		int parent = root;
		//��Ϊ����ȫ�����������������ں��� �����ӱض�����
		int child = parent * 2 + 1; 
		while (child < _a.size())
		{
			if (child + 1 < _a.size()
				&& Com(_a[child+1],_a[child]))
				//_a[child + 1] > _a[child]
				child++;

			//_a[child] > _a[parent]
			if (Com(_a[child] , _a[parent]))
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				break;
		}
	}


private:
	vector<T> _a;
};
