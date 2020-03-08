#include <stdio.h>

// 삽입 정렬
void InsertionSort(int arr[], int n)
{
    int i,j;
    int insData;
    
    for(i = 1; i < n; i++)
    {
        insData = arr[i]; // 정렬 대상 저장.
        for(j = i-1; j >= 0; j--)
        {
            if(arr[j] > insData)
                arr[j+1] = arr[j]; // 정렬 대상보다 크면  한 칸 뒤로 밀기
            else
                break; // 삽입 위치를 찾았으면 탈출.
        }
        arr[j+1] = insData; // 찾은 위치에 정렬대상 삽입.
    }
}

int main(){
    
    int arr[9] = {3,4,2,1,8,12,34,5,9};
    
    InsertionSort(arr, sizeof(arr)/sizeof(int));
    
    for(int i = 0; i < 9; i++)
        printf("%d\t",arr[i]);
    
    return 0;
}

