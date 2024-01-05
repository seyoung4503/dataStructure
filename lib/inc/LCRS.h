#ifndef LCRS_TREE_H
#define LCRS_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType; // typedef char ElementType;

typedef struct tagLCRSNode
{
    struct tagLCRSNode* LeftChild;
    struct tagLCRSNode* RightSibling;

    ElementType Data;
} LCRSNode;




LCRSNode* LCRS_CreateNode(ElementType NewData);
void LCRS_DestroyNode(LCRSNode* Node);
void LCRS_DestroyTree(LCRSNode* Root);
void LCRS_Add_ChildNode(LCRSNode* Parent, LCRSNode* Child);
void LCRS_PrintTree(LCRSNode* Node, int Depth);

#endif