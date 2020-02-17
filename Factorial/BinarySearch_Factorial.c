#include <stdio.h>

int BSearch(int arr[], int first, int last, int target)
{
    int mid = (first+last)/2;
    
    if(first > last) // 못찾음.
        return -1;
    
    if(arr[mid] == target) // 정답을 찾은 경우
        return mid;
    else if(arr[mid] < target) // 중앙값이 정답보다 작은 경우
        return BSearch(arr, mid+1, last, target);
    else // 중앙값이 정답보다 큰 경우
        return BSearch(arr, first, mid-1, target);
}

int main(){
    int arr[] = {1,2,5,6,7,8,9,10,13,15};
    
    int idx = BSearch(arr, 0, sizeof(arr)/sizeof(int)-1, 5);
    
    if(idx == -1)
        printf("못 찾음 \n");
    else
        printf("%d", idx);
    return 0;
}
