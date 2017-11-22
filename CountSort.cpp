#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;


//��������
//1�����㵱ǰ���������ֵ����Сֵ��ֵΪlen
//2: ����len+1��Ԫ�ش�С������tmp��arr������ÿ��Ԫ�ؼ�ȥmin ��Ϊ��tmp�����е��±��Ž�ȥ������
//3. tmp �±�ֵ = arr[i] - min     �������arrÿ��Ԫ��Ϊ��Ӧtmp�е��±����min

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
	int len = max - min + 1;//�¿��������С ���ֵ����Сֵ+1
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
