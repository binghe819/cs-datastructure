#include <stdio.h>
#include <stdlib.h>

// 가장 왼쪽 값이 아닌 중간 값을 뽑아서 정렬하는 코드.

void Swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int findmidValue(int arr[], int first, int last)
{
    // 첫번째, 중간, 마지막 인덱스
    int tmp[3] = {first, (first+last)/2, last-1};
    
    // 버블 정렬
    if(arr[tmp[0]] > arr[tmp[1]])
        Swap(tmp, 0, 1);
    if(arr[tmp[1]] > arr[tmp[2]])
        Swap(tmp, 1, 2);
    if(arr[tmp[0]] > arr[tmp[1]])
        Swap(tmp, 0, 1);
    
    // 값 확인.
//    for(int i = 0; i < 3; i++)
//        printf("%d \t", arr[tmp[i]]);
    
    return tmp[1];
}

int Partition(int arr[], int first, int last)
{
    int pivotIdx = findmidValue(arr, first, last);
    int pivot = arr[pivotIdx]; // 피벗의 위치. ( 개발자 지정 가능 )
    
    int low = first+1;
    int high = last;
//    printf("피벗 : %d\n", pivot);
    
    // 피벗을 가장 왼쪽으로 이동.
    Swap(arr, first, pivotIdx);
    
    // 교차되지 않을 때까지 반복
    while( low <= high )
    {
        // 피벗보다 큰 값을 찾는 과정
        while(pivot >= arr[low] && low <= last)
            low++;
        
        // 피벗보다 작은 값을 찾는 과정
        while(pivot <= arr[high] && high >= (first+1))
            high--;
        
        // 교차되지 않은 상태라면 swap 실행.
        if(low <= high)
            Swap(arr, low, high);
    }
    
    Swap(arr, first, high); // 피벗과 high가 가리키는 대상 교환
    return high; // 옮겨진 피벗의 위치정보 반환 (정렬이 완료된 인덱스 반환)
}

void QuickSort(int arr[], int first, int last)
{
    if(first <= last)
    {
        // 둘로 나눔.
        int pivot = Partition(arr, first, last);
        QuickSort(arr, first, pivot-1); // 왼쪽 영역 정렬
        QuickSort(arr, pivot+1, last); // 오른쪽 영역 정렬
    }
}

int main(){
    
    int arr[13] = {5,3,6,9,10,34,22,53,1,2,4,5,8};
    int len = sizeof(arr)/sizeof(int);
    QuickSort(arr, 0, len);

    for(int i = 0; i < len; i++)
        printf("%d\t", arr[i]);
    
//    printf("%d", findmidValue(arr, 0, len));
    
    return 0;
}

