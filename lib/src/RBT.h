#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct tagRBTNode
{
    struct tagRBTNode* Parent;
    struct tagRBTNode* Left;
    struct tagRBTNode* Right;

    enum {RED, BLACK} Color;

    ElementType Data;
} RBTNode;

void RBT_DestroyTree(RBTNode* Tree);
RBTNode* RBT_CreateNode(ElementType NewData);
void RBT_DestroyNode(RBTNode* Node);
RBTNode* RBT_SearchNode(RBTNode * Tree, ElementType Target);
void RBT_InsertNode(RBTNode** Tree, RBTNode* NewNode);

// extern RBTNode* Nil = RBT_CreateNode(0);