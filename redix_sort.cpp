#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//求最大数的位数
int GetmMaxBitNum(vector<int> arr)
{
	int sz = arr.size();
	int tmp = 10;
	int ret = 1;
	for (int i = 0; i < sz; i++)
	{
		if (arr[i] >= tmp)
		{
			tmp *= 10;
			ret++;
		}
	}
	return ret;
}

void bucket_sort(vector<int>& arr)
{
	const int n = arr.size();
	int bit_num = GetmMaxBitNum(arr);
	int redix = 1;
	vector<int> bucket(10,0);
	vector<int> tmp(n,0);

	for (int i = 1; i <= bit_num; i++)
	{
		//每次初始化bucket
		for (int i = 0; i < 10; i++)
			bucket[i] = 0;

		//统计该位0-9分别出现的次数
		for (int i = 0; i < n; i++)
		{
			int index = (arr[i] / redix) % 10;
			bucket[index]++;
		}

		for (int i = 1; i < 10; i++)
			bucket[i] = bucket[i - 1] + bucket[i];

		//计算出对应的下标，按照稳定性从后向前排序
		for (int i = n-1; i >= 0 ; i--)
		{
			int index = (arr[i] / redix) % 10;
			tmp[bucket[index] - 1] = arr[i];
			bucket[index]--;
		}

		//拷贝回原数组
		for (int i = 0; i < n; i++)
			arr[i] = tmp[i];

		//进行下一位排序
		redix *= 10;
	}
}


int main()
{
	vector<int> arr = { 73,2,93,43,55,14,28,6,39,81 };
	bucket_sort(arr);
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
