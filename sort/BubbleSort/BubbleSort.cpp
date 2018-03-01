#include <iostream>
using namespace std;

//通过标记来使得当序列一旦已经有序时则直接停止
//提高效率
void BubbleSort(int *arr, int size){
    if(arr == NULL)
        return;

    int flags = 1;

    for(int i=0; i<size-1; ++i){
        if(flags == 0){
        //说明在上一趟排序时就已经有序了
            return;
        }

        flags = 0;
        for(int j=0; j<size-1-i; ++j){
            if(arr[j] > arr[j+1]){
                flags = 1;
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[] = {12,5,6,3,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr, size);
    for(int i=0; i<size; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
