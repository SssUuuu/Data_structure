#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;


//��parent,����child,��ѭ��.ע�⹹������С��
void AdjustDown(vector<int>& heap,int parent)
{
	assert(parent < heap.size());
	int child = parent * 2 + 1;
	while (child < heap.size())
	{
		if (child + 1 < heap.size() && heap[child + 1] < heap[child])
			child++;
		if (heap[child] < heap[parent])
		{
			swap(heap[child], heap[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}


void TopK(const vector<int>& v, int k)
{
	assert(k < v.size());

	vector<int> topK;
	topK.reserve(k);

	//�ȹ���һ��kԪ�صĶѣ��ٽ��е���
	for (int i = 0; i < k; i++)
		topK.push_back(v[i]);

	for (int i = (k - 2)/2; i >= 0; i--)
		AdjustDown(topK,i);

	//��������Ԫ�أ����бȽϵ���
	for (int i = k; i < v.size(); i++)
	{
		if (v[i] > topK[0])
		{
			topK[0] = v[0];
			AdjustDown(topK,0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		cout << topK[i] << " ";
	}

}

void Test1()
{
	vector<int> v;
	v.resize(10, 5);

	v[4] = 100;
	v[5] = 101;
	v[6] = 102;
	v[7] = 103;

	TopK(v,5);
}

int main()
{
	Test1();

	system("pause");
	return 0;
}
