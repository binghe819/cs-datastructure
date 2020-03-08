#include <stdio.h>

// 버블 정렬
void BubbleSort(int arr[], int n)
{
    int i, j;
    int tmp;
    
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < (n-i)-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}


int main(){
    
    int arr[9] = {3,4,2,1,8,12,34,5,9};
    
    BubbleSort(arr, sizeof(arr)/sizeof(int));
    
    for(int i = 0; i < 9; i++)
        printf("%d\t",arr[i]);
    
    return 0;
}

