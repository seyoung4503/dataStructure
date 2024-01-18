
#include "RBT.h"

RBTNode* Nil;

void RBT_DestroyTree(RBTNode* Tree)
{

}

RBTNode* RBT_CreateNode(ElementType NewData)
{
    RBTNode* NewNode = (RBTNode*)malloc(sizeof(RBTNode));
    NewNode->Parent = NULL;
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;
    NewNode->Color = BLACK;

    return NewNode;
}

void RBT_DestroyNode(RBTNode* Node)
{
    free(Node);
}

RBTNode* RBT_SearchNode(RBTNode * Tree, ElementType Target)
{
    if (Tree == Nil)
        return NULL;
    if (Tree->Data > Target)
        return RBT_SearchNode(Tree->Left, Target);
    else if (Tree->Data < Target)
        return RBT_SearchNode(Tree->Right, Target);
    else    
        return Tree;
}

void RBT_InsertNodeHelper(RBTNode** Tree, RBTNode* NewNode)
{
    if ((*Tree) == NULL)
        (*Tree) = NewNode;
    
    if ((*Tree)->Data < NewNode->Data)
    {
        if ((*Tree)->Right == Nil)
        {
            (*Tree)->Right = NewNode;
            NewNode->Parent = (*Tree);
        }
        else
            RBT_InsertNodeHelper(&(*Tree)->Right, NewNode);
    }
    else if ((*Tree)->Data > NewNode->Data)
    {
        if((*Tree)->Left == Nil)
        {
            (*Tree)->Left = NewNode;
            NewNode->Parent = (*Tree);
        }
        RBT_InsertNodeHelper(&(*Tree)->Left, NewNode);
    }
}

void RBT_InsertNode(RBTNode** Tree, RBTNode* NewNode)
{
    RBT_InsertNodeHelper(Tree, NewNode);
    NewNode->Color = RED;
    NewNode->Left = Nil;
    NewNode->Right = Nil;
    RBT_RebuildAfterInsert(Tree, NewNode);
}

