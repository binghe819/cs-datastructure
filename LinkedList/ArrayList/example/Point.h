//
//  Point.h
//  C_practice
//
//  Created by 김병화 on 18/02/2020.
//  Copyright © 2020 김병화. All rights reserved.
//

#ifndef Point_h
#define Point_h

#include <stdio.h>

typedef struct point
{
    int xpos;
    int ypos;
} Point;

// Point 변수의 xpos, ypos 값 설정
void SetPointPos(Point *ppos, int xpos, int ypos);

// Point 변수의 xpos, ypos 정보 출력
void ShowPointPos(Point *ppos);

// 두 Point의 변수 비교
int PointComp(Point *pos1, Point *pos2);




#endif /* Point_h */
