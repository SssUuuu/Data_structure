#include <stdio.h>
#include <assert.h>

void PrintSort(int *arr, int n){
    for(int i=0; i<n; ++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void ShellSort(int *arr, int n){
    assert(arr);
    
    int gap = n;
    while(gap > 1){
        gap = gap / 3 + 1;

        for(int i=0; i<n-gap; ++i){
            int end = i;
            int tmp = arr[end+gap];

            while(end >= 0){
                if(arr[end] > tmp){
                    arr[end+gap] = arr[end];
                    end -= gap;
                }else
                    break;
            }
            arr[end+gap] = tmp;
        }
    }
}

int main(){
    int arr[] = {5,4,3,2,1};
    ShellSort(arr, sizeof(arr)/sizeof(arr[0]));
    PrintSort(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
