#include <iostream>
#include <stdio.h>
#include <stack>

//快排时间复杂度为O(nlgn);
//快排优化：
//1、当选取key值每次都为最大时，end每次都需要与begin交换
//时间复杂度为O(N^2)，所以可以采用三数取中法，选择一个不大不小的key
//2、当区间内元素个数过少时，可以采取插入排序进行替代

void QuickSort(int *arr, int left, int right){
    if(left >= right)
        return;

    int key = arr[right];
    int begin = left;
    int end = right;

    //arr[begin]从左向右寻找比key大的值，与之后的arr[end]交换
    //arr[end]从右向左寻找比key小的值
    //当begin == end时，说明该位置就是key的位置
    while(begin < end){
        while(begin < end && arr[begin] <= key)
            ++begin;

        while(begin < end && arr[end] >= key)
            --end;

        if(begin < end){
            std::swap(arr[begin], arr[end]);
        }
    }
    std::swap(arr[begin], arr[right]);
    
    QuickSort(arr, left, begin-1);
    QuickSort(arr, begin+1, right);
}


void QuickSortNR(int *arr, int begin, int end){
    if(arr == NULL || begin >= end)
        return ;

    std::stack<int> s;
    int left = begin;
    int right = end;
    s.push(right);
    s.push(left);
    while(!s.empty()){

        left = s.top();
        s.pop();
        right = s.top();
        s.pop();
        
        if(left < right){
             int begin = left;
             int end = right;
             int key = arr[end];
             while(begin < end){

                 while(begin < end && arr[begin] <= key)
                     ++begin;
                 while(begin < end && arr[end] >= key)
                     --end;

                 if(begin < end)
                     std::swap(arr[begin], arr[end]);
             }
             std::swap(arr[begin], arr[right]);

             s.push(right);
             s.push(begin+1);

             s.push(begin-1);
             s.push(left);
          }  
      }
}

int main(){
    int arr[] = {2,3,4,1,5};
    int num = sizeof(arr)/sizeof(arr[0]);
    QuickSortNR(arr, 0, num-1);
    for(int i=0; i<num; ++i){
        std::cout<<arr[i]<<" ";
    }
    printf("\n");
    return 0;
}
