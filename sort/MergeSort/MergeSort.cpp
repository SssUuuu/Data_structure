#include <iostream>
using namespace std;

void Merge(int *arr, int left, int mid, int right, int *res){
  //将[first,mid] [mid+1,right]合并
    int first_start = left, first_end = mid;
    int second_start = mid+1, second_end = right;
    int res_index = 0;

    while(first_start <= mid && second_start <= right){
        if(arr[first_start] < arr[second_start]){
            res[res_index++] = arr[first_start++];
        }else
            res[res_index++] = arr[second_start++];
    }

    while(first_start <= mid)
        res[res_index++] = arr[first_start++];
    while(second_start <= right)
        res[res_index++] = arr[second_start++];

    for(int i=0; i<res_index; ++i){
        arr[left+i] = res[i];
    }
}

void merge_sort(int *arr, int left, int right, int* res){
    if(left >= right)
        return;

    int mid = (left + right) >> 1;
    merge_sort(arr, left, mid, res);
    merge_sort(arr, mid+1, right, res);
    Merge(arr,left,mid, right, res);
}


void MergeSort(int *arr, int n){
    if(arr == NULL)
        return ;

    //辅助空间
    int *res = new int[n];
    merge_sort(arr, 0, n-1, res);
    for(int i=0; i<n; ++i){
        cout<<arr[i]<<" ";
    }
    delete[] res;
}

void MergeSortNR(int *arr, int n){
    if(arr == NULL)
        return ;
    int size = 1; //size为一半部分元素的个数
    int left, right, mid;
    left = mid = right = 0;
    int *res = new int[n];

    while(size <= n - 1){
        left = 0;
        while(left + size <= n - 1){
            mid = left + size - 1;
            right = mid + size;

            if(right > n -1)
                right = n - 1;
            
            Merge(arr, left, mid ,right, res);
            left = right + 1;
        }
        size *= 2;
    }  
    delete[] res;
    for(int i=0; i<n; ++i){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {1,5,6,2,7};
    int num = sizeof(arr)/sizeof(arr[0]);
    MergeSortNR(arr, num);
   
    cout<<endl;
    return 0;
}
