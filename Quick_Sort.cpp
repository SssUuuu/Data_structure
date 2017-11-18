#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

//[left,right]闭区间 左右指针法
void Quick_Sort1(int* arr, int left, int right)
{
	assert(arr);
	if (left >= right)
		return;

	int begin = left;
	int end = right;
	int key = arr[end];

	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
			begin++;

		while (begin < end && arr[end] >= key)
			end--;

		if (begin < end)
			swap(arr[begin], arr[end]);
	}
	swap(arr[begin], arr[right]);

	Quick_Sort1(arr, left, begin - 1);
	Quick_Sort1(arr, begin + 1, right);
}

//挖坑快排法
void Quick_Sort2(int* arr, int left, int right)
{
	if (left >= right)
		return;

	int begin = left;
	int end = right;
	int key = arr[right];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= key)
			begin++;
		arr[end] = arr[begin];

		while (begin < end && arr[end] >= key)
			end--;
		arr[begin] = arr[end];
	}
	arr[end] = key;

	Quick_Sort2(arr, left, begin - 1);
	Quick_Sort2(arr, begin + 1, right);
}

//前后指针法
void Quick_Sort3(int* arr, int left, int right)
{
	if (left >= right)
		return;
	int cur = left;
	int prev = left - 1;
	while (cur < right)
	{
		if (arr[cur] < arr[right] && ++prev != cur)
			swap(arr[prev], arr[cur]);
		++cur;
	}

	swap(arr[++prev], arr[right]);

	Quick_Sort3(arr, left, prev - 1);
	Quick_Sort3(arr, prev + 1, right);
}

int main()
{
	int arr[] = { 2,5,4,9,3,6,8,7,1,5 };
	//Quick_Sort3(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	//Quick_Sort2(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	Quick_Sort1(arr,0, sizeof(arr) / sizeof(arr[0])-1);

	system("pause");
	return 0;
}
