#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MyBitSet
{
public:
	MyBitSet(size_t range)
	{
		//由于是char类型，要除8，+1是为了空间开够
		int size = (range >> 3) + 1;
		_bitset.resize(size, 0);
	}

	//将第x位置1
	void Set(size_t x)
	{
		//第index 个字节
		size_t index = (x >> 3);
		//第n个位
		size_t n = x % 8;
		_bitset[index] |= (1<<n);
	}

	//将第x位置0
	void Reset(size_t x)
	{
		size_t index = (x >> 3);
		size_t n = x % 8;
		_bitset[index] &= ~(1 << n);
	}

	//查看第x位的值
	bool Test(size_t x)
	{
		size_t index = (x >> 3);
		size_t n = x % 8;
		return _bitset[index] & (1 << n);
	}

	size_t Count()
	{
		int count = 0;
		for (size_t index = 0; index < _bitset.size(); index++)
		{
			for (int i = 0; i < 8; i++)
			{
				if (Test(i+i*index))
					count++;
			}
		}
		return count;
	}

	void Print()
	{
		for (size_t index = 0; index < _bitset.size(); index++)
		{
			for (int i = 0; i < 8; i++)
			{
				if (Test(i + i*index))
					cout << 1;
				else
					cout << 0;
			}	
			cout << " ";
		}
	}
private:
	vector<char> _bitset;
};

