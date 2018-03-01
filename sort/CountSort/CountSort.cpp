#include <iostream>
#include <vector>
using namespace std;

void CountSort(int *arr, int size){
    if(arr == NULL)
        return;

    int max , min;
    max = min = arr[0];
    for(int i=0; i<size; ++i){
        if(max < arr[i])
            max = arr[i];
        if(min > arr[i])
            min = arr[i];
    }

    int size = max - min + 1;
    vector<int> tmp(size, 0);
    
    for(int i=0; i<size; ++i){
        tmp[arr[i]-min]++;
    }

    int index = 0;
    for(int i=0; i<size; ++i){
        while(tmp[i]--){
            arr[index++] = i+min;
        }
    }
}

int main(){
    int arr[] = {2,5,6,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    CountSort(arr, size);
    for(int i=0; i<size; ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
