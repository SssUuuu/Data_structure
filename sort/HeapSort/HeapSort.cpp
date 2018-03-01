#include <iostream>
using namespace std;

//升序：设置大堆，调整完成后，将最后一个元素和堆顶元素交换重新调整
//每次调整完成后 end--;

void AdjustDown(int *arr, int parent, int size){
    if(arr == NULL || parent >= size)
        return;

    int child = parent*2+1;
    while(child < size){
        if(child+1 < size && arr[child] < arr[child+1]){
            child += 1;
        }
        if(arr[child] > arr[parent]){
            swap(arr[child], arr[parent]);
            parent = child;
            child = parent*2 + 1;
        }else{
            break;
        }
    }
}

void HeapSort(int *arr, int size){
    if(arr == NULL)
        return;
    
    for(int i=(size-2)/2; i>=0; --i){
        AdjustDown(arr,i,size);
    }
    
    int end = size-1;
    while(end >= 0){
        swap(arr[0], arr[end]);
        AdjustDown(arr,0,end);
        --end;
    }
}


int main(){
    int arr[] = {2,5,3,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    HeapSort(arr, size);
    for(int i=0; i<size; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
