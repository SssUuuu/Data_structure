#include <stdio.h>

void InserSort(int *arr, int n){

    for(int i=0; i<n-1; ++i){
        int end = i;
        int tmp = arr[end+1];
        while(end >= 0){
            if(arr[end] > tmp){
                arr[end+1] = arr[end];
                --end;
            }else{
                break;
            }
        }
        arr[end+1] = tmp;
    }
}

void Print(int *arr, int n){
    for(int i=0; i<n; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {2,4,1,5,6};
    InserSort(arr, sizeof(arr)/sizeof(arr[0]));
    Print(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
