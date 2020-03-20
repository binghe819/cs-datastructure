#include <stdio.h>
#include "ALGraph.h"


// 무방향 그래프 구현
int main()
{
    ALGraph graph;
    GraphInit(&graph, 5);
    
    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, C, D);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, A);
    
    ShowGraphEdgeInfo(&graph);
    GraphDestory(&graph);
    return 0;
}

