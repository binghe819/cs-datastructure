#include <stdio.h>

int Fibo(int num)
{
    printf("called %d\n", num);
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
    
    for(int i = 1; i < num; i++)
    {
        printf("%d ",Fibo(i));
    }
    return 0;
}
