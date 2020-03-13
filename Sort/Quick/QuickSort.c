#include <stdio.h>

// 제일 왼쪽의 인덱스를 계속해서 pivot으로 선택하는 기본적인 Quick
void Swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int Partition(int arr[], int first, int last)
{
    int pivot = arr[first]; // 피벗의 위치. ( 가장 왼쪽으로 설정 )
    int low = first+1;
    int high = last;
    
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
    if(first < last) // first=last는 요소가 하나라는 뜻이므로, 이때는 continue
    {
        // 둘로 나눔.
        int pivot = Partition(arr, first, last);
        QuickSort(arr, first, pivot-1); // 왼쪽 영역 정렬
        QuickSort(arr, pivot+1, last); // 오른쪽 영역 정렬
    }
}

int main(){
    
    int arr[9] = {3,4,2,1,8,12,34,5,9};
    int len = sizeof(arr)/sizeof(int);
    
    QuickSort(arr, 0, len);
    
    for(int i = 0; i < len; i++)
        printf("%d\t", arr[i]);
    
    return 0;
}

