#include <stdio.h>
#include "CircularQueue.h"
#include <time.h>
#include <stdlib.h>

#define CUS_COME_TERM 15 // 고객의 주문 간격 : 초 단위

#define CHE_BUR 0 // 치즈 버거 상수
#define BUL_BUR 1 // 불고기 버거 상수
#define DUB_BUR 2 // 더블버거 상수

// 햄버거 제작 시간 ( 초단위 )
#define CHE_TERM 12
#define BUL_TERM 15
#define DUB_TERM 24

int main(){
    
    int makeProc = 0; // 햄버거 제작 진행 상황
    int cheOrder = 0, bulOrder = 0, dubOrder = 0;
    int sec;

    QUEUE que;
    QueueInit(&que);
    srand(time(NULL)); // 난수에 매번 다른 시드를 주기 위함. 시간을 시드로 주기 때문에 항상 랜덤한 숫자가 나온다.
    
    // 랜덤한 숫자 뽑기 ( n에 정수를 지정하면 0부터 n 사이의 랜덤한 값을 뽑는다. )
    // srand(time(NULL));
    // printf("%d",rand()%n);

    // 한 반복마다 1초의 시간 흐름을 의미함. ( 3600초 = 1시간 )
    for(sec = 0; sec < 3600; sec++)
    {
        if(sec % CUS_COME_TERM == 0) // 15초마다 한번 주문.
        {
            switch(rand() % 3) // 1,2,3중에 하나를 랜덤으로 뽑는다. ( 랜덤으로 햄버거를 주문한다.)
            {
                case CHE_BUR:
                    Enqueue(&que, CHE_TERM);
                    cheOrder++;
                    break;
                
                case BUL_BUR:
                    Enqueue(&que, BUL_TERM);
                    bulOrder++;
                    break;
                    
                case DUB_BUR:
                    Enqueue(&que, DUB_TERM);
                    dubOrder++;
                    break;
            }
        }
        
        
        if(makeProc <= 0 && !QIsEmpty(&que)) // 만약 햄버거를 만들고 있지 않는데 손님이 있다면
            makeProc = Dequeue(&que); // 대기열에 있는 햄버거 하나를 뺀다.
        
        // 대기열에서 뺀 손님의 햄버거를 초마다 작업하면서 1초씩 뺌. ( 햄버거를 만드는 시간을 재는 것, makeProc가 0이되면 햄버거 하나를 완성했다는 의미. )
        makeProc--;
    }
    // Queue의 Memory범람없이 for문이 끝난 것은 대기실(큐)의 자리가 부족하지 않다는 의미.
    
    // 주문 수량 출력
    printf("Simulation Report !\n");
    printf(" Cheese Burger : %d \n", cheOrder);
    printf(" Bulgogi Burger : %d \n", bulOrder);
    printf(" Double Burger : %d \n",dubOrder);
    printf(" waiting room size : %d\n", QUE_LEN);
    return 0;
}

