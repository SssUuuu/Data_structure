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
		//������char���ͣ�Ҫ��8��+1��Ϊ�˿ռ俪��
		int size = (range >> 3) + 1;
		_bitset.resize(size, 0);
	}

	//����xλ��1
	void Set(size_t x)
	{
		//��index ���ֽ�
		size_t index = (x >> 3);
		//��n��λ
		size_t n = x % 8;
		_bitset[index] |= (1<<n);
	}

	//����xλ��0
	void Reset(size_t x)
	{
		size_t index = (x >> 3);
		size_t n = x % 8;
		_bitset[index] &= ~(1 << n);
	}

	//�鿴��xλ��ֵ
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

