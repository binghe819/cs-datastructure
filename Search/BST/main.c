#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree2.h"
#include "BinarySearchTree.h"


int main(){
    
    BTreeNode * bstRoot;
    BTreeNode * sNode; // search Node
    
    BSTMakeAndInit(&bstRoot);
    
    BSTInsert(&bstRoot, 5); BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 1); BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 4); BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 3); BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 7);
    
    BSTShowAll(bstRoot);
    sNode = BSTRemove(&bstRoot, 3);
    free(sNode);
    
    printf("\n");
    BSTShowAll(bstRoot);
    sNode = BSTRemove(&bstRoot, 8);
    free(sNode);
    printf("\n");
    
    BSTShowAll(bstRoot);
    return 0;
}

