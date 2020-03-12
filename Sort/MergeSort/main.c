#include <stdio.h>
#include <stdlib.h>

// 두 개의 영역 병합
void MergeTwoArea(int arr[], int first, int mid, int last)
{
    int leftIdx = first; // 첫번째 영역에서의 첫번째 인덱스
    int rightIdx = mid+1; // 두번째 영역에서의 첫번째 인덱스
    int i;
    
    int (*sortedArr) = malloc(sizeof(int) * (last+1)); // 비교하고난 결과들을 저장해놓는 tmp배열.
    int sortIdx = first; // tmp배열의 인덱스.
    
    // 분할한 두 영역을 하나하나 훑으면서 비교.
    while(leftIdx <= mid && rightIdx <= last)
    {
        if(arr[leftIdx] < arr[rightIdx]) // 첫번째 영역의 값이 더 작은 경우
        {
            sortedArr[sortIdx] = arr[leftIdx];
            leftIdx++;
        }
        else // 두번째 영역의 값이 더 작은 경우
        {
            sortedArr[sortIdx] = arr[rightIdx];
            rightIdx++;
        }
        sortIdx++;
    }
    
    // 비교후 두 영역중 남은 숫자 대입.
    if(leftIdx > mid)
    {
        for(i = rightIdx; i <= last; i++)
        {
            sortedArr[sortIdx] = arr[i];
            sortIdx++;
        }
    }
    else
    {
        for(i = leftIdx; i <= mid; i++)
        {
            sortedArr[sortIdx] = arr[i];
            sortIdx++;
        }
    }
    
    // tmp배열에서 원래 배열로 복사
    for(i = first; i <= last; i++)
        arr[i] = sortedArr[i];
    
    free(sortedArr);
}

// 병합 정렬
void MergeSort(int arr[], int first, int last)
{
    if(first < last) // 분할된게 하나라면 continue하기 위함.
    {
        // 중간 값
        int mid = (first + last) / 2;
        
        // 분할
        MergeSort(arr, first, mid);
        MergeSort(arr, mid+1, last);
        
        // 병합
        MergeTwoArea(arr, first, mid, last);
    }
}


int main(){
    
    int arr[9] = {3,4,2,1,8,12,34,5,9};
    
    MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);
    
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
        printf("%d\t", arr[i]);
    
    return 0;
}

