#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;


//计数排序
//1：计算当前数组中最大值与最小值差值为len
//2: 开辟len+1个元素大小的数组tmp，arr数组中每个元素减去min 作为在tmp数组中的下标存放进去并计数
//3. tmp 下标值 = arr[i] - min     所以最后arr每个元素为对应tmp中的下标加上min

void CountSort(int* arr, size_t sz)
{
	assert(arr);
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < sz; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	int len = max - min + 1;//新开辟数组大小 最大值减最小值+1
	vector<int> tmp(max-min+1,0);
	for (int i = 0; i < sz; i++)
		tmp[arr[i] - min]++;

	int index = 0;
	for (int i = 0; i < tmp.size(); i++)
	{
		while (tmp[i]--)
			arr[index++] = i + min;
	}
}


int main()
{
	int arr[] = { 5,20,6,7,3,8 };
	CountSort(arr,sizeof(arr)/sizeof(arr[0]));

	system("pause");
	return 0;
}
