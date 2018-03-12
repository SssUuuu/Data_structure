#include <iostream>
#include <stdio.h>
using namespace std;

void SelectSort(int* arr, int num){
    if(arr == NULL || num <= 0)
        return;

    int left = 0;
    int right = num - 1;
    int min = left;
    int max = right;
    while(left <= right){
        min = left;
        max = right;
        for(int i=left; i<=right; ++i){
            if(arr[i] > arr[max]){
                max = i;
            }else if(arr[i] < arr[min]){
                min = i;
            }
        }
        swap(arr[left], arr[min]);
        if(left == max){
            max = min;
        }
        swap(arr[right], arr[max]);

        ++left;
        --right;
    }
}

int main(){
    int arr[] = {5,7,1,2,5,7};
    int num = sizeof(arr)/sizeof(arr[0]);
    SelectSort(arr,num);
    for(int i=0; i<num; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
