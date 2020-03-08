#include <stdio.h>

// 선택 정렬
void SelectionSort(int arr[], int n)
{
    int i,j;
    int key;
    int tmp;
    
    for(i = 0; i < n-1; i++)
    {
        key = i;
        
        // 최소값 탐색
        for(j = i+1; j < n; j++)
        {
            if(arr[key] > arr[j])
                key = j;
        }
        
        // 맨 앞부터 찾은 최소값으로 바꾸기.
        tmp = arr[key];
        arr[key] = arr[i];
        arr[i] = tmp;
    }
}


int main(){
    
    int arr[9] = {3,4,2,1,8,12,34,5,9};
    
    SelectionSort(arr, sizeof(arr)/sizeof(int));
    
    for(int i = 0; i < 9; i++)
        printf("%d\t",arr[i]);
    
    return 0;
}

