//
//  Point.c
//  C_practice
//
//  Created by 김병화 on 18/02/2020.
//  Copyright © 2020 김병화. All rights reserved.
//

#include "Point.h"

void SetPointPos(Point *ppos, int xpos, int ypos)
{
    ppos->xpos = xpos;
    ppos->ypos = ypos;
}

void ShowPointPos(Point *ppos)
{
    printf("[%d,  %d]\n", ppos->xpos, ppos->ypos);
}

int PointComp(Point *pos1, Point *pos2)
{
    if(pos1->xpos == pos2->ypos && pos1->ypos == pos2->ypos)
        return 0;
    else if(pos1->xpos == pos2->xpos)
        return 1;
    else if(pos2->ypos == pos2->ypos)
        return 2;
    else
        return -1;
}
