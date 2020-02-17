#include <stdio.h>

// 어떤 순서로 출력되는지 알기위한 코드.
int Fibo(int num)
{
    printf("called %d \n", num);
    if(num==1)
        return 0;
    else if(num==2)
        return 1;
    else
    {
        return Fibo(num-1)+Fibo(num-2);
    }
}

int main(){
    
    int num;
    printf("입력 : "); scanf("%d", &num);
    
    Fibo(5);
    return 0;
}