#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

//堆，利用数组下标来存放二叉树,
//知道孩子节点下标为i ,父亲节点下标为(i-1)/2
//知道父亲节点下标为i，左孩子节点下标为2*i +1，右孩子下标为2*i+2;

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

	//插入到最后，从该位置向上调整
	void Push(const T& x)
	{
		_a.push_back(x);
		_AdjustUp(_a.size() - 1);
	}

	//pop掉_a[0]，替换删除
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
		//因为是完全二叉树，所以若存在孩子 则左孩子必定存在
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
